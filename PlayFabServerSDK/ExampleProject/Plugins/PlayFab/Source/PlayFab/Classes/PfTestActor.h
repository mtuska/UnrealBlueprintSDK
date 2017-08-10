// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "PlayFabServerModels.h"
#include "PlayFabServerApi.h"

#include "PfTestActor.generated.h"

UENUM(BlueprintType)
enum class PlayFabApiTestActiveState : uint8
{
    PENDING UMETA(DisplayName = "PENDING"), // Not started
    ACTIVE UMETA(DisplayName = "ACTIVE"), // Currently testing
    READY UMETA(DisplayName = "READY"), // An answer is sent by the http thread, but the main thread hasn't finalized the test yet
    COMPLETE UMETA(DisplayName = "COMPLETE"), // Test is finalized and recorded
    ABORTED UMETA(DisplayName = "ABORTED"), // todo
};

UENUM(BlueprintType)
enum class PlayFabApiTestFinishState : uint8
{
    PASSED UMETA(DisplayName = "PASSED"),
    FAILED UMETA(DisplayName = "FAILED"),
    SKIPPED UMETA(DisplayName = "SKIPPED"),
    TIMEDOUT UMETA(DisplayName = "TIMEDOUT"),
};

UCLASS(Blueprintable, BlueprintType)
class UPfTestContext : public UObject
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_DELEGATE_OneParam(FApiTestCase, UPfTestContext*, error);

    UPROPERTY()
        FString testName;
    UPROPERTY()
        PlayFabApiTestActiveState activeState;
    UPROPERTY()
        PlayFabApiTestFinishState finishState;
    UPROPERTY()
        FString testResultMsg;
    UPROPERTY()
        FApiTestCase testFunc;
    UPROPERTY()
        FDateTime startTime;
    UPROPERTY()
        FDateTime endTime;

    UFUNCTION()
        void Setup(FString name, FApiTestCase func)
    {
        testName = name;
        activeState = PlayFabApiTestActiveState::PENDING;
        finishState = PlayFabApiTestFinishState::TIMEDOUT;
        testResultMsg = "";
        testFunc = func;
        startTime = 0;
        endTime = 0;
    };

    UFUNCTION()
        FString GenerateSummary(FDateTime now)
    {
        FDateTime tempEndTime = (activeState == PlayFabApiTestActiveState::COMPLETE) ? endTime : now;
        FDateTime tempStartTime = (startTime != 0) ? startTime : now;

        FString temp;
        temp = FString::FromInt((tempEndTime - tempStartTime).GetTotalMilliseconds());
        while (temp.Len() < 12)
            temp = " " + temp;
        temp += " ms, ";
        switch (finishState)
        {
        case PlayFabApiTestFinishState::PASSED: temp += "pass: "; break;
        case PlayFabApiTestFinishState::FAILED: temp += "FAILED: "; break;
        case PlayFabApiTestFinishState::SKIPPED: temp += "SKIPPED: "; break;
        case PlayFabApiTestFinishState::TIMEDOUT: temp += "TIMED OUT: "; break;
        }
        temp += testName;
        if (testResultMsg.Len() > 0)
        {
            temp += " - ";
            temp += testResultMsg;
        }
        return temp;
    }
};

UCLASS()
class APfTestActor : public AActor
{
    GENERATED_BODY()

public:
    ///////////////////// Actor stuff /////////////////////
    APfTestActor(); // Sets default values for this actor's properties
    virtual void BeginPlay() override; // Called when the game starts or when spawned
    virtual void Tick(float DeltaSeconds) override; // Called every frame

    ///////////////////// API-test stuff /////////////////////

    /* The active test summary */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PfTestSummary)
        FString _outputSummary;
    // A bunch of constants: load these from testTitleData.json
    UPROPERTY()
        FString TEST_TITLE_DATA_LOC = "testTitleData.json";
    UPROPERTY()
        FString userEmail;
    UPROPERTY()
        FString characterName;
    UPROPERTY()
        FString TEST_DATA_KEY = "testCounter";
    UPROPERTY()
        FString TEST_STAT_NAME = "str";
    UPROPERTY()
        FString playFabId;
    UPROPERTY()
        FDateTime testMessageTime;
    UPROPERTY()
        TArray<UPfTestContext*> testContexts;
    int testMessageInt;

    UFUNCTION()
        void InitializeTestSuite();
    UFUNCTION()
        void AppendTest(const FString& testFuncName);
    UFUNCTION()
        bool TickTestSuite();
    UFUNCTION()
        FString GenerateSummary();

    UFUNCTION()
        bool ClassSetup();
    // Start a test, and block until the threaded response arrives
    UFUNCTION()
        void StartTest(UPfTestContext* testContext);
    UFUNCTION()
        void TickTest(UPfTestContext* testContext);
    // This should be called in the api-responses, which are threaded.  This will allow TickTest to finalize the test
    UFUNCTION()
        void EndTest(UPfTestContext* testContext, PlayFabApiTestFinishState finishState, FString resultMsg);

    UFUNCTION()
        void OnSharedError(FPlayFabError error, UObject* customData);

    /// <summary>
    /// SERVER API
    /// Test that server apis can be called successfully
    /// Parameter types tested: none
    /// </summary>
    UFUNCTION()
        void ServerTitleData(UPfTestContext* testContext);
    UFUNCTION()
        void OnServerTitleData(FServerGetTitleDataResult result, UObject* customData);

};
