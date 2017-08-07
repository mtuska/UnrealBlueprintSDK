//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated cpp file for the UE4 PlayFab plugin.
//
// API: Admin
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabPrivatePCH.h"
#include "PlayFabEnums.h"
#include "PlayFabAdminAPI.h"

UPlayFabAdminAPI::UPlayFabAdminAPI(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UPlayFabAdminAPI::SetRequestObject(UPlayFabJsonObject* JsonObject)
{
    RequestJsonObj = JsonObject;
}

UPlayFabJsonObject* UPlayFabAdminAPI::GetResponseObject()
{
    return ResponseJsonObj;
}

FString UPlayFabAdminAPI::PercentEncode(const FString& Text)
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
// Generated PlayFab Admin API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////
/** Creates a new Player Shared Secret Key. It may take up to 5 minutes for this key to become generally available after this API returns. */
UPlayFabAdminAPI* UPlayFabAdminAPI::CreatePlayerSharedSecret(FAdminCreatePlayerSharedSecretRequest request,
    FDelegateOnSuccessCreatePlayerSharedSecret onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreatePlayerSharedSecret = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperCreatePlayerSharedSecret);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/CreatePlayerSharedSecret";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.FriendlyName.IsEmpty() || request.FriendlyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendlyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendlyName"), request.FriendlyName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperCreatePlayerSharedSecret(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminCreatePlayerSharedSecretResult result = UPlayFabAdminModelDecoder::decodeCreatePlayerSharedSecretResultResponse(response.responseData);
        if (OnSuccessCreatePlayerSharedSecret.IsBound())
        {
            OnSuccessCreatePlayerSharedSecret.Execute(result, mCustomData);
        }
    }
}

/** Deletes an existing Player Shared Secret Key. It may take up to 5 minutes for this delete to be reflected after this API returns. */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeletePlayerSharedSecret(FAdminDeletePlayerSharedSecretRequest request,
    FDelegateOnSuccessDeletePlayerSharedSecret onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeletePlayerSharedSecret = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeletePlayerSharedSecret);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeletePlayerSharedSecret";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SecretKey.IsEmpty() || request.SecretKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SecretKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SecretKey"), request.SecretKey);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeletePlayerSharedSecret(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminDeletePlayerSharedSecretResult result = UPlayFabAdminModelDecoder::decodeDeletePlayerSharedSecretResultResponse(response.responseData);
        if (OnSuccessDeletePlayerSharedSecret.IsBound())
        {
            OnSuccessDeletePlayerSharedSecret.Execute(result, mCustomData);
        }
    }
}

/** Returns all Player Shared Secret Keys including disabled and expired. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayerSharedSecrets(FAdminGetPlayerSharedSecretsRequest request,
    FDelegateOnSuccessGetPlayerSharedSecrets onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerSharedSecrets = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayerSharedSecrets);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayerSharedSecrets";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayerSharedSecrets(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPlayerSharedSecretsResult result = UPlayFabAdminModelDecoder::decodeGetPlayerSharedSecretsResultResponse(response.responseData);
        if (OnSuccessGetPlayerSharedSecrets.IsBound())
        {
            OnSuccessGetPlayerSharedSecrets.Execute(result, mCustomData);
        }
    }
}

/** Gets the requested policy. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPolicy(FAdminGetPolicyRequest request,
    FDelegateOnSuccessGetPolicy onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPolicy = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPolicy);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPolicy";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PolicyName.IsEmpty() || request.PolicyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PolicyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PolicyName"), request.PolicyName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPolicy(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPolicyResponse result = UPlayFabAdminModelDecoder::decodeGetPolicyResponseResponse(response.responseData);
        if (OnSuccessGetPolicy.IsBound())
        {
            OnSuccessGetPolicy.Execute(result, mCustomData);
        }
    }
}

/** Sets or resets the player's secret. Player secrets are used to sign API requests. */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetPlayerSecret(FAdminSetPlayerSecretRequest request,
    FDelegateOnSuccessSetPlayerSecret onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetPlayerSecret = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetPlayerSecret);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetPlayerSecret";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetPlayerSecret(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminSetPlayerSecretResult result = UPlayFabAdminModelDecoder::decodeSetPlayerSecretResultResponse(response.responseData);
        if (OnSuccessSetPlayerSecret.IsBound())
        {
            OnSuccessSetPlayerSecret.Execute(result, mCustomData);
        }
    }
}

/** Updates a existing Player Shared Secret Key. It may take up to 5 minutes for this update to become generally available after this API returns. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdatePlayerSharedSecret(FAdminUpdatePlayerSharedSecretRequest request,
    FDelegateOnSuccessUpdatePlayerSharedSecret onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdatePlayerSharedSecret = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdatePlayerSharedSecret);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdatePlayerSharedSecret";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.SecretKey.IsEmpty() || request.SecretKey == "") {
        OutRestJsonObj->SetFieldNull(TEXT("SecretKey"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("SecretKey"), request.SecretKey);
    }
    if (request.FriendlyName.IsEmpty() || request.FriendlyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("FriendlyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("FriendlyName"), request.FriendlyName);
    }
    OutRestJsonObj->SetBoolField(TEXT("Disabled"), request.Disabled);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdatePlayerSharedSecret(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdatePlayerSharedSecretResult result = UPlayFabAdminModelDecoder::decodeUpdatePlayerSharedSecretResultResponse(response.responseData);
        if (OnSuccessUpdatePlayerSharedSecret.IsBound())
        {
            OnSuccessUpdatePlayerSharedSecret.Execute(result, mCustomData);
        }
    }
}

/** Changes a policy for a title */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdatePolicy(FAdminUpdatePolicyRequest request,
    FDelegateOnSuccessUpdatePolicy onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdatePolicy = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdatePolicy);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdatePolicy";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PolicyName.IsEmpty() || request.PolicyName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PolicyName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PolicyName"), request.PolicyName);
    }
    if (request.Statements.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Statements"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Statements"), request.Statements);
    }
    OutRestJsonObj->SetBoolField(TEXT("OverwritePolicy"), request.OverwritePolicy);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdatePolicy(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdatePolicyResponse result = UPlayFabAdminModelDecoder::decodeUpdatePolicyResponseResponse(response.responseData);
        if (OnSuccessUpdatePolicy.IsBound())
        {
            OnSuccessUpdatePolicy.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////
/** Bans users by PlayFab ID with optional IP address, or MAC address for the provided game. */
UPlayFabAdminAPI* UPlayFabAdminAPI::BanUsers(FAdminBanUsersRequest request,
    FDelegateOnSuccessBanUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessBanUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperBanUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/BanUsers";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperBanUsers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminBanUsersResult result = UPlayFabAdminModelDecoder::decodeBanUsersResultResponse(response.responseData);
        if (OnSuccessBanUsers.IsBound())
        {
            OnSuccessBanUsers.Execute(result, mCustomData);
        }
    }
}

/** Removes a user's player account from a title and deletes all associated data */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeletePlayer(FAdminDeletePlayerRequest request,
    FDelegateOnSuccessDeletePlayer onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeletePlayer = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeletePlayer);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeletePlayer";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeletePlayer(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminDeletePlayerResult result = UPlayFabAdminModelDecoder::decodeDeletePlayerResultResponse(response.responseData);
        if (OnSuccessDeletePlayer.IsBound())
        {
            OnSuccessDeletePlayer.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the relevant details for a specified user, based upon a match against a supplied unique identifier */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserAccountInfo(FAdminLookupUserAccountInfoRequest request,
    FDelegateOnSuccessGetUserAccountInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserAccountInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserAccountInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserAccountInfo";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.Email.IsEmpty() || request.Email == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }
    if (request.Username.IsEmpty() || request.Username == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Username"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Username"), request.Username);
    }
    if (request.TitleDisplayName.IsEmpty() || request.TitleDisplayName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TitleDisplayName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TitleDisplayName"), request.TitleDisplayName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserAccountInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminLookupUserAccountInfoResult result = UPlayFabAdminModelDecoder::decodeLookupUserAccountInfoResultResponse(response.responseData);
        if (OnSuccessGetUserAccountInfo.IsBound())
        {
            OnSuccessGetUserAccountInfo.Execute(result, mCustomData);
        }
    }
}

/** Gets all bans for a user. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserBans(FAdminGetUserBansRequest request,
    FDelegateOnSuccessGetUserBans onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserBans = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserBans);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserBans";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserBans(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserBansResult result = UPlayFabAdminModelDecoder::decodeGetUserBansResultResponse(response.responseData);
        if (OnSuccessGetUserBans.IsBound())
        {
            OnSuccessGetUserBans.Execute(result, mCustomData);
        }
    }
}

/** Resets all title-specific information about a particular account, including user data, virtual currency balances, inventory, purchase history, and statistics */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetUsers(FAdminResetUsersRequest request,
    FDelegateOnSuccessResetUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessResetUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperResetUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ResetUsers";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Users.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Users"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Users"), request.Users);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperResetUsers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminBlankResult result = UPlayFabAdminModelDecoder::decodeBlankResultResponse(response.responseData);
        if (OnSuccessResetUsers.IsBound())
        {
            OnSuccessResetUsers.Execute(result, mCustomData);
        }
    }
}

