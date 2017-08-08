# Unreal Cpp -> BP Upgrade Guide

This guide is designed to help PlayFab customers upgrade from [UnrealCppSdk](https://github.com/PlayFab/UnrealCppSdk) to [UnrealBlueprintSDK](https://github.com/PlayFab/UnrealBlueprintSDK).

**Feature comparison**:

* Both SDKs are capable of making API calls purely from C++
  * The C++ SDK contained an ideal syntax for making API calls without the clutter of knowing about the existence of blueprints
  * The BP SDK requires an alternate syntax that is a bit more complex
* The BP SDK is tailored towards making API calls using the Blueprint editor
  * The C++ SDK contained no blueprint interaction
* The BP SDK can unpack complex/json-object results from ExecuteCloudScript
  * The C++ SDK could only deserialize primitives such as strings
* The C++ SDK contained integrated Unreal unit tests which were executed from the Unreal testing interface
  * The BP SDK example project contains a special test entity which runs in a test-scene, and executes the tests, and displays the result to the game screen
  * The [BP tests](https://github.com/PlayFab/UnrealBlueprintSDK/blob/master/PlayFabClientSDK/ExampleProject/Plugins/PlayFab/Source/PlayFab/Private/PfTestActor.cpp) were easier to update and was closer to actual game usage
  * They also serve as a great example of how to implement a bunch of API calls

**Example Login Functions**:

Please note, the used namespaces are different between the two examples.  Click the links to the original code for full context.

**NEW**: Unreal Blueuprint SDK (C++ implementation) from [here](https://github.com/PlayFab/UnrealBlueprintSDK/blob/master/PlayFabClientSDK/ExampleProject/Plugins/PlayFab/Source/PlayFab/Private/PfTestActor.cpp#L297)

	void LoginWithBp()
	{
		// Create Request
		FClientLoginWithCustomIDRequest request;
		request.CustomId = "GettingStartedGuide";
		request.CreateAccount = true;
		request.InfoRequestParameters = nullptr;
		// Set up Callbacks
		UPlayFabClientAPI::FDelegateOnSuccessLoginWithCustomID onSuccess; onSuccess.BindUFunction(this, "OnLoginOrRegister");
		UPlayFabClientAPI::FDelegateOnFailurePlayFabError onError; onError.BindUFunction(this, "OnSharedError");
		// Make API Call
		UPlayFabClientAPI* callObj = UPlayFabClientAPI::LoginWithCustomID(request, onSuccess, onError);
		// Extra memory management step for UE BP
		managedObjects.Add(callObj);
		// Extra activation step for UE BP
		callObj->Activate();
	}
	void APfTestActor::OnLoginOrRegister(FClientLoginResult result, UObject* customData)
	{
		playFabId = result.PlayFabId;
	}

**OLD**: Unreal Cpp SDK (C++ implementation) from [here](https://github.com/PlayFab/UnrealCppSdk/blob/1d10d5c639831fed046f10dad1f9cc485cb4ee8e/ExampleProject/Source/ExampleProject/PlayFabApiTests.cpp#L68)

	void LoginWithCpp()
	{
		// Create Request
		PlayFab::ClientModels::FLoginWithCustomIDRequest request;
		request.CustomId = "GettingStartedGuide";
		request.CreateAccount = true;
		// Make API Call
		clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
		clientAPI->LoginWithCustomID(request
		// Set up Callbacks
			, PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateRaw(this, &PlayFabApiTest_LoginWithCustomID::OnSuccess)
			, PlayFab::FPlayFabErrorDelegate::CreateRaw(this, &PlayFabApiTest_LoginWithCustomID::OnError)
		);
	}
	void PlayFabApiTest_LoginWithCustomID::OnSuccess(const PlayFab::ClientModels::FLoginResult& result) const
	{
		playFabId = result.PlayFabId;
	}

**Create Request**: This step is identical for both SDKs. The request object has the same structure in both SDKs, and contains all the same information in the same format. It is generally safer to explicitly set sub-object pointers to null, which was not required in the Cpp SDK.

**Set up Callbacks**: The callbacks are probably the biggest overall change. Every object that makes API calls must become UObjects (with an unbroken U-chain), and all your callbacks must become [UFunctions](https://wiki.unrealengine.com/UFUNCTION) (if they weren't already), and you use [BindUFunction](https://docs.unrealengine.com/latest/INT/API/Runtime/Core/UObject/TScriptDelegate/BindUFunction/index.html) instead of [CreateRaw](https://docs.unrealengine.com/latest/INT/API/Runtime/Core/Delegates/TBaseDelegate/CreateRaw/1/index.html)

**Make API Call**: The Cpp SDK accessed each API via an Unreal module:

  clientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
  clientAPI->LoginWithCustomID(...);
  
where the BP SDK called with global static functions:

  UPlayFabClientAPI::LoginWithCustomID(...);

A simple regex should solve this one.

**Callback Implementation**: As mentioned above, your callback functions must be UFunctions, but otherwise they should work pretty similarly.

**Memory Management**: The API calls create a blueprint UObject which is part of the Unreal memory management system.  If it is not referenced by another UObject, it will immediately garbage collect and your program will experience undesired behavior (api won't complete, and/or the program will crash).  You will need to ensure that you reference this object somewhere so that it stays active.  The example keeps a list of all nodes called under the test-entity that causes the tests to run.

We hope that this step will go away in the next release, it's kindof silly to force you to do this.  This occurs because it's all driven from blueprints and therefore must be UObjects.

**Extra activation step for UE BP**: Because these are blueprints, and you're invoking them from C++, you will need to manually take the returned callObj, and activate it.  There is no workaround for this, it's just an extra line of code that you will always need.  Unlike the memory management problem, we can't do much about this without doubling the size of the plugin, so this will not change.
