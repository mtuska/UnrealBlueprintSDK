// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayFabPrivatePCH.h"
#include "PfTestActor.h"
#include "PlayFabEnums.h"

const int SUMMARY_INIT_BUFFER_SIZE = 10000;
const int TEST_TIMEOUT_SECONDS = 10;

// Sets default values
APfTestActor::APfTestActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APfTestActor::BeginPlay()
{
    Super::BeginPlay();
    InitializeTestSuite();
}

// Called every frame
void APfTestActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    TickTestSuite();
    _outputSummary = GenerateSummary();
}

/////////////////////////////////////// The actual testing framework ///////////////////////////////////////
void APfTestActor::InitializeTestSuite()
{
    bool setupSuccessful = ClassSetup();

    // Reset testContexts if this has already been run (The results are kept for later viewing)
    testContexts.Empty();

    if (setupSuccessful)
    {

        AppendTest("ServerTitleData");

    }
}

void APfTestActor::AppendTest(const FString& testFuncName)
{
    UPfTestContext::FApiTestCase eachTestDelegate;
    eachTestDelegate.BindUFunction(this, *testFuncName);
    if (eachTestDelegate.IsBound())
    {
        UPfTestContext* eachTestContext = NewObject<UPfTestContext>(this);
        eachTestContext->Setup(testFuncName, eachTestDelegate);
        testContexts.Add(eachTestContext);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("%s: %s"), *testFuncName, TEXT("Critical Failure: Cannot bind test UFUNCTION."));
    }
}

bool APfTestActor::TickTestSuite()
{
    if (IPlayFab::Get().GetPendingCallCount() > 0)
        return false; // The active test won't advance until all outstanding calls return

    int unfinishedTests = 0;
    UPfTestContext* nextTest = nullptr;
    for (int i = 0; i < testContexts.Num(); i++)
    {
        auto eachState = testContexts[i]->activeState;

        if (eachState != PlayFabApiTestActiveState::COMPLETE && eachState != PlayFabApiTestActiveState::ABORTED)
            unfinishedTests++;

        if (eachState == PlayFabApiTestActiveState::ACTIVE || eachState == PlayFabApiTestActiveState::READY) // Find the active test, and prioritize it
            nextTest = testContexts[i];
        else if (eachState == PlayFabApiTestActiveState::PENDING && nextTest == nullptr) // Or find a test to start
            nextTest = testContexts[i];
    }

    if (nextTest != nullptr && !nextTest->IsValidLowLevel())
    {
        UE_LOG(LogTemp, Error, TEXT("%s"), TEXT("Critical Failure: Test context has become invalid."));
        return true;
    }

    if (nextTest != nullptr && nextTest->activeState == PlayFabApiTestActiveState::PENDING)
        StartTest(nextTest);
    else if (nextTest != nullptr)
        TickTest(nextTest);

    bool result = unfinishedTests == 0; // Return whether tests are complete
    return result;
}

FString APfTestActor::GenerateSummary()
{
    _outputSummary.Empty(SUMMARY_INIT_BUFFER_SIZE); // Set the capacity to handle everything we're about to put into it

    FDateTime now = FDateTime::UtcNow();
    int numPassed = 0;
    int numFailed = 0;
    for (int i = 0; i < testContexts.Num(); i++)
    {
        if (_outputSummary.Len() != 0)
            _outputSummary += '\n';
        _outputSummary += testContexts[i]->GenerateSummary(now);
        if (testContexts[i]->finishState == PlayFabApiTestFinishState::PASSED) numPassed++;
        else if (testContexts[i]->finishState == PlayFabApiTestFinishState::FAILED) numFailed++;
    }

    FString testCountLine = "\nTotal tests: ";
    testCountLine += FString::FromInt(testContexts.Num());
    testCountLine += ", Passed: ";
    testCountLine += FString::FromInt(numPassed);
    testCountLine += ", Failed: ";
    testCountLine += FString::FromInt(numFailed);

    _outputSummary += testCountLine;
    return _outputSummary;
}