/** Revoke all active bans for a user. */
UPlayFabAdminAPI* UPlayFabAdminAPI::RevokeAllBansForUser(FAdminRevokeAllBansForUserRequest request,
    FDelegateOnSuccessRevokeAllBansForUser onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRevokeAllBansForUser = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRevokeAllBansForUser);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RevokeAllBansForUser";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRevokeAllBansForUser(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminRevokeAllBansForUserResult result = UPlayFabAdminModelDecoder::decodeRevokeAllBansForUserResultResponse(response.responseData);
        if (OnSuccessRevokeAllBansForUser.IsBound())
        {
            OnSuccessRevokeAllBansForUser.Execute(result, mCustomData);
        }
    }
}

/** Revoke all active bans specified with BanId. */
UPlayFabAdminAPI* UPlayFabAdminAPI::RevokeBans(FAdminRevokeBansRequest request,
    FDelegateOnSuccessRevokeBans onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRevokeBans = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRevokeBans);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RevokeBans";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRevokeBans(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminRevokeBansResult result = UPlayFabAdminModelDecoder::decodeRevokeBansResultResponse(response.responseData);
        if (OnSuccessRevokeBans.IsBound())
        {
            OnSuccessRevokeBans.Execute(result, mCustomData);
        }
    }
}

/** Forces an email to be sent to the registered email address for the specified account, with a link allowing the user to change the password */
UPlayFabAdminAPI* UPlayFabAdminAPI::SendAccountRecoveryEmail(FAdminSendAccountRecoveryEmailRequest request,
    FDelegateOnSuccessSendAccountRecoveryEmail onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSendAccountRecoveryEmail = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSendAccountRecoveryEmail);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SendAccountRecoveryEmail";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Email.IsEmpty() || request.Email == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Email"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Email"), request.Email);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSendAccountRecoveryEmail(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminSendAccountRecoveryEmailResult result = UPlayFabAdminModelDecoder::decodeSendAccountRecoveryEmailResultResponse(response.responseData);
        if (OnSuccessSendAccountRecoveryEmail.IsBound())
        {
            OnSuccessSendAccountRecoveryEmail.Execute(result, mCustomData);
        }
    }
}

/** Updates information of a list of existing bans specified with Ban Ids. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateBans(FAdminUpdateBansRequest request,
    FDelegateOnSuccessUpdateBans onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateBans = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateBans);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateBans";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateBans(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateBansResult result = UPlayFabAdminModelDecoder::decodeUpdateBansResultResponse(response.responseData);
        if (OnSuccessUpdateBans.IsBound())
        {
            OnSuccessUpdateBans.Execute(result, mCustomData);
        }
    }
}

/** Updates the title specific display name for a user */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserTitleDisplayName(FAdminUpdateUserTitleDisplayNameRequest request,
    FDelegateOnSuccessUpdateUserTitleDisplayName onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserTitleDisplayName = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserTitleDisplayName);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserTitleDisplayName";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.DisplayName.IsEmpty() || request.DisplayName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DisplayName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DisplayName"), request.DisplayName);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserTitleDisplayName(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateUserTitleDisplayNameResult result = UPlayFabAdminModelDecoder::decodeUpdateUserTitleDisplayNameResultResponse(response.responseData);
        if (OnSuccessUpdateUserTitleDisplayName.IsBound())
        {
            OnSuccessUpdateUserTitleDisplayName.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////
/** Adds a new player statistic configuration to the title, optionally allowing the developer to specify a reset interval and an aggregation method. */
UPlayFabAdminAPI* UPlayFabAdminAPI::CreatePlayerStatisticDefinition(FAdminCreatePlayerStatisticDefinitionRequest request,
    FDelegateOnSuccessCreatePlayerStatisticDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreatePlayerStatisticDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperCreatePlayerStatisticDefinition);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/CreatePlayerStatisticDefinition";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    FString temp_VersionChangeInterval;
    if (GetEnumValueToString<EStatisticResetIntervalOption>(TEXT("EStatisticResetIntervalOption"), request.VersionChangeInterval, temp_VersionChangeInterval))
        OutRestJsonObj->SetStringField(TEXT("VersionChangeInterval"), temp_VersionChangeInterval);
    FString temp_AggregationMethod;
    if (GetEnumValueToString<EStatisticAggregationMethod>(TEXT("EStatisticAggregationMethod"), request.AggregationMethod, temp_AggregationMethod))
        OutRestJsonObj->SetStringField(TEXT("AggregationMethod"), temp_AggregationMethod);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperCreatePlayerStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminCreatePlayerStatisticDefinitionResult result = UPlayFabAdminModelDecoder::decodeCreatePlayerStatisticDefinitionResultResponse(response.responseData);
        if (OnSuccessCreatePlayerStatisticDefinition.IsBound())
        {
            OnSuccessCreatePlayerStatisticDefinition.Execute(result, mCustomData);
        }
    }
}

/** Deletes the users for the provided game. Deletes custom data, all account linkages, and statistics. This method does not remove the player's event history, login history, inventory items, nor virtual currencies. */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteUsers(FAdminDeleteUsersRequest request,
    FDelegateOnSuccessDeleteUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeleteUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeleteUsers";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeleteUsers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminDeleteUsersResult result = UPlayFabAdminModelDecoder::decodeDeleteUsersResultResponse(response.responseData);
        if (OnSuccessDeleteUsers.IsBound())
        {
            OnSuccessDeleteUsers.Execute(result, mCustomData);
        }
    }
}

/** Retrieves a download URL for the requested report */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetDataReport(FAdminGetDataReportRequest request,
    FDelegateOnSuccessGetDataReport onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetDataReport = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetDataReport);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetDataReport";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.ReportName.IsEmpty() || request.ReportName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ReportName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ReportName"), request.ReportName);
    }
    OutRestJsonObj->SetNumberField(TEXT("Year"), request.Year);
    OutRestJsonObj->SetNumberField(TEXT("Month"), request.Month);
    OutRestJsonObj->SetNumberField(TEXT("Day"), request.Day);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetDataReport(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetDataReportResult result = UPlayFabAdminModelDecoder::decodeGetDataReportResultResponse(response.responseData);
        if (OnSuccessGetDataReport.IsBound())
        {
            OnSuccessGetDataReport.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the configuration information for all player statistics defined in the title, regardless of whether they have a reset interval. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayerStatisticDefinitions(FAdminGetPlayerStatisticDefinitionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticDefinitions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticDefinitions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayerStatisticDefinitions);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayerStatisticDefinitions";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayerStatisticDefinitions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPlayerStatisticDefinitionsResult result = UPlayFabAdminModelDecoder::decodeGetPlayerStatisticDefinitionsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatisticDefinitions.IsBound())
        {
            OnSuccessGetPlayerStatisticDefinitions.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the information on the available versions of the specified statistic. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayerStatisticVersions(FAdminGetPlayerStatisticVersionsRequest request,
    FDelegateOnSuccessGetPlayerStatisticVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerStatisticVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayerStatisticVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayerStatisticVersions";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayerStatisticVersions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPlayerStatisticVersionsResult result = UPlayFabAdminModelDecoder::decodeGetPlayerStatisticVersionsResultResponse(response.responseData);
        if (OnSuccessGetPlayerStatisticVersions.IsBound())
        {
            OnSuccessGetPlayerStatisticVersions.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the title-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserData.IsBound())
        {
            OnSuccessGetUserData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserInternalData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserInternalData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserInternalData.IsBound())
        {
            OnSuccessGetUserInternalData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserPublisherData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherData.IsBound())
        {
            OnSuccessGetUserPublisherData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherInternalData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserPublisherInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserPublisherInternalData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherInternalData.IsBound())
        {
            OnSuccessGetUserPublisherInternalData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the publisher-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserPublisherReadOnlyData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserPublisherReadOnlyData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessGetUserPublisherReadOnlyData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the title-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserReadOnlyData(FAdminGetUserDataRequest request,
    FDelegateOnSuccessGetUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserReadOnlyData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserDataResult result = UPlayFabAdminModelDecoder::decodeGetUserDataResultResponse(response.responseData);
        if (OnSuccessGetUserReadOnlyData.IsBound())
        {
            OnSuccessGetUserReadOnlyData.Execute(result, mCustomData);
        }
    }
}

/** Resets the indicated statistic, removing all player entries for it and backing up the old values. */
UPlayFabAdminAPI* UPlayFabAdminAPI::IncrementPlayerStatisticVersion(FAdminIncrementPlayerStatisticVersionRequest request,
    FDelegateOnSuccessIncrementPlayerStatisticVersion onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessIncrementPlayerStatisticVersion = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperIncrementPlayerStatisticVersion);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/IncrementPlayerStatisticVersion";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperIncrementPlayerStatisticVersion(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminIncrementPlayerStatisticVersionResult result = UPlayFabAdminModelDecoder::decodeIncrementPlayerStatisticVersionResultResponse(response.responseData);
        if (OnSuccessIncrementPlayerStatisticVersion.IsBound())
        {
            OnSuccessIncrementPlayerStatisticVersion.Execute(result, mCustomData);
        }
    }
}

/** Attempts to process an order refund through the original real money payment provider. */
UPlayFabAdminAPI* UPlayFabAdminAPI::RefundPurchase(FAdminRefundPurchaseRequest request,
    FDelegateOnSuccessRefundPurchase onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRefundPurchase = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRefundPurchase);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RefundPurchase";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.OrderId.IsEmpty() || request.OrderId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }
    if (request.Reason.IsEmpty() || request.Reason == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Reason"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Reason"), request.Reason);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRefundPurchase(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminRefundPurchaseResponse result = UPlayFabAdminModelDecoder::decodeRefundPurchaseResponseResponse(response.responseData);
        if (OnSuccessRefundPurchase.IsBound())
        {
            OnSuccessRefundPurchase.Execute(result, mCustomData);
        }
    }
}

