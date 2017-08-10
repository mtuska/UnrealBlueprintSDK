//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Server
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabEnums.h"
#include "PlayFabServerAPI.h"

UPlayFabServerAPI::UPlayFabServerAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UPlayFabServerAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabServerAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabServerAPI::PercentEncode(const FString& Text)
{
    FString OutText = Text;

    OutText = OutText.Replace(TEXT("!"), TEXT("%21"));
    OutText = OutText.Replace(TEXT("\""), TEXT("%22"));
    OutText = OutText.Replace(TEXT("#"), TEXT("%23"));
    OutText = OutText.Replace(TEXT("$"), TEXT("%24"));
    //OutText = OutText.Replace(TEXT("&"), TEXT("%26"));
    OutText = OutText.Replace(TEXT("'"), TEXT("%27"));
    OutText = OutText.Replace(TEXT("("), TEXT("%28"));
    OutText = OutText.Replace(TEXT(")"), TEXT("%29"));
    OutText = OutText.Replace(TEXT("*"), TEXT("%2A"));
    OutText = OutText.Replace(TEXT("+"), TEXT("%2B"));
    OutText = OutText.Replace(TEXT(","), TEXT("%2C"));
    //OutText = OutText.Replace(TEXT("/"), TEXT("%2F"));
    OutText = OutText.Replace(TEXT(":"), TEXT("%3A"));
    OutText = OutText.Replace(TEXT(";"), TEXT("%3B"));
    OutText = OutText.Replace(TEXT("="), TEXT("%3D"));
    //OutText = OutText.Replace(TEXT("?"), TEXT("%3F"));
    OutText = OutText.Replace(TEXT("@"), TEXT("%40"));
    OutText = OutText.Replace(TEXT("["), TEXT("%5B"));
    OutText = OutText.Replace(TEXT("]"), TEXT("%5D"));
    OutText = OutText.Replace(TEXT("{"), TEXT("%7B"));
    OutText = OutText.Replace(TEXT("}"), TEXT("%7D"));

    return OutText;
}

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////
/** Validated a client's session ticket, and if successful, returns details for that user */
UPlayFabServerAPI* UPlayFabServerAPI::AuthenticateSessionTicket(FServerAuthenticateSessionTicketRequest request,
    FDelegateOnSuccessAuthenticateSessionTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAuthenticateSessionTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAuthenticateSessionTicket);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AuthenticateSessionTicket";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SessionTicket.IsEmpty() || request.SessionTicket == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SessionTicket"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SessionTicket"), request.SessionTicket);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAuthenticateSessionTicket(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAuthenticateSessionTicket.IsBound())
    {
        FServerAuthenticateSessionTicketResult result = UPlayFabServerModelDecoder::decodeAuthenticateSessionTicketResultResponse(response.responseData);
        OnSuccessAuthenticateSessionTicket.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets the player's secret if it is not already set. Player secrets are used to sign API requests. To reset a player's secret use the Admin or Server API method SetPlayerSecret. */
UPlayFabServerAPI* UPlayFabServerAPI::SetPlayerSecret(FServerSetPlayerSecretRequest request,
    FDelegateOnSuccessSetPlayerSecret onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetPlayerSecret = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetPlayerSecret);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetPlayerSecret";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayerSecret.IsEmpty() || request.PlayerSecret == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayerSecret"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayerSecret"), request.PlayerSecret);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetPlayerSecret(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetPlayerSecret.IsBound())
    {
        FServerSetPlayerSecretResult result = UPlayFabServerModelDecoder::decodeSetPlayerSecretResultResponse(response.responseData);
        OnSuccessSetPlayerSecret.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Bans users by PlayFab ID with optional IP address, or MAC address for the provided game. */
UPlayFabServerAPI* UPlayFabServerAPI::BanUsers(FServerBanUsersRequest request,
    FDelegateOnSuccessBanUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessBanUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperBanUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/BanUsers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Bans.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Bans"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Bans"), request.Bans);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperBanUsers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessBanUsers.IsBound())
    {
        FServerBanUsersResult result = UPlayFabServerModelDecoder::decodeBanUsersResultResponse(response.responseData);
        OnSuccessBanUsers.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the player's profile */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerProfile(FServerGetPlayerProfileRequest request,
    FDelegateOnSuccessGetPlayerProfile onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerProfile = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerProfile);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerProfile";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.ProfileConstraints != nullptr) OutRestJsonObj->SetObjectField(TEXT("ProfileConstraints"), request.ProfileConstraints);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerProfile(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayerProfile.IsBound())
    {
        FServerGetPlayerProfileResult result = UPlayFabServerModelDecoder::decodeGetPlayerProfileResultResponse(response.responseData);
        OnSuccessGetPlayerProfile.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayFabIDsFromFacebookIDs(FServerGetPlayFabIDsFromFacebookIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromFacebookIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromFacebookIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayFabIDsFromFacebookIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayFabIDsFromFacebookIDs";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.FacebookIDs.IsEmpty() || request.FacebookIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FacebookIDs"));
    } else {
        TArray<FString> FacebookIDsArray;
        FString(request.FacebookIDs).ParseIntoArray(FacebookIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("FacebookIDs"), FacebookIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayFabIDsFromFacebookIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayFabIDsFromFacebookIDs.IsBound())
    {
        FServerGetPlayFabIDsFromFacebookIDsResult result = UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromFacebookIDsResultResponse(response.responseData);
        OnSuccessGetPlayFabIDsFromFacebookIDs.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers  are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayFabIDsFromSteamIDs(FServerGetPlayFabIDsFromSteamIDsRequest request,
    FDelegateOnSuccessGetPlayFabIDsFromSteamIDs onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayFabIDsFromSteamIDs = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayFabIDsFromSteamIDs);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayFabIDsFromSteamIDs";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.SteamStringIDs.IsEmpty() || request.SteamStringIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SteamStringIDs"));
    } else {
        TArray<FString> SteamStringIDsArray;
        FString(request.SteamStringIDs).ParseIntoArray(SteamStringIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("SteamStringIDs"), SteamStringIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayFabIDsFromSteamIDs(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayFabIDsFromSteamIDs.IsBound())
    {
        FServerGetPlayFabIDsFromSteamIDsResult result = UPlayFabServerModelDecoder::decodeGetPlayFabIDsFromSteamIDsResultResponse(response.responseData);
        OnSuccessGetPlayFabIDsFromSteamIDs.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the relevant details for a specified user */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserAccountInfo(FServerGetUserAccountInfoRequest request,
    FDelegateOnSuccessGetUserAccountInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserAccountInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserAccountInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserAccountInfo";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserAccountInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserAccountInfo.IsBound())
    {
        FServerGetUserAccountInfoResult result = UPlayFabServerModelDecoder::decodeGetUserAccountInfoResultResponse(response.responseData);
        OnSuccessGetUserAccountInfo.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Gets all bans for a user. */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserBans(FServerGetUserBansRequest request,
    FDelegateOnSuccessGetUserBans onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserBans = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserBans);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserBans";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserBans(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserBans.IsBound())
    {
        FServerGetUserBansResult result = UPlayFabServerModelDecoder::decodeGetUserBansResultResponse(response.responseData);
        OnSuccessGetUserBans.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Revoke all active bans for a user. */
UPlayFabServerAPI* UPlayFabServerAPI::RevokeAllBansForUser(FServerRevokeAllBansForUserRequest request,
    FDelegateOnSuccessRevokeAllBansForUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRevokeAllBansForUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRevokeAllBansForUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RevokeAllBansForUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRevokeAllBansForUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRevokeAllBansForUser.IsBound())
    {
        FServerRevokeAllBansForUserResult result = UPlayFabServerModelDecoder::decodeRevokeAllBansForUserResultResponse(response.responseData);
        OnSuccessRevokeAllBansForUser.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Revoke all active bans specified with BanId. */
UPlayFabServerAPI* UPlayFabServerAPI::RevokeBans(FServerRevokeBansRequest request,
    FDelegateOnSuccessRevokeBans onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRevokeBans = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRevokeBans);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RevokeBans";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.BanIds.IsEmpty() || request.BanIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BanIds"));
    } else {
        TArray<FString> BanIdsArray;
        FString(request.BanIds).ParseIntoArray(BanIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("BanIds"), BanIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRevokeBans(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRevokeBans.IsBound())
    {
        FServerRevokeBansResult result = UPlayFabServerModelDecoder::decodeRevokeBansResultResponse(response.responseData);
        OnSuccessRevokeBans.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sends an iOS/Android Push Notification to a specific user, if that user's device has been configured for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be notified. */
UPlayFabServerAPI* UPlayFabServerAPI::SendPushNotification(FServerSendPushNotificationRequest request,
    FDelegateOnSuccessSendPushNotification onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSendPushNotification = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSendPushNotification);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SendPushNotification";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Recipient.IsEmpty() || request.Recipient == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Recipient"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Recipient"), request.Recipient);
    }
    if (request.Message.IsEmpty() || request.Message == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Message"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Message"), request.Message);
    }
    if (request.Package != nullptr) OutRestJsonObj->SetObjectField(TEXT("Package"), request.Package);
    if (request.Subject.IsEmpty() || request.Subject == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Subject"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Subject"), request.Subject);
    }
    // Check to see if string is empty
    if (request.TargetPlatforms.IsEmpty() || request.TargetPlatforms == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TargetPlatforms"));
    } else {
        TArray<FString> TargetPlatformsArray;
        FString(request.TargetPlatforms).ParseIntoArray(TargetPlatformsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("TargetPlatforms"), TargetPlatformsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSendPushNotification(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSendPushNotification.IsBound())
    {
        FServerSendPushNotificationResult result = UPlayFabServerModelDecoder::decodeSendPushNotificationResultResponse(response.responseData);
        OnSuccessSendPushNotification.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Update the avatar URL of the specified player */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateAvatarUrl(FServerUpdateAvatarUrlRequest request,
    FDelegateOnSuccessUpdateAvatarUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateAvatarUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateAvatarUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateAvatarUrl";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.ImageUrl.IsEmpty() || request.ImageUrl == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ImageUrl"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ImageUrl"), request.ImageUrl);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateAvatarUrl(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateAvatarUrl.IsBound())
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        OnSuccessUpdateAvatarUrl.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates information of a list of existing bans specified with Ban Ids. */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateBans(FServerUpdateBansRequest request,
    FDelegateOnSuccessUpdateBans onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateBans = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateBans);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateBans";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Bans.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Bans"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Bans"), request.Bans);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateBans(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateBans.IsBound())
    {
        FServerUpdateBansResult result = UPlayFabServerModelDecoder::decodeUpdateBansResultResponse(response.responseData);
        OnSuccessUpdateBans.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteUsers(FServerDeleteUsersRequest request,
    FDelegateOnSuccessDeleteUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperDeleteUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/DeleteUsers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    } else {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }
    OutRestJsonObj->SetStringField(TEXT("TitleId"), IPlayFab::Get().getGameTitleId());

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperDeleteUsers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteUsers.IsBound())
    {
        FServerDeleteUsersResult result = UPlayFabServerModelDecoder::decodeDeleteUsersResultResponse(response.responseData);
        OnSuccessDeleteUsers.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a list of ranked friends of the given player for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabServerAPI* UPlayFabServerAPI::GetFriendLeaderboard(FServerGetFriendLeaderboardRequest request,
    FDelegateOnSuccessGetFriendLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFriendLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetFriendLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetFriendLeaderboard";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("UseSpecificVersion"), request.UseSpecificVersion);
    if (request.ProfileConstraints != nullptr) OutRestJsonObj->SetObjectField(TEXT("ProfileConstraints"), request.ProfileConstraints);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetFriendLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetFriendLeaderboard.IsBound())
    {
        FServerGetLeaderboardResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardResultResponse(response.responseData);
        OnSuccessGetFriendLeaderboard.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a list of ranked users for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboard(FServerGetLeaderboardRequest request,
    FDelegateOnSuccessGetLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboard";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    if (request.ProfileConstraints != nullptr) OutRestJsonObj->SetObjectField(TEXT("ProfileConstraints"), request.ProfileConstraints);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("UseSpecificVersion"), request.UseSpecificVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboard.IsBound())
    {
        FServerGetLeaderboardResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardResultResponse(response.responseData);
        OnSuccessGetLeaderboard.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardAroundUser(FServerGetLeaderboardAroundUserRequest request,
    FDelegateOnSuccessGetLeaderboardAroundUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboardAroundUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboardAroundUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);
    if (request.ProfileConstraints != nullptr) OutRestJsonObj->SetObjectField(TEXT("ProfileConstraints"), request.ProfileConstraints);
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetBoolField(TEXT("UseSpecificVersion"), request.UseSpecificVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboardAroundUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboardAroundUser.IsBound())
    {
        FServerGetLeaderboardAroundUserResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardAroundUserResultResponse(response.responseData);
        OnSuccessGetLeaderboardAroundUser.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Returns whatever info is requested in the response for the user. Note that PII (like email address, facebook id)             may be returned. All parameters default to false. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerCombinedInfo(FServerGetPlayerCombinedInfoRequest request,
    FDelegateOnSuccessGetPlayerCombinedInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerCombinedInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerCombinedInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerCombinedInfo";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.InfoRequestParameters != nullptr) OutRestJsonObj->SetObjectField(TEXT("InfoRequestParameters"), request.InfoRequestParameters);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerCombinedInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayerCombinedInfo.IsBound())
    {
        FServerGetPlayerCombinedInfoResult result = UPlayFabServerModelDecoder::decodeGetPlayerCombinedInfoResultResponse(response.responseData);
        OnSuccessGetPlayerCombinedInfo.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the current version and values for the indicated statistics, for the local player. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerStatistics(FServerGetPlayerStatisticsRequest request,
    FDelegateOnSuccessGetPlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    // Check to see if string is empty
    if (request.StatisticNames.IsEmpty() || request.StatisticNames == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticNames"));
    } else {
        TArray<FString> StatisticNamesArray;
        FString(request.StatisticNames).ParseIntoArray(StatisticNamesArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("StatisticNames"), StatisticNamesArray);
    }
    if (request.StatisticNameVersions.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticNameVersions"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("StatisticNameVersions"), request.StatisticNameVersions);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayerStatistics.IsBound())
    {
        FServerGetPlayerStatisticsResult result = UPlayFabServerModelDecoder::decodeGetPlayerStatisticsResultResponse(response.responseData);
        OnSuccessGetPlayerStatistics.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the information on the available versions of the specified statistic. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerStatisticVersions(FServerGetPlayerStatisticVersionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerStatisticVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerStatisticVersions";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayerStatisticVersions.IsBound())
    {
        FServerGetPlayerStatisticVersionsResult result = UPlayFabServerModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(response.responseData);
        OnSuccessGetPlayerStatisticVersions.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserData.IsBound())
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        OnSuccessGetUserData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserInternalData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserInternalData.IsBound())
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        OnSuccessGetUserInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserPublisherData.IsBound())
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        OnSuccessGetUserPublisherData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherInternalData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserPublisherInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserPublisherInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserPublisherInternalData.IsBound())
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        OnSuccessGetUserPublisherInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserPublisherReadOnlyData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserPublisherReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserPublisherReadOnlyData.IsBound())
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        OnSuccessGetUserPublisherReadOnlyData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserReadOnlyData(FServerGetUserDataRequest request,
    FDelegateOnSuccessGetUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserReadOnlyData.IsBound())
    {
        FServerGetUserDataResult result = UPlayFabServerModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        OnSuccessGetUserReadOnlyData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the values of the specified title-specific statistics for the user */
UPlayFabServerAPI* UPlayFabServerAPI::UpdatePlayerStatistics(FServerUpdatePlayerStatisticsRequest request,
    FDelegateOnSuccessUpdatePlayerStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdatePlayerStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdatePlayerStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdatePlayerStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Statistics.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Statistics"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Statistics"), request.Statistics);
    }
    OutRestJsonObj->SetBoolField(TEXT("ForceUpdate"), request.ForceUpdate);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdatePlayerStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdatePlayerStatistics.IsBound())
    {
        FServerUpdatePlayerStatisticsResult result = UPlayFabServerModelDecoder::decodeUpdatePlayerStatisticsResultResponse(response.responseData);
        OnSuccessUpdatePlayerStatistics.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateUserData.IsBound())
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        OnSuccessUpdateUserData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserInternalData(FServerUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateUserInternalData.IsBound())
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        OnSuccessUpdateUserInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateUserPublisherData.IsBound())
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        OnSuccessUpdateUserPublisherData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherInternalData(FServerUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserPublisherInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserPublisherInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateUserPublisherInternalData.IsBound())
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        OnSuccessUpdateUserPublisherInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the publisher-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserPublisherReadOnlyData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserPublisherReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateUserPublisherReadOnlyData.IsBound())
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        OnSuccessUpdateUserPublisherReadOnlyData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the title-specific custom data for the user which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserReadOnlyData(FServerUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateUserReadOnlyData.IsBound())
    {
        FServerUpdateUserDataResult result = UPlayFabServerModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        OnSuccessUpdateUserReadOnlyData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabServerAPI* UPlayFabServerAPI::GetCatalogItems(FServerGetCatalogItemsRequest request,
    FDelegateOnSuccessGetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCatalogItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCatalogItems";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCatalogItems.IsBound())
    {
        FServerGetCatalogItemsResult result = UPlayFabServerModelDecoder::decodeGetCatalogItemsResultResponse(response.responseData);
        OnSuccessGetCatalogItems.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the key-value store of custom publisher settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetPublisherData(FServerGetPublisherDataRequest request,
    FDelegateOnSuccessGetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPublisherData.IsBound())
    {
        FServerGetPublisherDataResult result = UPlayFabServerModelDecoder::decodeGetPublisherDataResultResponse(response.responseData);
        OnSuccessGetPublisherData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the current server time */
UPlayFabServerAPI* UPlayFabServerAPI::GetTime(FServerGetTimeRequest request,
    FDelegateOnSuccessGetTime onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTime = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetTime);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetTime";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetTime(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTime.IsBound())
    {
        FServerGetTimeResult result = UPlayFabServerModelDecoder::decodeGetTimeResultResponse(response.responseData);
        OnSuccessGetTime.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleData(FServerGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetTitleData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTitleData.IsBound())
    {
        FServerGetTitleDataResult result = UPlayFabServerModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        OnSuccessGetTitleData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the key-value store of custom internal title settings */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleInternalData(FServerGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetTitleInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetTitleInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTitleInternalData.IsBound())
    {
        FServerGetTitleDataResult result = UPlayFabServerModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        OnSuccessGetTitleInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the title news feed, as configured in the developer portal */
UPlayFabServerAPI* UPlayFabServerAPI::GetTitleNews(FServerGetTitleNewsRequest request,
    FDelegateOnSuccessGetTitleNews onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleNews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetTitleNews);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetTitleNews";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Count"), request.Count);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetTitleNews(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetTitleNews.IsBound())
    {
        FServerGetTitleNewsResult result = UPlayFabServerModelDecoder::decodeGetTitleNewsResultResponse(response.responseData);
        OnSuccessGetTitleNews.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the key-value store of custom publisher settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetPublisherData(FServerSetPublisherDataRequest request,
    FDelegateOnSuccessSetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetPublisherData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }
    if (request.Value.IsEmpty() || request.Value == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Value"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Value"), request.Value);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetPublisherData.IsBound())
    {
        FServerSetPublisherDataResult result = UPlayFabServerModelDecoder::decodeSetPublisherDataResultResponse(response.responseData);
        OnSuccessSetPublisherData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetTitleData(FServerSetTitleDataRequest request,
    FDelegateOnSuccessSetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetTitleData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }
    if (request.Value.IsEmpty() || request.Value == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Value"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Value"), request.Value);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetTitleData.IsBound())
    {
        FServerSetTitleDataResult result = UPlayFabServerModelDecoder::decodeSetTitleDataResultResponse(response.responseData);
        OnSuccessSetTitleData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the key-value store of custom title settings */
UPlayFabServerAPI* UPlayFabServerAPI::SetTitleInternalData(FServerSetTitleDataRequest request,
    FDelegateOnSuccessSetTitleInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetTitleInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetTitleInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetTitleInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }
    if (request.Value.IsEmpty() || request.Value == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Value"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Value"), request.Value);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetTitleInternalData.IsBound())
    {
        FServerSetTitleDataResult result = UPlayFabServerModelDecoder::decodeSetTitleDataResultResponse(response.responseData);
        OnSuccessSetTitleInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments  the character's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::AddCharacterVirtualCurrency(FServerAddCharacterVirtualCurrencyRequest request,
    FDelegateOnSuccessAddCharacterVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddCharacterVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddCharacterVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddCharacterVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddCharacterVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAddCharacterVirtualCurrency.IsBound())
    {
        FServerModifyCharacterVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyCharacterVirtualCurrencyResultResponse(response.responseData);
        OnSuccessAddCharacterVirtualCurrency.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Increments  the user's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::AddUserVirtualCurrency(FServerAddUserVirtualCurrencyRequest request,
    FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddUserVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAddUserVirtualCurrency.IsBound())
    {
        FServerModifyUserVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        OnSuccessAddUserVirtualCurrency.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::ConsumeItem(FServerConsumeItemRequest request,
    FDelegateOnSuccessConsumeItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessConsumeItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperConsumeItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ConsumeItem";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }
    OutRestJsonObj->SetNumberField(TEXT("ConsumeCount"), request.ConsumeCount);
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperConsumeItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessConsumeItem.IsBound())
    {
        FServerConsumeItemResult result = UPlayFabServerModelDecoder::decodeConsumeItemResultResponse(response.responseData);
        OnSuccessConsumeItem.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Returns the result of an evaluation of a Random Result Table - the ItemId from the game Catalog which would have been added to the player inventory, if the Random Result Table were added via a Bundle or a call to UnlockContainer. */
UPlayFabServerAPI* UPlayFabServerAPI::EvaluateRandomResultTable(FServerEvaluateRandomResultTableRequest request,
    FDelegateOnSuccessEvaluateRandomResultTable onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessEvaluateRandomResultTable = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperEvaluateRandomResultTable);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/EvaluateRandomResultTable";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.TableId.IsEmpty() || request.TableId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TableId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TableId"), request.TableId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperEvaluateRandomResultTable(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessEvaluateRandomResultTable.IsBound())
    {
        FServerEvaluateRandomResultTableResult result = UPlayFabServerModelDecoder::decodeEvaluateRandomResultTableResultResponse(response.responseData);
        OnSuccessEvaluateRandomResultTable.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the specified character's current inventory of virtual goods */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterInventory(FServerGetCharacterInventoryRequest request,
    FDelegateOnSuccessGetCharacterInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterInventory";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterInventory(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCharacterInventory.IsBound())
    {
        FServerGetCharacterInventoryResult result = UPlayFabServerModelDecoder::decodeGetCharacterInventoryResultResponse(response.responseData);
        OnSuccessGetCharacterInventory.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the configuration information for the specified random results tables for the title, including all ItemId values and weights */
UPlayFabServerAPI* UPlayFabServerAPI::GetRandomResultTables(FServerGetRandomResultTablesRequest request,
    FDelegateOnSuccessGetRandomResultTables onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetRandomResultTables = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetRandomResultTables);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetRandomResultTables";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    // Check to see if string is empty
    if (request.TableIDs.IsEmpty() || request.TableIDs == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TableIDs"));
    } else {
        TArray<FString> TableIDsArray;
        FString(request.TableIDs).ParseIntoArray(TableIDsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("TableIDs"), TableIDsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetRandomResultTables(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetRandomResultTables.IsBound())
    {
        FServerGetRandomResultTablesResult result = UPlayFabServerModelDecoder::decodeGetRandomResultTablesResultResponse(response.responseData);
        OnSuccessGetRandomResultTables.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the specified user's current inventory of virtual goods */
UPlayFabServerAPI* UPlayFabServerAPI::GetUserInventory(FServerGetUserInventoryRequest request,
    FDelegateOnSuccessGetUserInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetUserInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetUserInventory";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetUserInventory(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetUserInventory.IsBound())
    {
        FServerGetUserInventoryResult result = UPlayFabServerModelDecoder::decodeGetUserInventoryResultResponse(response.responseData);
        OnSuccessGetUserInventory.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Adds the specified items to the specified character's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToCharacter(FServerGrantItemsToCharacterRequest request,
    FDelegateOnSuccessGrantItemsToCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGrantItemsToCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantItemsToCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantItemsToCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Annotation.IsEmpty() || request.Annotation == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Annotation"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Annotation"), request.Annotation);
    }
    // Check to see if string is empty
    if (request.ItemIds.IsEmpty() || request.ItemIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemIds"));
    } else {
        TArray<FString> ItemIdsArray;
        FString(request.ItemIds).ParseIntoArray(ItemIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ItemIds"), ItemIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantItemsToCharacter(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGrantItemsToCharacter.IsBound())
    {
        FServerGrantItemsToCharacterResult result = UPlayFabServerModelDecoder::decodeGrantItemsToCharacterResultResponse(response.responseData);
        OnSuccessGrantItemsToCharacter.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Adds the specified items to the specified user's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToUser(FServerGrantItemsToUserRequest request,
    FDelegateOnSuccessGrantItemsToUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGrantItemsToUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantItemsToUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantItemsToUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Annotation.IsEmpty() || request.Annotation == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Annotation"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Annotation"), request.Annotation);
    }
    // Check to see if string is empty
    if (request.ItemIds.IsEmpty() || request.ItemIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemIds"));
    } else {
        TArray<FString> ItemIdsArray;
        FString(request.ItemIds).ParseIntoArray(ItemIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ItemIds"), ItemIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantItemsToUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGrantItemsToUser.IsBound())
    {
        FServerGrantItemsToUserResult result = UPlayFabServerModelDecoder::decodeGrantItemsToUserResultResponse(response.responseData);
        OnSuccessGrantItemsToUser.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Adds the specified items to the specified user inventories */
UPlayFabServerAPI* UPlayFabServerAPI::GrantItemsToUsers(FServerGrantItemsToUsersRequest request,
    FDelegateOnSuccessGrantItemsToUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGrantItemsToUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantItemsToUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantItemsToUsers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.ItemGrants.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("ItemGrants"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("ItemGrants"), request.ItemGrants);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantItemsToUsers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGrantItemsToUsers.IsBound())
    {
        FServerGrantItemsToUsersResult result = UPlayFabServerModelDecoder::decodeGrantItemsToUsersResultResponse(response.responseData);
        OnSuccessGrantItemsToUsers.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Modifies the number of remaining uses of a player's inventory item */
UPlayFabServerAPI* UPlayFabServerAPI::ModifyItemUses(FServerModifyItemUsesRequest request,
    FDelegateOnSuccessModifyItemUses onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessModifyItemUses = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperModifyItemUses);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ModifyItemUses";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }
    OutRestJsonObj->SetNumberField(TEXT("UsesToAdd"), request.UsesToAdd);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperModifyItemUses(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessModifyItemUses.IsBound())
    {
        FServerModifyItemUsesResult result = UPlayFabServerModelDecoder::decodeModifyItemUsesResultResponse(response.responseData);
        OnSuccessModifyItemUses.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Moves an item from a character's inventory into another of the users's character's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToCharacterFromCharacter(FServerMoveItemToCharacterFromCharacterRequest request,
    FDelegateOnSuccessMoveItemToCharacterFromCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessMoveItemToCharacterFromCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperMoveItemToCharacterFromCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/MoveItemToCharacterFromCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.GivingCharacterId.IsEmpty() || request.GivingCharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GivingCharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GivingCharacterId"), request.GivingCharacterId);
    }
    if (request.ReceivingCharacterId.IsEmpty() || request.ReceivingCharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReceivingCharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReceivingCharacterId"), request.ReceivingCharacterId);
    }
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperMoveItemToCharacterFromCharacter(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessMoveItemToCharacterFromCharacter.IsBound())
    {
        FServerMoveItemToCharacterFromCharacterResult result = UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromCharacterResultResponse(response.responseData);
        OnSuccessMoveItemToCharacterFromCharacter.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Moves an item from a user's inventory into their character's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToCharacterFromUser(FServerMoveItemToCharacterFromUserRequest request,
    FDelegateOnSuccessMoveItemToCharacterFromUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessMoveItemToCharacterFromUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperMoveItemToCharacterFromUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/MoveItemToCharacterFromUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperMoveItemToCharacterFromUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessMoveItemToCharacterFromUser.IsBound())
    {
        FServerMoveItemToCharacterFromUserResult result = UPlayFabServerModelDecoder::decodeMoveItemToCharacterFromUserResultResponse(response.responseData);
        OnSuccessMoveItemToCharacterFromUser.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Moves an item from a character's inventory into the owning user's inventory. */
UPlayFabServerAPI* UPlayFabServerAPI::MoveItemToUserFromCharacter(FServerMoveItemToUserFromCharacterRequest request,
    FDelegateOnSuccessMoveItemToUserFromCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessMoveItemToUserFromCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperMoveItemToUserFromCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/MoveItemToUserFromCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperMoveItemToUserFromCharacter(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessMoveItemToUserFromCharacter.IsBound())
    {
        FServerMoveItemToUserFromCharacterResult result = UPlayFabServerModelDecoder::decodeMoveItemToUserFromCharacterResultResponse(response.responseData);
        OnSuccessMoveItemToUserFromCharacter.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated  via the Economy->Catalogs tab in the PlayFab Game Manager. */
UPlayFabServerAPI* UPlayFabServerAPI::RedeemCoupon(FServerRedeemCouponRequest request,
    FDelegateOnSuccessRedeemCoupon onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemCoupon = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRedeemCoupon);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RedeemCoupon";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CouponCode.IsEmpty() || request.CouponCode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CouponCode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CouponCode"), request.CouponCode);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRedeemCoupon(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemCoupon.IsBound())
    {
        FServerRedeemCouponResult result = UPlayFabServerModelDecoder::decodeRedeemCouponResultResponse(response.responseData);
        OnSuccessRedeemCoupon.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer service representatives for the title can take action concerning potentially toxic players. */
UPlayFabServerAPI* UPlayFabServerAPI::ReportPlayer(FServerReportPlayerServerRequest request,
    FDelegateOnSuccessReportPlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessReportPlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperReportPlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ReportPlayer";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.ReporterId.IsEmpty() || request.ReporterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReporterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReporterId"), request.ReporterId);
    }
    if (request.ReporteeId.IsEmpty() || request.ReporteeId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReporteeId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReporteeId"), request.ReporteeId);
    }
    if (request.Comment.IsEmpty() || request.Comment == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Comment"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Comment"), request.Comment);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperReportPlayer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessReportPlayer.IsBound())
    {
        FServerReportPlayerServerResult result = UPlayFabServerModelDecoder::decodeReportPlayerServerResultResponse(response.responseData);
        OnSuccessReportPlayer.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Revokes access to an item in a user's inventory */
UPlayFabServerAPI* UPlayFabServerAPI::RevokeInventoryItem(FServerRevokeInventoryItemRequest request,
    FDelegateOnSuccessRevokeInventoryItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRevokeInventoryItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRevokeInventoryItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RevokeInventoryItem";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRevokeInventoryItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRevokeInventoryItem.IsBound())
    {
        FServerRevokeInventoryResult result = UPlayFabServerModelDecoder::decodeRevokeInventoryResultResponse(response.responseData);
        OnSuccessRevokeInventoryItem.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Decrements the character's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::SubtractCharacterVirtualCurrency(FServerSubtractCharacterVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractCharacterVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSubtractCharacterVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSubtractCharacterVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SubtractCharacterVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSubtractCharacterVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSubtractCharacterVirtualCurrency.IsBound())
    {
        FServerModifyCharacterVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyCharacterVirtualCurrencyResultResponse(response.responseData);
        OnSuccessSubtractCharacterVirtualCurrency.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Decrements the user's balance of the specified virtual currency by the stated amount */
UPlayFabServerAPI* UPlayFabServerAPI::SubtractUserVirtualCurrency(FServerSubtractUserVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSubtractUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSubtractUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SubtractUserVirtualCurrency";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.VirtualCurrency.IsEmpty() || request.VirtualCurrency == "") {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrency"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("VirtualCurrency"), request.VirtualCurrency);
    }
    OutRestJsonObj->SetNumberField(TEXT("Amount"), request.Amount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSubtractUserVirtualCurrency.IsBound())
    {
        FServerModifyUserVirtualCurrencyResult result = UPlayFabServerModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        OnSuccessSubtractUserVirtualCurrency.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Opens a specific container (ContainerItemInstanceId), with a specific key (KeyItemInstanceId, when required), and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabServerAPI* UPlayFabServerAPI::UnlockContainerInstance(FServerUnlockContainerInstanceRequest request,
    FDelegateOnSuccessUnlockContainerInstance onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlockContainerInstance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUnlockContainerInstance);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UnlockContainerInstance";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.ContainerItemInstanceId.IsEmpty() || request.ContainerItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContainerItemInstanceId"), request.ContainerItemInstanceId);
    }
    if (request.KeyItemInstanceId.IsEmpty() || request.KeyItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeyItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("KeyItemInstanceId"), request.KeyItemInstanceId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUnlockContainerInstance(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUnlockContainerInstance.IsBound())
    {
        FServerUnlockContainerItemResult result = UPlayFabServerModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        OnSuccessUnlockContainerInstance.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Searches Player or Character inventory for any ItemInstance matching the given CatalogItemId, if necessary unlocks it using any appropriate key, and returns the contents of the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation of ConsumeItem. */
UPlayFabServerAPI* UPlayFabServerAPI::UnlockContainerItem(FServerUnlockContainerItemRequest request,
    FDelegateOnSuccessUnlockContainerItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUnlockContainerItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUnlockContainerItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UnlockContainerItem";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.ContainerItemId.IsEmpty() || request.ContainerItemId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContainerItemId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContainerItemId"), request.ContainerItemId);
    }
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUnlockContainerItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUnlockContainerItem.IsBound())
    {
        FServerUnlockContainerItemResult result = UPlayFabServerModelDecoder::decodeUnlockContainerItemResultResponse(response.responseData);
        OnSuccessUnlockContainerItem.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the key-value pair data tagged to the specified item, which is read-only from the client. */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateUserInventoryItemCustomData(FServerUpdateUserInventoryItemDataRequest request,
    FDelegateOnSuccessUpdateUserInventoryItemCustomData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserInventoryItemCustomData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateUserInventoryItemCustomData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateUserInventoryItemCustomData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.ItemInstanceId.IsEmpty() || request.ItemInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ItemInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ItemInstanceId"), request.ItemInstanceId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateUserInventoryItemCustomData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateUserInventoryItemCustomData.IsBound())
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        OnSuccessUpdateUserInventoryItemCustomData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////
/** Adds the Friend user to the friendlist of the user with PlayFabId. At least one of FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName should be initialized. */
UPlayFabServerAPI* UPlayFabServerAPI::AddFriend(FServerAddFriendRequest request,
    FDelegateOnSuccessAddFriend onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddFriend = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddFriend);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddFriend";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }
    if (request.FriendUsername.IsEmpty() || request.FriendUsername == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendUsername"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendUsername"), request.FriendUsername);
    }
    if (request.FriendEmail.IsEmpty() || request.FriendEmail == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendEmail"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendEmail"), request.FriendEmail);
    }
    if (request.FriendTitleDisplayName.IsEmpty() || request.FriendTitleDisplayName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendTitleDisplayName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendTitleDisplayName"), request.FriendTitleDisplayName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddFriend(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAddFriend.IsBound())
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        OnSuccessAddFriend.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the current friends for the user with PlayFabId, constrained to users who have PlayFab accounts. Friends from linked accounts (Facebook, Steam) are also included. You may optionally exclude some linked services' friends. */
UPlayFabServerAPI* UPlayFabServerAPI::GetFriendsList(FServerGetFriendsListRequest request,
    FDelegateOnSuccessGetFriendsList onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetFriendsList = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetFriendsList);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetFriendsList";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetBoolField(TEXT("IncludeSteamFriends"), request.IncludeSteamFriends);
    OutRestJsonObj->SetBoolField(TEXT("IncludeFacebookFriends"), request.IncludeFacebookFriends);
    if (request.ProfileConstraints != nullptr) OutRestJsonObj->SetObjectField(TEXT("ProfileConstraints"), request.ProfileConstraints);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetFriendsList(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetFriendsList.IsBound())
    {
        FServerGetFriendsListResult result = UPlayFabServerModelDecoder::decodeGetFriendsListResultResponse(response.responseData);
        OnSuccessGetFriendsList.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Removes the specified friend from the the user's friend list */
UPlayFabServerAPI* UPlayFabServerAPI::RemoveFriend(FServerRemoveFriendRequest request,
    FDelegateOnSuccessRemoveFriend onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveFriend = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRemoveFriend);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RemoveFriend";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRemoveFriend(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRemoveFriend.IsBound())
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        OnSuccessRemoveFriend.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the tag list for a specified user in the friend list of another user */
UPlayFabServerAPI* UPlayFabServerAPI::SetFriendTags(FServerSetFriendTagsRequest request,
    FDelegateOnSuccessSetFriendTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetFriendTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetFriendTags);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetFriendTags";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.FriendPlayFabId.IsEmpty() || request.FriendPlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendPlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendPlayFabId"), request.FriendPlayFabId);
    }
    // Check to see if string is empty
    if (request.Tags.IsEmpty() || request.Tags == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Tags"));
    } else {
        TArray<FString> TagsArray;
        FString(request.Tags).ParseIntoArray(TagsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Tags"), TagsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetFriendTags(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetFriendTags.IsBound())
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        OnSuccessSetFriendTags.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////
/** Inform the matchmaker that a Game Server Instance is removed. */
UPlayFabServerAPI* UPlayFabServerAPI::DeregisterGame(FServerDeregisterGameRequest request,
    FDelegateOnSuccessDeregisterGame onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeregisterGame = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperDeregisterGame);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/DeregisterGame";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperDeregisterGame(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeregisterGame.IsBound())
    {
        FServerDeregisterGameResponse result = UPlayFabServerModelDecoder::decodeDeregisterGameResponseResponse(response.responseData);
        OnSuccessDeregisterGame.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Informs the PlayFab match-making service that the user specified has left the Game Server Instance */
UPlayFabServerAPI* UPlayFabServerAPI::NotifyMatchmakerPlayerLeft(FServerNotifyMatchmakerPlayerLeftRequest request,
    FDelegateOnSuccessNotifyMatchmakerPlayerLeft onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessNotifyMatchmakerPlayerLeft = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperNotifyMatchmakerPlayerLeft);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/NotifyMatchmakerPlayerLeft";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperNotifyMatchmakerPlayerLeft(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessNotifyMatchmakerPlayerLeft.IsBound())
    {
        FServerNotifyMatchmakerPlayerLeftResult result = UPlayFabServerModelDecoder::decodeNotifyMatchmakerPlayerLeftResultResponse(response.responseData);
        OnSuccessNotifyMatchmakerPlayerLeft.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Validates a Game Server session ticket and returns details about the user */
UPlayFabServerAPI* UPlayFabServerAPI::RedeemMatchmakerTicket(FServerRedeemMatchmakerTicketRequest request,
    FDelegateOnSuccessRedeemMatchmakerTicket onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRedeemMatchmakerTicket = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRedeemMatchmakerTicket);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RedeemMatchmakerTicket";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Ticket.IsEmpty() || request.Ticket == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Ticket"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Ticket"), request.Ticket);
    }
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRedeemMatchmakerTicket(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRedeemMatchmakerTicket.IsBound())
    {
        FServerRedeemMatchmakerTicketResult result = UPlayFabServerModelDecoder::decodeRedeemMatchmakerTicketResultResponse(response.responseData);
        OnSuccessRedeemMatchmakerTicket.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Set the state of the indicated Game Server Instance. Also update the heartbeat for the instance. */
UPlayFabServerAPI* UPlayFabServerAPI::RefreshGameServerInstanceHeartbeat(FServerRefreshGameServerInstanceHeartbeatRequest request,
    FDelegateOnSuccessRefreshGameServerInstanceHeartbeat onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRefreshGameServerInstanceHeartbeat = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRefreshGameServerInstanceHeartbeat);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RefreshGameServerInstanceHeartbeat";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRefreshGameServerInstanceHeartbeat(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRefreshGameServerInstanceHeartbeat.IsBound())
    {
        FServerRefreshGameServerInstanceHeartbeatResult result = UPlayFabServerModelDecoder::decodeRefreshGameServerInstanceHeartbeatResultResponse(response.responseData);
        OnSuccessRefreshGameServerInstanceHeartbeat.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Inform the matchmaker that a new Game Server Instance is added. */
UPlayFabServerAPI* UPlayFabServerAPI::RegisterGame(FServerRegisterGameRequest request,
    FDelegateOnSuccessRegisterGame onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRegisterGame = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRegisterGame);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RegisterGame";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    if (request.ServerHost.IsEmpty() || request.ServerHost == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ServerHost"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ServerHost"), request.ServerHost);
    }
    if (request.ServerPort.IsEmpty() || request.ServerPort == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ServerPort"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ServerPort"), request.ServerPort);
    }
    if (request.Build.IsEmpty() || request.Build == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Build"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Build"), request.Build);
    }
    FString temp_Region;
    if (GetEnumValueToString<ERegion>(TEXT("ERegion"), request.Region, temp_Region))
        OutRestJsonObj->SetStringField(TEXT("Region"), temp_Region);
    if (request.GameMode.IsEmpty() || request.GameMode == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameMode"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GameMode"), request.GameMode);
    }
    if (request.Tags != nullptr) OutRestJsonObj->SetObjectField(TEXT("Tags"), request.Tags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRegisterGame(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRegisterGame.IsBound())
    {
        FServerRegisterGameResponse result = UPlayFabServerModelDecoder::decodeRegisterGameResponseResponse(response.responseData);
        OnSuccessRegisterGame.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Sets the custom data of the indicated Game Server Instance */
UPlayFabServerAPI* UPlayFabServerAPI::SetGameServerInstanceData(FServerSetGameServerInstanceDataRequest request,
    FDelegateOnSuccessSetGameServerInstanceData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetGameServerInstanceData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetGameServerInstanceData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetGameServerInstanceData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    if (request.GameServerData.IsEmpty() || request.GameServerData == "") {
        OutRestJsonObj->SetFieldNull(TEXT("GameServerData"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("GameServerData"), request.GameServerData);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetGameServerInstanceData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetGameServerInstanceData.IsBound())
    {
        FServerSetGameServerInstanceDataResult result = UPlayFabServerModelDecoder::decodeSetGameServerInstanceDataResultResponse(response.responseData);
        OnSuccessSetGameServerInstanceData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Set the state of the indicated Game Server Instance. */
UPlayFabServerAPI* UPlayFabServerAPI::SetGameServerInstanceState(FServerSetGameServerInstanceStateRequest request,
    FDelegateOnSuccessSetGameServerInstanceState onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetGameServerInstanceState = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetGameServerInstanceState);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetGameServerInstanceState";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    FString temp_State;
    if (GetEnumValueToString<EGameInstanceState>(TEXT("EGameInstanceState"), request.State, temp_State))
        OutRestJsonObj->SetStringField(TEXT("State"), temp_State);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetGameServerInstanceState(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetGameServerInstanceState.IsBound())
    {
        FServerSetGameServerInstanceStateResult result = UPlayFabServerModelDecoder::decodeSetGameServerInstanceStateResultResponse(response.responseData);
        OnSuccessSetGameServerInstanceState.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Set custom tags for the specified Game Server Instance */
UPlayFabServerAPI* UPlayFabServerAPI::SetGameServerInstanceTags(FServerSetGameServerInstanceTagsRequest request,
    FDelegateOnSuccessSetGameServerInstanceTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetGameServerInstanceTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperSetGameServerInstanceTags);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/SetGameServerInstanceTags";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.LobbyId.IsEmpty() || request.LobbyId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("LobbyId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("LobbyId"), request.LobbyId);
    }
    if (request.Tags != nullptr) OutRestJsonObj->SetObjectField(TEXT("Tags"), request.Tags);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperSetGameServerInstanceTags(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessSetGameServerInstanceTags.IsBound())
    {
        FServerSetGameServerInstanceTagsResult result = UPlayFabServerModelDecoder::decodeSetGameServerInstanceTagsResultResponse(response.responseData);
        OnSuccessSetGameServerInstanceTags.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////
/** Writes a character-based event into PlayStream. */
UPlayFabServerAPI* UPlayFabServerAPI::WriteCharacterEvent(FServerWriteServerCharacterEventRequest request,
    FDelegateOnSuccessWriteCharacterEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWriteCharacterEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperWriteCharacterEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/WriteCharacterEvent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.EventName.IsEmpty() || request.EventName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    if (request.Body != nullptr) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperWriteCharacterEvent(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessWriteCharacterEvent.IsBound())
    {
        FServerWriteEventResponse result = UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        OnSuccessWriteCharacterEvent.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Writes a player-based event into PlayStream. */
UPlayFabServerAPI* UPlayFabServerAPI::WritePlayerEvent(FServerWriteServerPlayerEventRequest request,
    FDelegateOnSuccessWritePlayerEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWritePlayerEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperWritePlayerEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/WritePlayerEvent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.EventName.IsEmpty() || request.EventName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    if (request.Body != nullptr) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperWritePlayerEvent(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessWritePlayerEvent.IsBound())
    {
        FServerWriteEventResponse result = UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        OnSuccessWritePlayerEvent.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Writes a title-based event into PlayStream. */
UPlayFabServerAPI* UPlayFabServerAPI::WriteTitleEvent(FServerWriteTitleEventRequest request,
    FDelegateOnSuccessWriteTitleEvent onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessWriteTitleEvent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperWriteTitleEvent);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/WriteTitleEvent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.EventName.IsEmpty() || request.EventName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("EventName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("EventName"), request.EventName);
    }
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    if (request.Body != nullptr) OutRestJsonObj->SetObjectField(TEXT("Body"), request.Body);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperWriteTitleEvent(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessWriteTitleEvent.IsBound())
    {
        FServerWriteEventResponse result = UPlayFabServerModelDecoder::decodeWriteEventResponseResponse(response.responseData);
        OnSuccessWriteTitleEvent.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Adds users to the set of those able to update both the shared data, as well as the set of users  in the group. Only users in the group (and the server) can add new members. Shared Groups are designed for sharing data  between a very small number of players, please see our guide: https://api.playfab.com/docs/tutorials/landing-players/shared-groups */
UPlayFabServerAPI* UPlayFabServerAPI::AddSharedGroupMembers(FServerAddSharedGroupMembersRequest request,
    FDelegateOnSuccessAddSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddSharedGroupMembers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    } else {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAddSharedGroupMembers.IsBound())
    {
        FServerAddSharedGroupMembersResult result = UPlayFabServerModelDecoder::decodeAddSharedGroupMembersResultResponse(response.responseData);
        OnSuccessAddSharedGroupMembers.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Requests the creation of a shared group object, containing key/value pairs which may  be updated by all members of the group. When created by a server, the group will initially have no members.  Shared Groups are designed for sharing data between a very small number of players, please see our guide: https://api.playfab.com/docs/tutorials/landing-players/shared-groups */
UPlayFabServerAPI* UPlayFabServerAPI::CreateSharedGroup(FServerCreateSharedGroupRequest request,
    FDelegateOnSuccessCreateSharedGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateSharedGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperCreateSharedGroup);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/CreateSharedGroup";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperCreateSharedGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessCreateSharedGroup.IsBound())
    {
        FServerCreateSharedGroupResult result = UPlayFabServerModelDecoder::decodeCreateSharedGroupResultResponse(response.responseData);
        OnSuccessCreateSharedGroup.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Deletes a shared group, freeing up the shared group ID to be reused for a new group.  Shared Groups are designed for sharing data between a very small number of players, please see our guide:  https://api.playfab.com/docs/tutorials/landing-players/shared-groups */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteSharedGroup(FServerDeleteSharedGroupRequest request,
    FDelegateOnSuccessDeleteSharedGroup onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteSharedGroup = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperDeleteSharedGroup);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/DeleteSharedGroup";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperDeleteSharedGroup(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteSharedGroup.IsBound())
    {
        FServerEmptyResult result = UPlayFabServerModelDecoder::decodeEmptyResultResponse(response.responseData);
        OnSuccessDeleteSharedGroup.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves data stored in a shared group object, as well as the list of members in the group.  The server can access all public and private group data. Shared Groups are designed for sharing data between a very  small number of players, please see our guide: https://api.playfab.com/docs/tutorials/landing-players/shared-groups */
UPlayFabServerAPI* UPlayFabServerAPI::GetSharedGroupData(FServerGetSharedGroupDataRequest request,
    FDelegateOnSuccessGetSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetSharedGroupData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetBoolField(TEXT("GetMembers"), request.GetMembers);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetSharedGroupData.IsBound())
    {
        FServerGetSharedGroupDataResult result = UPlayFabServerModelDecoder::decodeGetSharedGroupDataResultResponse(response.responseData);
        OnSuccessGetSharedGroupData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Removes users from the set of those able to update the shared data and the set of users in the group. Only users in the group can remove members. If as a result of the call, zero users remain with access, the group and its associated data will be deleted. Shared Groups are designed for sharing data between a very small number of players,  please see our guide: https://api.playfab.com/docs/tutorials/landing-players/shared-groups */
UPlayFabServerAPI* UPlayFabServerAPI::RemoveSharedGroupMembers(FServerRemoveSharedGroupMembersRequest request,
    FDelegateOnSuccessRemoveSharedGroupMembers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveSharedGroupMembers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRemoveSharedGroupMembers);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RemoveSharedGroupMembers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    // Check to see if string is empty
    if (request.PlayFabIds.IsEmpty() || request.PlayFabIds == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabIds"));
    } else {
        TArray<FString> PlayFabIdsArray;
        FString(request.PlayFabIds).ParseIntoArray(PlayFabIdsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("PlayFabIds"), PlayFabIdsArray);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRemoveSharedGroupMembers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRemoveSharedGroupMembers.IsBound())
    {
        FServerRemoveSharedGroupMembersResult result = UPlayFabServerModelDecoder::decodeRemoveSharedGroupMembersResultResponse(response.responseData);
        OnSuccessRemoveSharedGroupMembers.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Adds, updates, and removes data keys for a shared group object. If the permission is set to Public, all fields updated or added in this call will be readable by users not in the group. By default, data permissions are set to Private. Regardless of the permission setting, only members of the group (and the server) can update the data.  Shared Groups are designed for sharing data between a very small number of players, please see our guide:  https://api.playfab.com/docs/tutorials/landing-players/shared-groups */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateSharedGroupData(FServerUpdateSharedGroupDataRequest request,
    FDelegateOnSuccessUpdateSharedGroupData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateSharedGroupData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateSharedGroupData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateSharedGroupData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SharedGroupId.IsEmpty() || request.SharedGroupId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SharedGroupId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SharedGroupId"), request.SharedGroupId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateSharedGroupData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateSharedGroupData.IsBound())
    {
        FServerUpdateSharedGroupDataResult result = UPlayFabServerModelDecoder::decodeUpdateSharedGroupDataResultResponse(response.responseData);
        OnSuccessUpdateSharedGroupData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Executes a CloudScript function, with the 'currentPlayerId' variable set to the specified PlayFabId parameter value. */
UPlayFabServerAPI* UPlayFabServerAPI::ExecuteCloudScript(FServerExecuteCloudScriptServerRequest request,
    FDelegateOnSuccessExecuteCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessExecuteCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperExecuteCloudScript);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/ExecuteCloudScript";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.FunctionName.IsEmpty() || request.FunctionName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FunctionName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FunctionName"), request.FunctionName);
    }
    if (request.FunctionParameter != nullptr) OutRestJsonObj->SetObjectField(TEXT("FunctionParameter"), request.FunctionParameter);
    FString temp_RevisionSelection;
    if (GetEnumValueToString<ECloudScriptRevisionOption>(TEXT("ECloudScriptRevisionOption"), request.RevisionSelection, temp_RevisionSelection))
        OutRestJsonObj->SetStringField(TEXT("RevisionSelection"), temp_RevisionSelection);
    OutRestJsonObj->SetNumberField(TEXT("SpecificRevision"), request.SpecificRevision);
    OutRestJsonObj->SetBoolField(TEXT("GeneratePlayStreamEvent"), request.GeneratePlayStreamEvent);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperExecuteCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessExecuteCloudScript.IsBound())
    {
        FServerExecuteCloudScriptResult result = UPlayFabServerModelDecoder::decodeExecuteCloudScriptResultResponse(response.responseData);
        OnSuccessExecuteCloudScript.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent  HTTP GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will attempt to  retrieve the metadata of the content. Note that a successful result does not guarantee the existence of this content -  if it has not been uploaded, the query to retrieve the data will fail. See this post for more information:  https://community.playfab.com/hc/en-us/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service.  Also, please be aware that the Content service is specifically PlayFab's CDN offering, for which standard CDN rates apply. */
UPlayFabServerAPI* UPlayFabServerAPI::GetContentDownloadUrl(FServerGetContentDownloadUrlRequest request,
    FDelegateOnSuccessGetContentDownloadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetContentDownloadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetContentDownloadUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetContentDownloadUrl";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }
    if (request.HttpMethod.IsEmpty() || request.HttpMethod == "") {
        OutRestJsonObj->SetFieldNull(TEXT("HttpMethod"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("HttpMethod"), request.HttpMethod);
    }
    OutRestJsonObj->SetBoolField(TEXT("ThruCDN"), request.ThruCDN);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetContentDownloadUrl(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetContentDownloadUrl.IsBound())
    {
        FServerGetContentDownloadUrlResult result = UPlayFabServerModelDecoder::decodeGetContentDownloadUrlResultResponse(response.responseData);
        OnSuccessGetContentDownloadUrl.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Deletes the specific character ID from the specified user. */
UPlayFabServerAPI* UPlayFabServerAPI::DeleteCharacterFromUser(FServerDeleteCharacterFromUserRequest request,
    FDelegateOnSuccessDeleteCharacterFromUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteCharacterFromUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperDeleteCharacterFromUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/DeleteCharacterFromUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    OutRestJsonObj->SetBoolField(TEXT("SaveCharacterInventory"), request.SaveCharacterInventory);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperDeleteCharacterFromUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessDeleteCharacterFromUser.IsBound())
    {
        FServerDeleteCharacterFromUserResult result = UPlayFabServerModelDecoder::decodeDeleteCharacterFromUserResultResponse(response.responseData);
        OnSuccessDeleteCharacterFromUser.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Lists all of the characters that belong to a specific user. CharacterIds are not globally unique; characterId must be evaluated with the parent PlayFabId to guarantee uniqueness. */
UPlayFabServerAPI* UPlayFabServerAPI::GetAllUsersCharacters(FServerListUsersCharactersRequest request,
    FDelegateOnSuccessGetAllUsersCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAllUsersCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetAllUsersCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetAllUsersCharacters";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetAllUsersCharacters(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetAllUsersCharacters.IsBound())
    {
        FServerListUsersCharactersResult result = UPlayFabServerModelDecoder::decodeListUsersCharactersResultResponse(response.responseData);
        OnSuccessGetAllUsersCharacters.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a list of ranked characters for the given statistic, starting from the indicated point in the leaderboard */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterLeaderboard(FServerGetCharacterLeaderboardRequest request,
    FDelegateOnSuccessGetCharacterLeaderboard onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterLeaderboard = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterLeaderboard);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterLeaderboard";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CharacterType.IsEmpty() || request.CharacterType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    OutRestJsonObj->SetNumberField(TEXT("StartPosition"), request.StartPosition);
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterLeaderboard(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCharacterLeaderboard.IsBound())
    {
        FServerGetCharacterLeaderboardResult result = UPlayFabServerModelDecoder::decodeGetCharacterLeaderboardResultResponse(response.responseData);
        OnSuccessGetCharacterLeaderboard.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the details of all title-specific statistics for the specific character */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterStatistics(FServerGetCharacterStatisticsRequest request,
    FDelegateOnSuccessGetCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCharacterStatistics.IsBound())
    {
        FServerGetCharacterStatisticsResult result = UPlayFabServerModelDecoder::decodeGetCharacterStatisticsResultResponse(response.responseData);
        OnSuccessGetCharacterStatistics.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a list of ranked characters for the given statistic, centered on the requested user */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardAroundCharacter(FServerGetLeaderboardAroundCharacterRequest request,
    FDelegateOnSuccessGetLeaderboardAroundCharacter onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardAroundCharacter = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboardAroundCharacter);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboardAroundCharacter";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CharacterType.IsEmpty() || request.CharacterType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboardAroundCharacter(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboardAroundCharacter.IsBound())
    {
        FServerGetLeaderboardAroundCharacterResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardAroundCharacterResultResponse(response.responseData);
        OnSuccessGetLeaderboardAroundCharacter.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves a list of all of the user's characters for the given statistic. */
UPlayFabServerAPI* UPlayFabServerAPI::GetLeaderboardForUserCharacters(FServerGetLeaderboardForUsersCharactersRequest request,
    FDelegateOnSuccessGetLeaderboardForUserCharacters onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetLeaderboardForUserCharacters = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetLeaderboardForUserCharacters);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetLeaderboardForUserCharacters";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxResultsCount"), request.MaxResultsCount);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetLeaderboardForUserCharacters(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetLeaderboardForUserCharacters.IsBound())
    {
        FServerGetLeaderboardForUsersCharactersResult result = UPlayFabServerModelDecoder::decodeGetLeaderboardForUsersCharactersResultResponse(response.responseData);
        OnSuccessGetLeaderboardForUserCharacters.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Grants the specified character type to the user. CharacterIds are not globally unique; characterId must be evaluated with the parent PlayFabId to guarantee uniqueness. */
UPlayFabServerAPI* UPlayFabServerAPI::GrantCharacterToUser(FServerGrantCharacterToUserRequest request,
    FDelegateOnSuccessGrantCharacterToUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGrantCharacterToUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGrantCharacterToUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GrantCharacterToUser";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterName.IsEmpty() || request.CharacterName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterName"), request.CharacterName);
    }
    if (request.CharacterType.IsEmpty() || request.CharacterType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterType"), request.CharacterType);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGrantCharacterToUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGrantCharacterToUser.IsBound())
    {
        FServerGrantCharacterToUserResult result = UPlayFabServerModelDecoder::decodeGrantCharacterToUserResultResponse(response.responseData);
        OnSuccessGrantCharacterToUser.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the values of the specified title-specific statistics for the specific character */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterStatistics(FServerUpdateCharacterStatisticsRequest request,
    FDelegateOnSuccessUpdateCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterStatistics";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.CharacterStatistics != nullptr) OutRestJsonObj->SetObjectField(TEXT("CharacterStatistics"), request.CharacterStatistics);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateCharacterStatistics.IsBound())
    {
        FServerUpdateCharacterStatisticsResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterStatisticsResultResponse(response.responseData);
        OnSuccessUpdateCharacterStatistics.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////
/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterData(FServerGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCharacterData.IsBound())
    {
        FServerGetCharacterDataResult result = UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        OnSuccessGetCharacterData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the title-specific custom data for the user's character which cannot be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterInternalData(FServerGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCharacterInternalData.IsBound())
    {
        FServerGetCharacterDataResult result = UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        OnSuccessGetCharacterInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves the title-specific custom data for the user's character which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::GetCharacterReadOnlyData(FServerGetCharacterDataRequest request,
    FDelegateOnSuccessGetCharacterReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCharacterReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetCharacterReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetCharacterReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    // Check to see if string is empty
    if (request.Keys.IsEmpty() || request.Keys == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Keys"));
    } else {
        TArray<FString> KeysArray;
        FString(request.Keys).ParseIntoArray(KeysArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("Keys"), KeysArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("IfChangedFromDataVersion"), request.IfChangedFromDataVersion);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetCharacterReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetCharacterReadOnlyData.IsBound())
    {
        FServerGetCharacterDataResult result = UPlayFabServerModelDecoder::decodeGetCharacterDataResultResponse(response.responseData);
        OnSuccessGetCharacterReadOnlyData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the title-specific custom data for the user's character which is readable and writable by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterData(FServerUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCharacterData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateCharacterData.IsBound())
    {
        FServerUpdateCharacterDataResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        OnSuccessUpdateCharacterData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the title-specific custom data for the user's character which cannot  be accessed by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterInternalData(FServerUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCharacterInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterInternalData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateCharacterInternalData.IsBound())
    {
        FServerUpdateCharacterDataResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        OnSuccessUpdateCharacterInternalData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Updates the title-specific custom data for the user's character which can only be read by the client */
UPlayFabServerAPI* UPlayFabServerAPI::UpdateCharacterReadOnlyData(FServerUpdateCharacterDataRequest request,
    FDelegateOnSuccessUpdateCharacterReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCharacterReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperUpdateCharacterReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/UpdateCharacterReadOnlyData";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.CharacterId.IsEmpty() || request.CharacterId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CharacterId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CharacterId"), request.CharacterId);
    }
    if (request.Data != nullptr) OutRestJsonObj->SetObjectField(TEXT("Data"), request.Data);
    // Check to see if string is empty
    if (request.KeysToRemove.IsEmpty() || request.KeysToRemove == "") {
        OutRestJsonObj->SetFieldNull(TEXT("KeysToRemove"));
    } else {
        TArray<FString> KeysToRemoveArray;
        FString(request.KeysToRemove).ParseIntoArray(KeysToRemoveArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("KeysToRemove"), KeysToRemoveArray);
    }
    FString temp_Permission;
    if (GetEnumValueToString<EUserDataPermission>(TEXT("EUserDataPermission"), request.Permission, temp_Permission))
        OutRestJsonObj->SetStringField(TEXT("Permission"), temp_Permission);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperUpdateCharacterReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessUpdateCharacterReadOnlyData.IsBound())
    {
        FServerUpdateCharacterDataResult result = UPlayFabServerModelDecoder::decodeUpdateCharacterDataResultResponse(response.responseData);
        OnSuccessUpdateCharacterReadOnlyData.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////
/** Adds a given tag to a player profile. The tag's namespace is automatically generated based on the source of the tag. */
UPlayFabServerAPI* UPlayFabServerAPI::AddPlayerTag(FServerAddPlayerTagRequest request,
    FDelegateOnSuccessAddPlayerTag onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddPlayerTag = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAddPlayerTag);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AddPlayerTag";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.TagName.IsEmpty() || request.TagName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TagName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TagName"), request.TagName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAddPlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAddPlayerTag.IsBound())
    {
        FServerAddPlayerTagResult result = UPlayFabServerModelDecoder::decodeAddPlayerTagResultResponse(response.responseData);
        OnSuccessAddPlayerTag.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieve a list of all PlayStream actions groups. */
UPlayFabServerAPI* UPlayFabServerAPI::GetAllActionGroups(FServerGetAllActionGroupsRequest request,
    FDelegateOnSuccessGetAllActionGroups onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAllActionGroups = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetAllActionGroups);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetAllActionGroups";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetAllActionGroups(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetAllActionGroups.IsBound())
    {
        FServerGetAllActionGroupsResult result = UPlayFabServerModelDecoder::decodeGetAllActionGroupsResultResponse(response.responseData);
        OnSuccessGetAllActionGroups.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Retrieves an array of player segment definitions. Results from this can be used in subsequent API calls such as GetPlayersInSegment which requires a Segment ID. While segment names can change the ID for that segment will not change. */
UPlayFabServerAPI* UPlayFabServerAPI::GetAllSegments(FServerGetAllSegmentsRequest request,
    FDelegateOnSuccessGetAllSegments onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAllSegments = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetAllSegments);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetAllSegments";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetAllSegments(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetAllSegments.IsBound())
    {
        FServerGetAllSegmentsResult result = UPlayFabServerModelDecoder::decodeGetAllSegmentsResultResponse(response.responseData);
        OnSuccessGetAllSegments.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** List all segments that a player currently belongs to at this moment in time. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerSegments(FServerGetPlayersSegmentsRequest request,
    FDelegateOnSuccessGetPlayerSegments onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerSegments = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerSegments);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerSegments";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerSegments(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayerSegments.IsBound())
    {
        FServerGetPlayerSegmentsResult result = UPlayFabServerModelDecoder::decodeGetPlayerSegmentsResultResponse(response.responseData);
        OnSuccessGetPlayerSegments.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Allows for paging through all players in a given segment. This API creates a snapshot of all player profiles that match the segment definition at the time of its creation and lives through the Total Seconds to Live, refreshing its life span on each subsequent use of the Continuation Token. Profiles that change during the course of paging will not be reflected in the results. AB Test segments are currently not supported by this operation. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayersInSegment(FServerGetPlayersInSegmentRequest request,
    FDelegateOnSuccessGetPlayersInSegment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayersInSegment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayersInSegment);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayersInSegment";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SegmentId.IsEmpty() || request.SegmentId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SegmentId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SegmentId"), request.SegmentId);
    }
    OutRestJsonObj->SetNumberField(TEXT("SecondsToLive"), request.SecondsToLive);
    OutRestJsonObj->SetNumberField(TEXT("MaxBatchSize"), request.MaxBatchSize);
    if (request.ContinuationToken.IsEmpty() || request.ContinuationToken == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContinuationToken"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContinuationToken"), request.ContinuationToken);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayersInSegment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayersInSegment.IsBound())
    {
        FServerGetPlayersInSegmentResult result = UPlayFabServerModelDecoder::decodeGetPlayersInSegmentResultResponse(response.responseData);
        OnSuccessGetPlayersInSegment.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Get all tags with a given Namespace (optional) from a player profile. */
UPlayFabServerAPI* UPlayFabServerAPI::GetPlayerTags(FServerGetPlayerTagsRequest request,
    FDelegateOnSuccessGetPlayerTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperGetPlayerTags);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/GetPlayerTags";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Namespace.IsEmpty() || request.Namespace == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Namespace"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Namespace"), request.Namespace);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperGetPlayerTags(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessGetPlayerTags.IsBound())
    {
        FServerGetPlayerTagsResult result = UPlayFabServerModelDecoder::decodeGetPlayerTagsResultResponse(response.responseData);
        OnSuccessGetPlayerTags.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}

/** Remove a given tag from a player profile. The tag's namespace is automatically generated based on the source of the tag. */
UPlayFabServerAPI* UPlayFabServerAPI::RemovePlayerTag(FServerRemovePlayerTagRequest request,
    FDelegateOnSuccessRemovePlayerTag onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemovePlayerTag = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperRemovePlayerTag);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/RemovePlayerTag";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.TagName.IsEmpty() || request.TagName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TagName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TagName"), request.TagName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperRemovePlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessRemovePlayerTag.IsBound())
    {
        FServerRemovePlayerTagResult result = UPlayFabServerModelDecoder::decodeRemovePlayerTagResultResponse(response.responseData);
        OnSuccessRemovePlayerTag.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}


///////////////////////////////////////////////////////
// Platform Specific Methods
//////////////////////////////////////////////////////
/** Awards the specified users the specified Steam achievements */
UPlayFabServerAPI* UPlayFabServerAPI::AwardSteamAchievement(FServerAwardSteamAchievementRequest request,
    FDelegateOnSuccessAwardSteamAchievement onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabServerAPI* manager = NewObject<UPlayFabServerAPI>();
    if (manager->IsSafeForRootSet()) manager->AddToRoot();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAwardSteamAchievement = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabServerAPI::HelperAwardSteamAchievement);

    // Setup the request
    manager->PlayFabRequestURL = "/Server/AwardSteamAchievement";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Achievements.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Achievements"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Achievements"), request.Achievements);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabServerRequestCompleted
void UPlayFabServerAPI::HelperAwardSteamAchievement(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError && OnFailure.IsBound())
    {
        OnFailure.Execute(error, customData);
    }
    else if (!error.hasError && OnSuccessAwardSteamAchievement.IsBound())
    {
        FServerAwardSteamAchievementResult result = UPlayFabServerModelDecoder::decodeAwardSteamAchievementResultResponse(response.responseData);
        OnSuccessAwardSteamAchievement.Execute(result, mCustomData);
    }
    this->RemoveFromRoot();
}



void UPlayFabServerAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    // Be sure that we have no data from previous response
    ResetResponseData();

    if (!IsValidLowLevel())
    {
        UE_LOG(LogPlayFab, Error, TEXT("The request object is invalid during OnProcessRequestComplete."));
        return;
    }
    if (!OnPlayFabResponse.IsBound())
    {
        UE_LOG(LogPlayFab, Error, TEXT("OnPlayFabResponse has come un-bound during OnProcessRequestComplete."));
        return;
    }

    FPlayFabBaseModel myResponse;

    // Check we have result to process further
    if (!bWasSuccessful)
    {
        UE_LOG(LogPlayFab, Error, TEXT("Request failed: %s"), *Request->GetURL());

        // Broadcast the result event
        myResponse.responseError.hasError = true;
        myResponse.responseError.ErrorCode = 503;
        myResponse.responseError.ErrorName = "Unable to contact server";
        myResponse.responseError.ErrorMessage = "Unable to contact server";

        OnPlayFabResponse.Broadcast(myResponse, mCustomData, false);

        return;
    }

    // Save response data as a string
    ResponseContent = Response->GetContentAsString();

    // Save response code as int32
    ResponseCode = Response->GetResponseCode();

    // Try to deserialize data to JSON
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);
    FJsonSerializer::Deserialize(JsonReader, ResponseJsonObj->GetRootObject());

    // Decide whether the request was successful
    bIsValidJsonResponse = bWasSuccessful && ResponseJsonObj->GetRootObject().IsValid();

    // Log errors
    if (!bIsValidJsonResponse)
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabServerAPI::Activate()
{
    IPlayFab* pfSettings = &(IPlayFab::Get());

    FString RequestUrl;
    RequestUrl = TEXT("https://") + pfSettings->getGameTitleId() + IPlayFab::PlayFabURL + PlayFabRequestURL;

    TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
    HttpRequest->SetURL(RequestUrl);
    HttpRequest->SetVerb("POST");

    // Headers
    if (useSessionTicket)
        HttpRequest->SetHeader("X-Authentication", pfSettings->getSessionTicket());
    if (useSecretKey)
        HttpRequest->SetHeader("X-SecretKey", pfSettings->getSecretApiKey());
    HttpRequest->SetHeader("Content-Type", "application/json");
    HttpRequest->SetHeader(TEXT("X-PlayFabSDK"), pfSettings->VersionString);
    HttpRequest->SetHeader("X-ReportErrorAsSuccess", "true"); // FHttpResponsePtr doesn't provide sufficient information when an error code is returned
    for (TMap<FString, FString>::TConstIterator It(RequestHeaders); It; ++It)
        HttpRequest->SetHeader(It.Key(), It.Value());

    // Serialize data to json string
    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(RequestJsonObj->GetRootObject().ToSharedRef(), Writer);

    // Set Json content
    HttpRequest->SetContentAsString(OutputString);

    UE_LOG(LogPlayFab, Log, TEXT("Request: %s"), *OutputString);

    // Bind event
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabServerAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabServerAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
        ResponseJsonObj->Reset();
    else
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    bIsValidJsonResponse = false;
}