bool APfTestActor::ClassSetup()
{
    // README:
    // modify the TEST_TITLE_DATA_LOC to a location of a testTitleData.json file
    // The format of this file is described in the sdk readme
    //  - OR -
    // Comment the "return false;" below, and
    //   Fill in all the variables under: POPULATE THIS SECTION WITH REAL INFORMATION

    IPlayFab* playFabSettings = &(IPlayFab::Get());

    playFabSettings->AdvertisingIdType = TEXT("");
    playFabSettings->AdvertisingIdValue = TEXT("");

    // Prefer to load path from environment variable, if present
    char* envPath = nullptr;
    size_t envPathStrLen;
    errno_t err = _dupenv_s(&envPath, &envPathStrLen, "PF_TEST_TITLE_DATA_JSON");
    if (err == 0 && envPath != nullptr)
        TEST_TITLE_DATA_LOC = FString(ANSI_TO_TCHAR(envPath));
    free(envPath); // It's OK to call free with NULL

    FString titleDataJson;
    if (FFileHelper::LoadFileToString(titleDataJson, *TEST_TITLE_DATA_LOC))
    {
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(titleDataJson);
        FJsonSerializer::Deserialize(Reader, JsonObject);
        playFabSettings->setGameTitleId(JsonObject->GetStringField(TEXT("titleId")));
        playFabSettings->setApiSecretKey(JsonObject->GetStringField(TEXT("developerSecretKey")));
        userEmail = JsonObject->GetStringField(TEXT("userEmail"));
    }
    else
    {
        // Add your real test data here and remove this return if you want to skip testTitleData
        return false;

        // Populate this section with real information, if you're not using the testTitleData.json file (or are using a device)
        playFabSettings->setGameTitleId(TEXT("")); // Without a titleId, your game will do terrible things (usually crash)
        playFabSettings->setApiSecretKey(TEXT("")); // Non-client api calls will all crash without a secret key
        userEmail = "yourEmail"; // This is the email for the user
    }

    // Verify all the inputs won't cause crashes in the tests
    return playFabSettings->getGameTitleId().Len() > 0
        && (userEmail.Len() > 0);
}

// Start a test, and block until the threaded response arrives
void APfTestActor::StartTest(UPfTestContext* testContext)
{
    UE_LOG(LogTemp, Log, TEXT("Starting Test: %s"), *(testContext->testName));
    testContext->activeState = PlayFabApiTestActiveState::ACTIVE;
    testContext->startTime = FDateTime::UtcNow();
    testContext->testFunc.Execute(testContext);
    // Async tests can't resolve this tick, so just return
}

void APfTestActor::TickTest(UPfTestContext* testContext)
{
    FDateTime now = FDateTime::UtcNow();
    if (testContext->activeState != PlayFabApiTestActiveState::READY // Not finished
        && (now - testContext->startTime) < FTimespan::FromSeconds(TEST_TIMEOUT_SECONDS)) // Not timed out
        return;

    testContext->endTime = now;
    testContext->activeState = PlayFabApiTestActiveState::COMPLETE;
}

// This should be called in the api-responses, which are threaded.  This will allow TickTest to finalize the test
void APfTestActor::EndTest(UPfTestContext* testContext, PlayFabApiTestFinishState finishState, FString resultMsg)
{
    testContext->testResultMsg = resultMsg;
    testContext->finishState = finishState;
    testContext->activeState = PlayFabApiTestActiveState::READY;
}

void APfTestActor::OnSharedError(FPlayFabError error, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    EndTest(testContext, PlayFabApiTestFinishState::FAILED, "Unexpected error: " + error.ErrorMessage + "\n" + error.ErrorDetails);
}

/// <summary>
/// SERVER API
/// Test that leaderboard results can be requested
/// Parameter types tested: List of contained-classes
/// </summary>
void APfTestActor::ServerTitleData(UPfTestContext* testContext)
{
    testMessageInt = 0;
    FServerGetTitleDataRequest request;
    UPlayFabServerAPI::FDelegateOnSuccessGetTitleData onSuccess; onSuccess.BindUFunction(this, "OnServerTitleData");
    UPlayFabServerAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
    UPlayFabServerAPI* callObj = UPlayFabServerAPI::GetTitleData(request, onSuccess, onError, testContext);
    callObj->Activate();
}
void APfTestActor::OnServerTitleData(FServerGetTitleDataResult result, UObject* customData)
{
    UPfTestContext* testContext = dynamic_cast<UPfTestContext*>(customData);
    // There is no guarantee about content in titleData, so as long as this request succeeds, test passes
    EndTest(testContext, PlayFabApiTestFinishState::PASSED, "");
}