/** Completely removes all statistics for the specified user, for the current game */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetUserStatistics(FAdminResetUserStatisticsRequest request,
    FDelegateOnSuccessResetUserStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessResetUserStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperResetUserStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ResetUserStatistics";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperResetUserStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminResetUserStatisticsResult result = UPlayFabAdminModelDecoder::decodeResetUserStatisticsResultResponse(response.responseData);
        if (OnSuccessResetUserStatistics.IsBound())
        {
            OnSuccessResetUserStatistics.Execute(result, mCustomData);
        }
    }
}

/** Attempts to resolve a dispute with the original order's payment provider. */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResolvePurchaseDispute(FAdminResolvePurchaseDisputeRequest request,
    FDelegateOnSuccessResolvePurchaseDispute onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessResolvePurchaseDispute = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperResolvePurchaseDispute);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ResolvePurchaseDispute";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.PlayFabId.IsEmpty() || request.PlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("PlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("PlayFabId"), request.PlayFabId);
    }
    if (request.OrderId.IsEmpty() || request.OrderId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("OrderId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("OrderId"), request.OrderId);
    }
    if (request.Reason.IsEmpty() || request.Reason == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Reason"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Reason"), request.Reason);
    }
    FString temp_Outcome;
    if (GetEnumValueToString<EResolutionOutcome>(TEXT("EResolutionOutcome"), request.Outcome, temp_Outcome))
        OutRestJsonObj->SetStringField(TEXT("Outcome"), temp_Outcome);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperResolvePurchaseDispute(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminResolvePurchaseDisputeResponse result = UPlayFabAdminModelDecoder::decodeResolvePurchaseDisputeResponseResponse(response.responseData);
        if (OnSuccessResolvePurchaseDispute.IsBound())
        {
            OnSuccessResolvePurchaseDispute.Execute(result, mCustomData);
        }
    }
}

/** Updates a player statistic configuration for the title, optionally allowing the developer to specify a reset interval. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdatePlayerStatisticDefinition(FAdminUpdatePlayerStatisticDefinitionRequest request,
    FDelegateOnSuccessUpdatePlayerStatisticDefinition onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdatePlayerStatisticDefinition = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdatePlayerStatisticDefinition);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdatePlayerStatisticDefinition";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.StatisticName.IsEmpty() || request.StatisticName == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StatisticName"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StatisticName"), request.StatisticName);
    }
    FString temp_VersionChangeInterval;
    if (GetEnumValueToString<EStatisticResetIntervalOption>(TEXT("EStatisticResetIntervalOption"), request.VersionChangeInterval, temp_VersionChangeInterval))
        OutRestJsonObj->SetStringField(TEXT("VersionChangeInterval"), temp_VersionChangeInterval);
    FString temp_AggregationMethod;
    if (GetEnumValueToString<EStatisticAggregationMethod>(TEXT("EStatisticAggregationMethod"), request.AggregationMethod, temp_AggregationMethod))
        OutRestJsonObj->SetStringField(TEXT("AggregationMethod"), temp_AggregationMethod);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdatePlayerStatisticDefinition(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdatePlayerStatisticDefinitionResult result = UPlayFabAdminModelDecoder::decodeUpdatePlayerStatisticDefinitionResultResponse(response.responseData);
        if (OnSuccessUpdatePlayerStatisticDefinition.IsBound())
        {
            OnSuccessUpdatePlayerStatisticDefinition.Execute(result, mCustomData);
        }
    }
}

/** Updates the title-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserData.IsBound())
        {
            OnSuccessUpdateUserData.Execute(result, mCustomData);
        }
    }
}

/** Updates the title-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserInternalData(FAdminUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserInternalData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserInternalData.IsBound())
        {
            OnSuccessUpdateUserInternalData.Execute(result, mCustomData);
        }
    }
}

/** Updates the publisher-specific custom data for the user which is readable and writable by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserPublisherData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherData.IsBound())
        {
            OnSuccessUpdateUserPublisherData.Execute(result, mCustomData);
        }
    }
}

/** Updates the publisher-specific custom data for the user which cannot be accessed by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherInternalData(FAdminUpdateUserInternalDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserPublisherInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserPublisherInternalData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserPublisherInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherInternalData.IsBound())
        {
            OnSuccessUpdateUserPublisherInternalData.Execute(result, mCustomData);
        }
    }
}

/** Updates the publisher-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserPublisherReadOnlyData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserPublisherReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserPublisherReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserPublisherReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserPublisherReadOnlyData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserPublisherReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserPublisherReadOnlyData.IsBound())
        {
            OnSuccessUpdateUserPublisherReadOnlyData.Execute(result, mCustomData);
        }
    }
}

/** Updates the title-specific custom data for the user which can only be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateUserReadOnlyData(FAdminUpdateUserDataRequest request,
    FDelegateOnSuccessUpdateUserReadOnlyData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateUserReadOnlyData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateUserReadOnlyData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateUserReadOnlyData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateUserReadOnlyData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateUserDataResult result = UPlayFabAdminModelDecoder::decodeUpdateUserDataResultResponse(response.responseData);
        if (OnSuccessUpdateUserReadOnlyData.IsBound())
        {
            OnSuccessUpdateUserReadOnlyData.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////
/** Adds a new news item to the title's news feed */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddNews(FAdminAddNewsRequest request,
    FDelegateOnSuccessAddNews onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddNews = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddNews);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddNews";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    if (request.Title.IsEmpty() || request.Title == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Title"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Title"), request.Title);
    }
    if (request.Body.IsEmpty() || request.Body == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Body"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Body"), request.Body);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddNews(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminAddNewsResult result = UPlayFabAdminModelDecoder::decodeAddNewsResultResponse(response.responseData);
        if (OnSuccessAddNews.IsBound())
        {
            OnSuccessAddNews.Execute(result, mCustomData);
        }
    }
}

/** Adds one or more virtual currencies to the set defined for the title. Virtual Currencies have a maximum value of 2,147,483,647 when granted to a player. Any value over that will be discarded. */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddVirtualCurrencyTypes(FAdminAddVirtualCurrencyTypesRequest request,
    FDelegateOnSuccessAddVirtualCurrencyTypes onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddVirtualCurrencyTypes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddVirtualCurrencyTypes);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddVirtualCurrencyTypes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.VirtualCurrencies.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrencies"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("VirtualCurrencies"), request.VirtualCurrencies);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddVirtualCurrencyTypes(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminBlankResult result = UPlayFabAdminModelDecoder::decodeBlankResultResponse(response.responseData);
        if (OnSuccessAddVirtualCurrencyTypes.IsBound())
        {
            OnSuccessAddVirtualCurrencyTypes.Execute(result, mCustomData);
        }
    }
}

/** Deletes an existing virtual item store */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteStore(FAdminDeleteStoreRequest request,
    FDelegateOnSuccessDeleteStore onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteStore = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeleteStore);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeleteStore";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeleteStore(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminDeleteStoreResult result = UPlayFabAdminModelDecoder::decodeDeleteStoreResultResponse(response.responseData);
        if (OnSuccessDeleteStore.IsBound())
        {
            OnSuccessDeleteStore.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the specified version of the title's catalog of virtual goods, including all defined properties */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCatalogItems(FAdminGetCatalogItemsRequest request,
    FDelegateOnSuccessGetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetCatalogItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCatalogItems";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetCatalogItemsResult result = UPlayFabAdminModelDecoder::decodeGetCatalogItemsResultResponse(response.responseData);
        if (OnSuccessGetCatalogItems.IsBound())
        {
            OnSuccessGetCatalogItems.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the key-value store of custom publisher settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPublisherData(FAdminGetPublisherDataRequest request,
    FDelegateOnSuccessGetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPublisherData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPublisherDataResult result = UPlayFabAdminModelDecoder::decodeGetPublisherDataResultResponse(response.responseData);
        if (OnSuccessGetPublisherData.IsBound())
        {
            OnSuccessGetPublisherData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the random drop table configuration for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetRandomResultTables(FAdminGetRandomResultTablesRequest request,
    FDelegateOnSuccessGetRandomResultTables onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetRandomResultTables = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetRandomResultTables);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetRandomResultTables";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetRandomResultTables(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetRandomResultTablesResult result = UPlayFabAdminModelDecoder::decodeGetRandomResultTablesResultResponse(response.responseData);
        if (OnSuccessGetRandomResultTables.IsBound())
        {
            OnSuccessGetRandomResultTables.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the set of items defined for the specified store, including all prices defined */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetStoreItems(FAdminGetStoreItemsRequest request,
    FDelegateOnSuccessGetStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetStoreItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetStoreItems";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetStoreItemsResult result = UPlayFabAdminModelDecoder::decodeGetStoreItemsResultResponse(response.responseData);
        if (OnSuccessGetStoreItems.IsBound())
        {
            OnSuccessGetStoreItems.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the key-value store of custom title settings which can be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetTitleData(FAdminGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetTitleData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetTitleDataResult result = UPlayFabAdminModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        if (OnSuccessGetTitleData.IsBound())
        {
            OnSuccessGetTitleData.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the key-value store of custom title settings which cannot be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetTitleInternalData(FAdminGetTitleDataRequest request,
    FDelegateOnSuccessGetTitleInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTitleInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetTitleInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetTitleInternalData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetTitleDataResult result = UPlayFabAdminModelDecoder::decodeGetTitleDataResultResponse(response.responseData);
        if (OnSuccessGetTitleInternalData.IsBound())
        {
            OnSuccessGetTitleInternalData.Execute(result, mCustomData);
        }
    }
}

/** Retuns the list of all defined virtual currencies for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::ListVirtualCurrencyTypes(FAdminListVirtualCurrencyTypesRequest request,
    FDelegateOnSuccessListVirtualCurrencyTypes onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListVirtualCurrencyTypes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperListVirtualCurrencyTypes);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ListVirtualCurrencyTypes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperListVirtualCurrencyTypes(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminListVirtualCurrencyTypesResult result = UPlayFabAdminModelDecoder::decodeListVirtualCurrencyTypesResultResponse(response.responseData);
        if (OnSuccessListVirtualCurrencyTypes.IsBound())
        {
            OnSuccessListVirtualCurrencyTypes.Execute(result, mCustomData);
        }
    }
}

/** Removes one or more virtual currencies from the set defined for the title. */
UPlayFabAdminAPI* UPlayFabAdminAPI::RemoveVirtualCurrencyTypes(FAdminRemoveVirtualCurrencyTypesRequest request,
    FDelegateOnSuccessRemoveVirtualCurrencyTypes onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveVirtualCurrencyTypes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRemoveVirtualCurrencyTypes);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RemoveVirtualCurrencyTypes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.VirtualCurrencies.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("VirtualCurrencies"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("VirtualCurrencies"), request.VirtualCurrencies);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRemoveVirtualCurrencyTypes(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminBlankResult result = UPlayFabAdminModelDecoder::decodeBlankResultResponse(response.responseData);
        if (OnSuccessRemoveVirtualCurrencyTypes.IsBound())
        {
            OnSuccessRemoveVirtualCurrencyTypes.Execute(result, mCustomData);
        }
    }
}

/** Creates the catalog configuration of all virtual goods for the specified catalog version */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetCatalogItems(FAdminUpdateCatalogItemsRequest request,
    FDelegateOnSuccessSetCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetCatalogItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetCatalogItems";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    OutRestJsonObj->SetBoolField(TEXT("SetAsDefaultCatalog"), request.SetAsDefaultCatalog);
    if (request.Catalog.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Catalog"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Catalog"), request.Catalog);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateCatalogItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateCatalogItemsResultResponse(response.responseData);
        if (OnSuccessSetCatalogItems.IsBound())
        {
            OnSuccessSetCatalogItems.Execute(result, mCustomData);
        }
    }
}

/** Sets all the items in one virtual store */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetStoreItems(FAdminUpdateStoreItemsRequest request,
    FDelegateOnSuccessSetStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetStoreItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetStoreItems";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }
    if (request.MarketingData != nullptr) OutRestJsonObj->SetObjectField(TEXT("MarketingData"), request.MarketingData);
    if (request.Store.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Store"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Store"), request.Store);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateStoreItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateStoreItemsResultResponse(response.responseData);
        if (OnSuccessSetStoreItems.IsBound())
        {
            OnSuccessSetStoreItems.Execute(result, mCustomData);
        }
    }
}

/** Creates and updates the key-value store of custom title settings which can be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetTitleData(FAdminSetTitleDataRequest request,
    FDelegateOnSuccessSetTitleData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetTitleData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetTitleData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetTitleData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetTitleData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminSetTitleDataResult result = UPlayFabAdminModelDecoder::decodeSetTitleDataResultResponse(response.responseData);
        if (OnSuccessSetTitleData.IsBound())
        {
            OnSuccessSetTitleData.Execute(result, mCustomData);
        }
    }
}

/** Updates the key-value store of custom title settings which cannot be read by the client */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetTitleInternalData(FAdminSetTitleDataRequest request,
    FDelegateOnSuccessSetTitleInternalData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetTitleInternalData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetTitleInternalData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetTitleInternalData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetTitleInternalData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminSetTitleDataResult result = UPlayFabAdminModelDecoder::decodeSetTitleDataResultResponse(response.responseData);
        if (OnSuccessSetTitleInternalData.IsBound())
        {
            OnSuccessSetTitleInternalData.Execute(result, mCustomData);
        }
    }
}

/** Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the exact restrictions can be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html. Currently, Amazon device Messaging is not supported. */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetupPushNotification(FAdminSetupPushNotificationRequest request,
    FDelegateOnSuccessSetupPushNotification onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetupPushNotification = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetupPushNotification);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetupPushNotification";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    FString temp_Platform;
    if (GetEnumValueToString<EPushSetupPlatform>(TEXT("EPushSetupPlatform"), request.Platform, temp_Platform))
        OutRestJsonObj->SetStringField(TEXT("Platform"), temp_Platform);
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }
    if (request.Credential.IsEmpty() || request.Credential == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Credential"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Credential"), request.Credential);
    }
    OutRestJsonObj->SetBoolField(TEXT("OverwriteOldARN"), request.OverwriteOldARN);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetupPushNotification(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminSetupPushNotificationResult result = UPlayFabAdminModelDecoder::decodeSetupPushNotificationResultResponse(response.responseData);
        if (OnSuccessSetupPushNotification.IsBound())
        {
            OnSuccessSetupPushNotification.Execute(result, mCustomData);
        }
    }
}

/** Updates the catalog configuration for virtual goods in the specified catalog version */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateCatalogItems(FAdminUpdateCatalogItemsRequest request,
    FDelegateOnSuccessUpdateCatalogItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCatalogItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateCatalogItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateCatalogItems";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    OutRestJsonObj->SetBoolField(TEXT("SetAsDefaultCatalog"), request.SetAsDefaultCatalog);
    if (request.Catalog.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Catalog"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Catalog"), request.Catalog);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateCatalogItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateCatalogItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateCatalogItemsResultResponse(response.responseData);
        if (OnSuccessUpdateCatalogItems.IsBound())
        {
            OnSuccessUpdateCatalogItems.Execute(result, mCustomData);
        }
    }
}

/** Updates the random drop table configuration for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateRandomResultTables(FAdminUpdateRandomResultTablesRequest request,
    FDelegateOnSuccessUpdateRandomResultTables onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateRandomResultTables = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateRandomResultTables);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateRandomResultTables";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.Tables.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Tables"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Tables"), request.Tables);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateRandomResultTables(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateRandomResultTablesResult result = UPlayFabAdminModelDecoder::decodeUpdateRandomResultTablesResultResponse(response.responseData);
        if (OnSuccessUpdateRandomResultTables.IsBound())
        {
            OnSuccessUpdateRandomResultTables.Execute(result, mCustomData);
        }
    }
}

/** Updates an existing virtual item store with new or modified items */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateStoreItems(FAdminUpdateStoreItemsRequest request,
    FDelegateOnSuccessUpdateStoreItems onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateStoreItems = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateStoreItems);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateStoreItems";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.CatalogVersion.IsEmpty() || request.CatalogVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CatalogVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CatalogVersion"), request.CatalogVersion);
    }
    if (request.StoreId.IsEmpty() || request.StoreId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StoreId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StoreId"), request.StoreId);
    }
    if (request.MarketingData != nullptr) OutRestJsonObj->SetObjectField(TEXT("MarketingData"), request.MarketingData);
    if (request.Store.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Store"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Store"), request.Store);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateStoreItems(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateStoreItemsResult result = UPlayFabAdminModelDecoder::decodeUpdateStoreItemsResultResponse(response.responseData);
        if (OnSuccessUpdateStoreItems.IsBound())
        {
            OnSuccessUpdateStoreItems.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////
/** Increments the specified virtual currency by the stated amount */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddUserVirtualCurrency(FAdminAddUserVirtualCurrencyRequest request,
    FDelegateOnSuccessAddUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddUserVirtualCurrency";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminModifyUserVirtualCurrencyResult result = UPlayFabAdminModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessAddUserVirtualCurrency.IsBound())
        {
            OnSuccessAddUserVirtualCurrency.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the specified user's current inventory of virtual goods */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetUserInventory(FAdminGetUserInventoryRequest request,
    FDelegateOnSuccessGetUserInventory onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetUserInventory = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetUserInventory);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetUserInventory";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetUserInventory(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetUserInventoryResult result = UPlayFabAdminModelDecoder::decodeGetUserInventoryResultResponse(response.responseData);
        if (OnSuccessGetUserInventory.IsBound())
        {
            OnSuccessGetUserInventory.Execute(result, mCustomData);
        }
    }
}

/** Adds the specified items to the specified user inventories */
UPlayFabAdminAPI* UPlayFabAdminAPI::GrantItemsToUsers(FAdminGrantItemsToUsersRequest request,
    FDelegateOnSuccessGrantItemsToUsers onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGrantItemsToUsers = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGrantItemsToUsers);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GrantItemsToUsers";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGrantItemsToUsers(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGrantItemsToUsersResult result = UPlayFabAdminModelDecoder::decodeGrantItemsToUsersResultResponse(response.responseData);
        if (OnSuccessGrantItemsToUsers.IsBound())
        {
            OnSuccessGrantItemsToUsers.Execute(result, mCustomData);
        }
    }
}

/** Revokes access to an item in a user's inventory */
UPlayFabAdminAPI* UPlayFabAdminAPI::RevokeInventoryItem(FAdminRevokeInventoryItemRequest request,
    FDelegateOnSuccessRevokeInventoryItem onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRevokeInventoryItem = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRevokeInventoryItem);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RevokeInventoryItem";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRevokeInventoryItem(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminRevokeInventoryResult result = UPlayFabAdminModelDecoder::decodeRevokeInventoryResultResponse(response.responseData);
        if (OnSuccessRevokeInventoryItem.IsBound())
        {
            OnSuccessRevokeInventoryItem.Execute(result, mCustomData);
        }
    }
}

/** Decrements the specified virtual currency by the stated amount */
UPlayFabAdminAPI* UPlayFabAdminAPI::SubtractUserVirtualCurrency(FAdminSubtractUserVirtualCurrencyRequest request,
    FDelegateOnSuccessSubtractUserVirtualCurrency onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSubtractUserVirtualCurrency = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSubtractUserVirtualCurrency);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SubtractUserVirtualCurrency";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSubtractUserVirtualCurrency(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminModifyUserVirtualCurrencyResult result = UPlayFabAdminModelDecoder::decodeModifyUserVirtualCurrencyResultResponse(response.responseData);
        if (OnSuccessSubtractUserVirtualCurrency.IsBound())
        {
            OnSuccessSubtractUserVirtualCurrency.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////
/** Retrieves the details for a specific completed session, including links to standard out and standard error logs */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetMatchmakerGameInfo(FAdminGetMatchmakerGameInfoRequest request,
    FDelegateOnSuccessGetMatchmakerGameInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetMatchmakerGameInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetMatchmakerGameInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetMatchmakerGameInfo";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetMatchmakerGameInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetMatchmakerGameInfoResult result = UPlayFabAdminModelDecoder::decodeGetMatchmakerGameInfoResultResponse(response.responseData);
        if (OnSuccessGetMatchmakerGameInfo.IsBound())
        {
            OnSuccessGetMatchmakerGameInfo.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the details of defined game modes for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetMatchmakerGameModes(FAdminGetMatchmakerGameModesRequest request,
    FDelegateOnSuccessGetMatchmakerGameModes onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetMatchmakerGameModes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetMatchmakerGameModes);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetMatchmakerGameModes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetMatchmakerGameModes(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetMatchmakerGameModesResult result = UPlayFabAdminModelDecoder::decodeGetMatchmakerGameModesResultResponse(response.responseData);
        if (OnSuccessGetMatchmakerGameModes.IsBound())
        {
            OnSuccessGetMatchmakerGameModes.Execute(result, mCustomData);
        }
    }
}

/** Updates the game server mode details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::ModifyMatchmakerGameModes(FAdminModifyMatchmakerGameModesRequest request,
    FDelegateOnSuccessModifyMatchmakerGameModes onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessModifyMatchmakerGameModes = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperModifyMatchmakerGameModes);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ModifyMatchmakerGameModes";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.BuildVersion.IsEmpty() || request.BuildVersion == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildVersion"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildVersion"), request.BuildVersion);
    }
    if (request.GameModes.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("GameModes"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("GameModes"), request.GameModes);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperModifyMatchmakerGameModes(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminModifyMatchmakerGameModesResult result = UPlayFabAdminModelDecoder::decodeModifyMatchmakerGameModesResultResponse(response.responseData);
        if (OnSuccessModifyMatchmakerGameModes.IsBound())
        {
            OnSuccessModifyMatchmakerGameModes.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Custom Server Management
//////////////////////////////////////////////////////
/** Adds the game server executable specified (previously uploaded - see GetServerBuildUploadUrl) to the set of those a client is permitted to request in a call to StartGame */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddServerBuild(FAdminAddServerBuildRequest request,
    FDelegateOnSuccessAddServerBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddServerBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddServerBuild);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddServerBuild";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.CommandLineTemplate.IsEmpty() || request.CommandLineTemplate == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CommandLineTemplate"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CommandLineTemplate"), request.CommandLineTemplate);
    }
    if (request.ExecutablePath.IsEmpty() || request.ExecutablePath == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExecutablePath"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExecutablePath"), request.ExecutablePath);
    }
    // Check to see if string is empty
    if (request.ActiveRegions.IsEmpty() || request.ActiveRegions == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ActiveRegions"));
    } else {
        TArray<FString> ActiveRegionsArray;
        FString(request.ActiveRegions).ParseIntoArray(ActiveRegionsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ActiveRegions"), ActiveRegionsArray);
    }
    if (request.Comment.IsEmpty() || request.Comment == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Comment"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Comment"), request.Comment);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxGamesPerHost"), request.MaxGamesPerHost);
    OutRestJsonObj->SetNumberField(TEXT("MinFreeGameSlots"), request.MinFreeGameSlots);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddServerBuild(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminAddServerBuildResult result = UPlayFabAdminModelDecoder::decodeAddServerBuildResultResponse(response.responseData);
        if (OnSuccessAddServerBuild.IsBound())
        {
            OnSuccessAddServerBuild.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the build details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetServerBuildInfo(FAdminGetServerBuildInfoRequest request,
    FDelegateOnSuccessGetServerBuildInfo onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetServerBuildInfo = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetServerBuildInfo);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetServerBuildInfo";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetServerBuildInfo(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetServerBuildInfoResult result = UPlayFabAdminModelDecoder::decodeGetServerBuildInfoResultResponse(response.responseData);
        if (OnSuccessGetServerBuildInfo.IsBound())
        {
            OnSuccessGetServerBuildInfo.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the pre-authorized URL for uploading a game server package containing a build (does not enable the build for use - see AddServerBuild) */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetServerBuildUploadUrl(FAdminGetServerBuildUploadURLRequest request,
    FDelegateOnSuccessGetServerBuildUploadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetServerBuildUploadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetServerBuildUploadUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetServerBuildUploadUrl";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetServerBuildUploadUrl(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetServerBuildUploadURLResult result = UPlayFabAdminModelDecoder::decodeGetServerBuildUploadURLResultResponse(response.responseData);
        if (OnSuccessGetServerBuildUploadUrl.IsBound())
        {
            OnSuccessGetServerBuildUploadUrl.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the build details for all game server executables which are currently defined for the title */
UPlayFabAdminAPI* UPlayFabAdminAPI::ListServerBuilds(FAdminListBuildsRequest request,
    FDelegateOnSuccessListServerBuilds onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessListServerBuilds = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperListServerBuilds);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ListServerBuilds";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperListServerBuilds(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminListBuildsResult result = UPlayFabAdminModelDecoder::decodeListBuildsResultResponse(response.responseData);
        if (OnSuccessListServerBuilds.IsBound())
        {
            OnSuccessListServerBuilds.Execute(result, mCustomData);
        }
    }
}

/** Updates the build details for the specified game server executable */
UPlayFabAdminAPI* UPlayFabAdminAPI::ModifyServerBuild(FAdminModifyServerBuildRequest request,
    FDelegateOnSuccessModifyServerBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessModifyServerBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperModifyServerBuild);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ModifyServerBuild";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }
    if (request.Timestamp.IsEmpty() || request.Timestamp == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Timestamp"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Timestamp"), request.Timestamp);
    }
    // Check to see if string is empty
    if (request.ActiveRegions.IsEmpty() || request.ActiveRegions == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ActiveRegions"));
    } else {
        TArray<FString> ActiveRegionsArray;
        FString(request.ActiveRegions).ParseIntoArray(ActiveRegionsArray, TEXT(","), false);
        OutRestJsonObj->SetStringArrayField(TEXT("ActiveRegions"), ActiveRegionsArray);
    }
    OutRestJsonObj->SetNumberField(TEXT("MaxGamesPerHost"), request.MaxGamesPerHost);
    OutRestJsonObj->SetNumberField(TEXT("MinFreeGameSlots"), request.MinFreeGameSlots);
    if (request.CommandLineTemplate.IsEmpty() || request.CommandLineTemplate == "") {
        OutRestJsonObj->SetFieldNull(TEXT("CommandLineTemplate"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("CommandLineTemplate"), request.CommandLineTemplate);
    }
    if (request.ExecutablePath.IsEmpty() || request.ExecutablePath == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ExecutablePath"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ExecutablePath"), request.ExecutablePath);
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperModifyServerBuild(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminModifyServerBuildResult result = UPlayFabAdminModelDecoder::decodeModifyServerBuildResultResponse(response.responseData);
        if (OnSuccessModifyServerBuild.IsBound())
        {
            OnSuccessModifyServerBuild.Execute(result, mCustomData);
        }
    }
}

/** Removes the game server executable specified from the set of those a client is permitted to request in a call to StartGame */
UPlayFabAdminAPI* UPlayFabAdminAPI::RemoveServerBuild(FAdminRemoveServerBuildRequest request,
    FDelegateOnSuccessRemoveServerBuild onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemoveServerBuild = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRemoveServerBuild);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RemoveServerBuild";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.BuildId.IsEmpty() || request.BuildId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("BuildId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("BuildId"), request.BuildId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRemoveServerBuild(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminRemoveServerBuildResult result = UPlayFabAdminModelDecoder::decodeRemoveServerBuildResultResponse(response.responseData);
        if (OnSuccessRemoveServerBuild.IsBound())
        {
            OnSuccessRemoveServerBuild.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////
/** Updates the key-value store of custom publisher settings */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetPublisherData(FAdminSetPublisherDataRequest request,
    FDelegateOnSuccessSetPublisherData onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetPublisherData = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetPublisherData);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetPublisherData";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetPublisherData(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminSetPublisherDataResult result = UPlayFabAdminModelDecoder::decodeSetPublisherDataResultResponse(response.responseData);
        if (OnSuccessSetPublisherData.IsBound())
        {
            OnSuccessSetPublisherData.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////
/** Gets the contents and information of a specific Cloud Script revision. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCloudScriptRevision(FAdminGetCloudScriptRevisionRequest request,
    FDelegateOnSuccessGetCloudScriptRevision onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCloudScriptRevision = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetCloudScriptRevision);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCloudScriptRevision";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetNumberField(TEXT("Revision"), request.Revision);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetCloudScriptRevision(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetCloudScriptRevisionResult result = UPlayFabAdminModelDecoder::decodeGetCloudScriptRevisionResultResponse(response.responseData);
        if (OnSuccessGetCloudScriptRevision.IsBound())
        {
            OnSuccessGetCloudScriptRevision.Execute(result, mCustomData);
        }
    }
}

/** Lists all the current cloud script versions. For each version, information about the current published and latest revisions is also listed. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCloudScriptVersions(FAdminGetCloudScriptVersionsRequest request,
    FDelegateOnSuccessGetCloudScriptVersions onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCloudScriptVersions = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetCloudScriptVersions);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCloudScriptVersions";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetCloudScriptVersions(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetCloudScriptVersionsResult result = UPlayFabAdminModelDecoder::decodeGetCloudScriptVersionsResultResponse(response.responseData);
        if (OnSuccessGetCloudScriptVersions.IsBound())
        {
            OnSuccessGetCloudScriptVersions.Execute(result, mCustomData);
        }
    }
}

/** Sets the currently published revision of a title Cloud Script */
UPlayFabAdminAPI* UPlayFabAdminAPI::SetPublishedRevision(FAdminSetPublishedRevisionRequest request,
    FDelegateOnSuccessSetPublishedRevision onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessSetPublishedRevision = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperSetPublishedRevision);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/SetPublishedRevision";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    OutRestJsonObj->SetNumberField(TEXT("Version"), request.Version);
    OutRestJsonObj->SetNumberField(TEXT("Revision"), request.Revision);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperSetPublishedRevision(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminSetPublishedRevisionResult result = UPlayFabAdminModelDecoder::decodeSetPublishedRevisionResultResponse(response.responseData);
        if (OnSuccessSetPublishedRevision.IsBound())
        {
            OnSuccessSetPublishedRevision.Execute(result, mCustomData);
        }
    }
}

/** Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one file should be submitted in the revision. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateCloudScript(FAdminUpdateCloudScriptRequest request,
    FDelegateOnSuccessUpdateCloudScript onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateCloudScript = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateCloudScript);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateCloudScript";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Files.Num() == 0) {
        OutRestJsonObj->SetFieldNull(TEXT("Files"));
    } else {
        OutRestJsonObj->SetObjectArrayField(TEXT("Files"), request.Files);
    }
    OutRestJsonObj->SetBoolField(TEXT("Publish"), request.Publish);
    if (request.DeveloperPlayFabId.IsEmpty() || request.DeveloperPlayFabId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("DeveloperPlayFabId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("DeveloperPlayFabId"), request.DeveloperPlayFabId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateCloudScript(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminUpdateCloudScriptResult result = UPlayFabAdminModelDecoder::decodeUpdateCloudScriptResultResponse(response.responseData);
        if (OnSuccessUpdateCloudScript.IsBound())
        {
            OnSuccessUpdateCloudScript.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////
/** Delete a content file from the title. When deleting a file that does not exist, it returns success. */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteContent(FAdminDeleteContentRequest request,
    FDelegateOnSuccessDeleteContent onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteContent = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeleteContent);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeleteContent";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeleteContent(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminBlankResult result = UPlayFabAdminModelDecoder::decodeBlankResultResponse(response.responseData);
        if (OnSuccessDeleteContent.IsBound())
        {
            OnSuccessDeleteContent.Execute(result, mCustomData);
        }
    }
}

/** List all contents of the title and get statistics such as size */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetContentList(FAdminGetContentListRequest request,
    FDelegateOnSuccessGetContentList onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetContentList = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetContentList);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetContentList";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Prefix.IsEmpty() || request.Prefix == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Prefix"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Prefix"), request.Prefix);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetContentList(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetContentListResult result = UPlayFabAdminModelDecoder::decodeGetContentListResultResponse(response.responseData);
        if (OnSuccessGetContentList.IsBound())
        {
            OnSuccessGetContentList.Execute(result, mCustomData);
        }
    }
}

/** Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned URL uploads the  content. Also, please be aware that the Content service is specifically PlayFab's CDN offering, for which standard CDN rates apply. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetContentUploadUrl(FAdminGetContentUploadUrlRequest request,
    FDelegateOnSuccessGetContentUploadUrl onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetContentUploadUrl = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetContentUploadUrl);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetContentUploadUrl";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Key.IsEmpty() || request.Key == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Key"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Key"), request.Key);
    }
    if (request.ContentType.IsEmpty() || request.ContentType == "") {
        OutRestJsonObj->SetFieldNull(TEXT("ContentType"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("ContentType"), request.ContentType);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetContentUploadUrl(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetContentUploadUrlResult result = UPlayFabAdminModelDecoder::decodeGetContentUploadUrlResultResponse(response.responseData);
        if (OnSuccessGetContentUploadUrl.IsBound())
        {
            OnSuccessGetContentUploadUrl.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////
/** Completely removes all statistics for the specified character, for the current game */
UPlayFabAdminAPI* UPlayFabAdminAPI::ResetCharacterStatistics(FAdminResetCharacterStatisticsRequest request,
    FDelegateOnSuccessResetCharacterStatistics onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessResetCharacterStatistics = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperResetCharacterStatistics);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/ResetCharacterStatistics";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperResetCharacterStatistics(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminResetCharacterStatisticsResult result = UPlayFabAdminModelDecoder::decodeResetCharacterStatisticsResultResponse(response.responseData);
        if (OnSuccessResetCharacterStatistics.IsBound())
        {
            OnSuccessResetCharacterStatistics.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////
/** Adds a given tag to a player profile. The tag's namespace is automatically generated based on the source of the tag. */
UPlayFabAdminAPI* UPlayFabAdminAPI::AddPlayerTag(FAdminAddPlayerTagRequest request,
    FDelegateOnSuccessAddPlayerTag onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAddPlayerTag = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAddPlayerTag);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AddPlayerTag";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAddPlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminAddPlayerTagResult result = UPlayFabAdminModelDecoder::decodeAddPlayerTagResultResponse(response.responseData);
        if (OnSuccessAddPlayerTag.IsBound())
        {
            OnSuccessAddPlayerTag.Execute(result, mCustomData);
        }
    }
}

/** Retrieve a list of all PlayStream actions groups. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetAllActionGroups(FAdminGetAllActionGroupsRequest request,
    FDelegateOnSuccessGetAllActionGroups onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAllActionGroups = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetAllActionGroups);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetAllActionGroups";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetAllActionGroups(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetAllActionGroupsResult result = UPlayFabAdminModelDecoder::decodeGetAllActionGroupsResultResponse(response.responseData);
        if (OnSuccessGetAllActionGroups.IsBound())
        {
            OnSuccessGetAllActionGroups.Execute(result, mCustomData);
        }
    }
}

/** Retrieves an array of player segment definitions. Results from this can be used in subsequent API calls such as GetPlayersInSegment which requires a Segment ID. While segment names can change the ID for that segment will not change. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetAllSegments(FAdminGetAllSegmentsRequest request,
    FDelegateOnSuccessGetAllSegments onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetAllSegments = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetAllSegments);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetAllSegments";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetAllSegments(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetAllSegmentsResult result = UPlayFabAdminModelDecoder::decodeGetAllSegmentsResultResponse(response.responseData);
        if (OnSuccessGetAllSegments.IsBound())
        {
            OnSuccessGetAllSegments.Execute(result, mCustomData);
        }
    }
}

/** List all segments that a player currently belongs to at this moment in time. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayerSegments(FAdminGetPlayersSegmentsRequest request,
    FDelegateOnSuccessGetPlayerSegments onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerSegments = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayerSegments);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayerSegments";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayerSegments(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPlayerSegmentsResult result = UPlayFabAdminModelDecoder::decodeGetPlayerSegmentsResultResponse(response.responseData);
        if (OnSuccessGetPlayerSegments.IsBound())
        {
            OnSuccessGetPlayerSegments.Execute(result, mCustomData);
        }
    }
}

/** Allows for paging through all players in a given segment. This API creates a snapshot of all player profiles that match the segment definition at the time of its creation and lives through the Total Seconds to Live, refreshing its life span on each subsequent use of the Continuation Token. Profiles that change during the course of paging will not be reflected in the results. AB Test segments are currently not supported by this operation. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayersInSegment(FAdminGetPlayersInSegmentRequest request,
    FDelegateOnSuccessGetPlayersInSegment onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayersInSegment = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayersInSegment);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayersInSegment";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayersInSegment(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPlayersInSegmentResult result = UPlayFabAdminModelDecoder::decodeGetPlayersInSegmentResultResponse(response.responseData);
        if (OnSuccessGetPlayersInSegment.IsBound())
        {
            OnSuccessGetPlayersInSegment.Execute(result, mCustomData);
        }
    }
}

/** Get all tags with a given Namespace (optional) from a player profile. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetPlayerTags(FAdminGetPlayerTagsRequest request,
    FDelegateOnSuccessGetPlayerTags onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetPlayerTags = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetPlayerTags);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetPlayerTags";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetPlayerTags(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetPlayerTagsResult result = UPlayFabAdminModelDecoder::decodeGetPlayerTagsResultResponse(response.responseData);
        if (OnSuccessGetPlayerTags.IsBound())
        {
            OnSuccessGetPlayerTags.Execute(result, mCustomData);
        }
    }
}

/** Remove a given tag from a player profile. The tag's namespace is automatically generated based on the source of the tag. */
UPlayFabAdminAPI* UPlayFabAdminAPI::RemovePlayerTag(FAdminRemovePlayerTagRequest request,
    FDelegateOnSuccessRemovePlayerTag onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRemovePlayerTag = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRemovePlayerTag);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RemovePlayerTag";
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

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRemovePlayerTag(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminRemovePlayerTagResult result = UPlayFabAdminModelDecoder::decodeRemovePlayerTagResultResponse(response.responseData);
        if (OnSuccessRemovePlayerTag.IsBound())
        {
            OnSuccessRemovePlayerTag.Execute(result, mCustomData);
        }
    }
}


///////////////////////////////////////////////////////
// ScheduledTask
//////////////////////////////////////////////////////
/** Abort an ongoing task instance. */
UPlayFabAdminAPI* UPlayFabAdminAPI::AbortTaskInstance(FAdminAbortTaskInstanceRequest request,
    FDelegateOnSuccessAbortTaskInstance onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessAbortTaskInstance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperAbortTaskInstance);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/AbortTaskInstance";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.TaskInstanceId.IsEmpty() || request.TaskInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TaskInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TaskInstanceId"), request.TaskInstanceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperAbortTaskInstance(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminEmptyResult result = UPlayFabAdminModelDecoder::decodeEmptyResultResponse(response.responseData);
        if (OnSuccessAbortTaskInstance.IsBound())
        {
            OnSuccessAbortTaskInstance.Execute(result, mCustomData);
        }
    }
}

/** Create an ActionsOnPlayersInSegment task, which iterates through all players in a segment to execute action. */
UPlayFabAdminAPI* UPlayFabAdminAPI::CreateActionsOnPlayersInSegmentTask(FAdminCreateActionsOnPlayerSegmentTaskRequest request,
    FDelegateOnSuccessCreateActionsOnPlayersInSegmentTask onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateActionsOnPlayersInSegmentTask = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperCreateActionsOnPlayersInSegmentTask);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/CreateActionsOnPlayersInSegmentTask";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    if (request.Description.IsEmpty() || request.Description == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Description"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Description"), request.Description);
    }
    if (request.Schedule.IsEmpty() || request.Schedule == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Schedule"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Schedule"), request.Schedule);
    }
    OutRestJsonObj->SetBoolField(TEXT("IsActive"), request.IsActive);
    if (request.Parameter != nullptr) OutRestJsonObj->SetObjectField(TEXT("Parameter"), request.Parameter);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperCreateActionsOnPlayersInSegmentTask(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminCreateTaskResult result = UPlayFabAdminModelDecoder::decodeCreateTaskResultResponse(response.responseData);
        if (OnSuccessCreateActionsOnPlayersInSegmentTask.IsBound())
        {
            OnSuccessCreateActionsOnPlayersInSegmentTask.Execute(result, mCustomData);
        }
    }
}

/** Create a CloudScript task, which can run a CloudScript on a schedule. */
UPlayFabAdminAPI* UPlayFabAdminAPI::CreateCloudScriptTask(FAdminCreateCloudScriptTaskRequest request,
    FDelegateOnSuccessCreateCloudScriptTask onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessCreateCloudScriptTask = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperCreateCloudScriptTask);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/CreateCloudScriptTask";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    if (request.Description.IsEmpty() || request.Description == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Description"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Description"), request.Description);
    }
    if (request.Schedule.IsEmpty() || request.Schedule == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Schedule"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Schedule"), request.Schedule);
    }
    OutRestJsonObj->SetBoolField(TEXT("IsActive"), request.IsActive);
    if (request.Parameter != nullptr) OutRestJsonObj->SetObjectField(TEXT("Parameter"), request.Parameter);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperCreateCloudScriptTask(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminCreateTaskResult result = UPlayFabAdminModelDecoder::decodeCreateTaskResultResponse(response.responseData);
        if (OnSuccessCreateCloudScriptTask.IsBound())
        {
            OnSuccessCreateCloudScriptTask.Execute(result, mCustomData);
        }
    }
}

/** Delete a task. */
UPlayFabAdminAPI* UPlayFabAdminAPI::DeleteTask(FAdminDeleteTaskRequest request,
    FDelegateOnSuccessDeleteTask onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessDeleteTask = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperDeleteTask);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/DeleteTask";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Identifier != nullptr) OutRestJsonObj->SetObjectField(TEXT("Identifier"), request.Identifier);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperDeleteTask(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminEmptyResult result = UPlayFabAdminModelDecoder::decodeEmptyResultResponse(response.responseData);
        if (OnSuccessDeleteTask.IsBound())
        {
            OnSuccessDeleteTask.Execute(result, mCustomData);
        }
    }
}

/** Get information about a ActionsOnPlayersInSegment task instance. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetActionsOnPlayersInSegmentTaskInstance(FAdminGetTaskInstanceRequest request,
    FDelegateOnSuccessGetActionsOnPlayersInSegmentTaskInstance onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetActionsOnPlayersInSegmentTaskInstance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetActionsOnPlayersInSegmentTaskInstance);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetActionsOnPlayersInSegmentTaskInstance";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.TaskInstanceId.IsEmpty() || request.TaskInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TaskInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TaskInstanceId"), request.TaskInstanceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetActionsOnPlayersInSegmentTaskInstance(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetActionsOnPlayersInSegmentTaskInstanceResult result = UPlayFabAdminModelDecoder::decodeGetActionsOnPlayersInSegmentTaskInstanceResultResponse(response.responseData);
        if (OnSuccessGetActionsOnPlayersInSegmentTaskInstance.IsBound())
        {
            OnSuccessGetActionsOnPlayersInSegmentTaskInstance.Execute(result, mCustomData);
        }
    }
}

/** Get detail information about a CloudScript task instance. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetCloudScriptTaskInstance(FAdminGetTaskInstanceRequest request,
    FDelegateOnSuccessGetCloudScriptTaskInstance onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetCloudScriptTaskInstance = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetCloudScriptTaskInstance);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetCloudScriptTaskInstance";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.TaskInstanceId.IsEmpty() || request.TaskInstanceId == "") {
        OutRestJsonObj->SetFieldNull(TEXT("TaskInstanceId"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("TaskInstanceId"), request.TaskInstanceId);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetCloudScriptTaskInstance(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetCloudScriptTaskInstanceResult result = UPlayFabAdminModelDecoder::decodeGetCloudScriptTaskInstanceResultResponse(response.responseData);
        if (OnSuccessGetCloudScriptTaskInstance.IsBound())
        {
            OnSuccessGetCloudScriptTaskInstance.Execute(result, mCustomData);
        }
    }
}

/** Query for task instances by task, status, or time range. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetTaskInstances(FAdminGetTaskInstancesRequest request,
    FDelegateOnSuccessGetTaskInstances onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTaskInstances = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetTaskInstances);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetTaskInstances";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.TaskIdentifier != nullptr) OutRestJsonObj->SetObjectField(TEXT("TaskIdentifier"), request.TaskIdentifier);
    FString temp_StatusFilter;
    if (GetEnumValueToString<ETaskInstanceStatus>(TEXT("ETaskInstanceStatus"), request.StatusFilter, temp_StatusFilter))
        OutRestJsonObj->SetStringField(TEXT("StatusFilter"), temp_StatusFilter);
    if (request.StartedAtRangeFrom.IsEmpty() || request.StartedAtRangeFrom == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StartedAtRangeFrom"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StartedAtRangeFrom"), request.StartedAtRangeFrom);
    }
    if (request.StartedAtRangeTo.IsEmpty() || request.StartedAtRangeTo == "") {
        OutRestJsonObj->SetFieldNull(TEXT("StartedAtRangeTo"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("StartedAtRangeTo"), request.StartedAtRangeTo);
    }

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetTaskInstances(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetTaskInstancesResult result = UPlayFabAdminModelDecoder::decodeGetTaskInstancesResultResponse(response.responseData);
        if (OnSuccessGetTaskInstances.IsBound())
        {
            OnSuccessGetTaskInstances.Execute(result, mCustomData);
        }
    }
}

/** Get definition information on a specified task or all tasks within a title. */
UPlayFabAdminAPI* UPlayFabAdminAPI::GetTasks(FAdminGetTasksRequest request,
    FDelegateOnSuccessGetTasks onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessGetTasks = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperGetTasks);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/GetTasks";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Identifier != nullptr) OutRestJsonObj->SetObjectField(TEXT("Identifier"), request.Identifier);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperGetTasks(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminGetTasksResult result = UPlayFabAdminModelDecoder::decodeGetTasksResultResponse(response.responseData);
        if (OnSuccessGetTasks.IsBound())
        {
            OnSuccessGetTasks.Execute(result, mCustomData);
        }
    }
}

/** Run a task immediately regardless of its schedule. */
UPlayFabAdminAPI* UPlayFabAdminAPI::RunTask(FAdminRunTaskRequest request,
    FDelegateOnSuccessRunTask onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessRunTask = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperRunTask);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/RunTask";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Identifier != nullptr) OutRestJsonObj->SetObjectField(TEXT("Identifier"), request.Identifier);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperRunTask(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminRunTaskResult result = UPlayFabAdminModelDecoder::decodeRunTaskResultResponse(response.responseData);
        if (OnSuccessRunTask.IsBound())
        {
            OnSuccessRunTask.Execute(result, mCustomData);
        }
    }
}

/** Update an existing task. */
UPlayFabAdminAPI* UPlayFabAdminAPI::UpdateTask(FAdminUpdateTaskRequest request,
    FDelegateOnSuccessUpdateTask onSuccess,
    FDelegateOnFailurePlayFabError onFailure,
    UObject* customData)
{
    // Objects containing request data
    UPlayFabAdminAPI* manager = NewObject<UPlayFabAdminAPI>();
    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    manager->mCustomData = customData;

    // Assign delegates
    manager->OnSuccessUpdateTask = onSuccess;
    manager->OnFailure = onFailure;
    manager->OnPlayFabResponse.AddDynamic(manager, &UPlayFabAdminAPI::HelperUpdateTask);

    // Setup the request
    manager->PlayFabRequestURL = "/Admin/UpdateTask";
    manager->useSessionTicket = false;
    manager->useSecretKey = true;

    // Serialize all the request properties to json
    if (request.Identifier != nullptr) OutRestJsonObj->SetObjectField(TEXT("Identifier"), request.Identifier);
    if (request.Name.IsEmpty() || request.Name == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Name"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Name"), request.Name);
    }
    if (request.Description.IsEmpty() || request.Description == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Description"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Description"), request.Description);
    }
    if (request.Schedule.IsEmpty() || request.Schedule == "") {
        OutRestJsonObj->SetFieldNull(TEXT("Schedule"));
    } else {
        OutRestJsonObj->SetStringField(TEXT("Schedule"), request.Schedule);
    }
    OutRestJsonObj->SetBoolField(TEXT("IsActive"), request.IsActive);
    FString temp_Type;
    if (GetEnumValueToString<EScheduledTaskType>(TEXT("EScheduledTaskType"), request.Type, temp_Type))
        OutRestJsonObj->SetStringField(TEXT("Type"), temp_Type);
    if (request.Parameter != nullptr) OutRestJsonObj->SetObjectField(TEXT("Parameter"), request.Parameter);

    // Add Request to manager
    manager->SetRequestObject(OutRestJsonObj);

    return manager;
}

// Implements FOnPlayFabAdminRequestCompleted
void UPlayFabAdminAPI::HelperUpdateTask(FPlayFabBaseModel response, UObject* customData, bool successful)
{
    FPlayFabError error = response.responseError;
    if (error.hasError)
    {
        if (OnFailure.IsBound())
        {
            OnFailure.Execute(error, customData);
        }
    }
    else
    {
        FAdminEmptyResult result = UPlayFabAdminModelDecoder::decodeEmptyResultResponse(response.responseData);
        if (OnSuccessUpdateTask.IsBound())
        {
            OnSuccessUpdateTask.Execute(result, mCustomData);
        }
    }
}



void UPlayFabAdminAPI::OnProcessRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
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
    {
        UE_LOG(LogPlayFab, Warning, TEXT("JSON could not be decoded!"));
    }

    // Log response state
    UE_LOG(LogPlayFab, Log, TEXT("Response : %s"), *ResponseContent);

    myResponse.responseError.decodeError(ResponseJsonObj);
    myResponse.responseData = ResponseJsonObj;
    IPlayFab* pfSettings = &(IPlayFab::Get());

    // Broadcast the result event
    OnPlayFabResponse.Broadcast(myResponse, mCustomData, myResponse.responseError.hasError);
    pfSettings->ModifyPendingCallCount(-1);
}

void UPlayFabAdminAPI::Activate()
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
    HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPlayFabAdminAPI::OnProcessRequestComplete);

    // Execute the request
    pfSettings->ModifyPendingCallCount(1);
    HttpRequest->ProcessRequest();
}

void UPlayFabAdminAPI::ResetResponseData()
{
    if (ResponseJsonObj != nullptr)
    {
        ResponseJsonObj->Reset();
    }
    else
    {
        ResponseJsonObj = NewObject<UPlayFabJsonObject>();
    }

    bIsValidJsonResponse = false;
}
