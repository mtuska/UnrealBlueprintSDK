#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Server
//////////////////////////////////////////////////////////////////////////////////////////////

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabServerModels.generated.h"

class UPlayFabJsonObject;

//////////////////////////////////////////////////////////////////////////
// Generated PlayFab Server API Functions
//////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Authentication
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAuthenticateSessionTicketRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Session ticket as issued by a PlayFab client login API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString SessionTicket;
};

USTRUCT(BlueprintType)
struct FServerAuthenticateSessionTicketResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account info for the user whose session ticket was supplied. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct FServerSetPlayerSecretRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Player secret that is used to verify API request signatures (Enterprise Only). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString PlayerSecret;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Authentication Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerSetPlayerSecretResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Account Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerBanUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of ban requests to be applied. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct FServerBanUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were applied */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerProfileRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
    /** If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client, only the allowed client profile properties for the title may be requested. These allowed properties are configured in the Game Manager "Client Profile Options" tab in the "Settings" section. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerProfileResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The profile of the player. This profile is not guaranteed to be up-to-date. For a new player, this profile will not exist. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* PlayerProfile = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromFacebookIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Facebook identifiers for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString FacebookIDs;
};

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromFacebookIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Facebook identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromSteamIDsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of unique Steam identifiers (Steam profile IDs) for which the title needs to get PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString SteamStringIDs;
};

USTRUCT(BlueprintType)
struct FServerGetPlayFabIDsFromSteamIDsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Mapping of Steam identifiers to PlayFab identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Data;
};

USTRUCT(BlueprintType)
struct FServerGetUserAccountInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerGetUserAccountInfoResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Account details for the user whose information was requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetUserBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerGetUserBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information about the bans */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FServerRevokeAllBansForUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerRevokeAllBansForUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FServerRevokeBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ids of the bans to be revoked. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString BanIds;
};

USTRUCT(BlueprintType)
struct FServerRevokeBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were revoked */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};

USTRUCT(BlueprintType)
struct FServerSendPushNotificationRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFabId of the recipient of the push notification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Recipient;
    /** Text of message to send. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Message;
    /** Defines all possible push attributes like message, title, icon, etc. Not supported for iOS devices. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        UPlayFabJsonObject* Package = nullptr;
    /** Subject of message to send (may not be displayed in all platforms. Not supported for Android devices (use Package instead). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString Subject;
    /** Platforms that should receive the message. If omitted, we will send to all available platforms. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString TargetPlatforms;
};

USTRUCT(BlueprintType)
struct FServerSendPushNotificationResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerEmptyResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerUpdateAvatarUrlRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString PlayFabId;
    /** URL of the avatar image. If empty, it removes the existing avatar URL. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        FString ImageUrl;
};

USTRUCT(BlueprintType)
struct FServerUpdateBansRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of bans to be updated. Maximum 100. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> Bans;
};

USTRUCT(BlueprintType)
struct FServerUpdateBansResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Information on the bans that were updated */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Account Management Models")
        TArray<UPlayFabJsonObject*> BanData;
};


///////////////////////////////////////////////////////
// Player Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerDeleteUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabIds;
};

USTRUCT(BlueprintType)
struct FServerDeleteUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerGetFriendLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The player whose friend leaderboard to get */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Statistic used to rank friends for this leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
    /** Position in the leaderboard to start this listing (defaults to the first entry). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 StartPosition = 0;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /** Indicates whether Steam service friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool IncludeSteamFriends = false;
    /** Indicates whether Facebook friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool IncludeFacebookFriends = false;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool UseSpecificVersion = false;
    /** If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client, only the allowed client profile properties for the title may be requested. These allowed properties are configured in the Game Manager "Client Profile Options" tab in the "Settings" section. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered listing of users and their positions in the requested leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
    /** The version of the leaderboard returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
    /** The time the next scheduled reset will occur. Null if the leaderboard does not reset on a schedule. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString NextReset;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
    /** First entry in the leaderboard to be retrieved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 StartPosition = 0;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /** If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client, only the allowed client profile properties for the title may be requested. These allowed properties are configured in the Game Manager "Client Profile Options" tab in the "Settings" section. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool UseSpecificVersion = false;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 MaxResultsCount = 0;
    /** If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client, only the allowed client profile properties for the title may be requested. These allowed properties are configured in the Game Manager "Client Profile Options" tab in the "Settings" section. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
    /** The version of the leaderboard to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
    /** If set to false, Version is considered null. If true, uses the specified Version */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool UseSpecificVersion = false;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered listing of users and their positions in the requested leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
    /** The version of the leaderboard returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 Version = 0;
    /** The time the next scheduled reset will occur. Null if the leaderboard does not reset on a schedule. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString NextReset;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerCombinedInfoRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFabId of the user whose data will be returned */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Flags for which pieces of info to return for the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* InfoRequestParameters = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerCombinedInfoResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Results for requested info. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* InfoResultPayload = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** user for whom statistics are being requested */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** statistics to return */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticNames;
    /** statistics to return, if StatisticNames is not set (only statistics which have a version matching that provided will be returned) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticNameVersions;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose statistics are being returned */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** User statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticVersionsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** unique name of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString StatisticName;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerStatisticVersionsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** version change history of the statistic */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> StatisticVersions;
};

USTRUCT(BlueprintType)
struct FServerGetUserDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString Keys;
    /** The version that currently exists according to the caller. The call will return the data for all of the keys if the version in the system is greater than this. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 IfChangedFromDataVersion = 0;
};

USTRUCT(BlueprintType)
struct FServerGetUserDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose custom data is being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 DataVersion = 0;
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data = nullptr;
};

USTRUCT(BlueprintType)
struct FServerUpdatePlayerStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Statistics to be updated with the provided values */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        TArray<UPlayFabJsonObject*> Statistics;
    /** Indicates whether the statistics provided should be set, regardless of the aggregation method set on the statistic. Default is false. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        bool ForceUpdate = false;
};

USTRUCT(BlueprintType)
struct FServerUpdatePlayerStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerUpdateUserDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character or be null. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data;
    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        EUserDataPermission Permission;
};

USTRUCT(BlueprintType)
struct FServerUpdateUserDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        int32 DataVersion = 0;
};

USTRUCT(BlueprintType)
struct FServerUpdateUserInternalDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString PlayFabId;
    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character or be null. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        UPlayFabJsonObject* Data;
    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Data Management Models")
        FString KeysToRemove;
};


///////////////////////////////////////////////////////
// Title-Wide Data Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerGetCatalogItemsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Which catalog is being requested. If null, uses the default catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FServerGetCatalogItemsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items which can be purchased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> Catalog;
};

USTRUCT(BlueprintType)
struct FServerGetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /**  array of keys to get back data from the Publisher data blob, set by the admin tools */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct FServerGetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct FServerGetTimeRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerGetTimeResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Current server time when the request was received, in UTC */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Time;
};

USTRUCT(BlueprintType)
struct FServerGetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specific keys to search for in the title data (leave null to get all keys) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Keys;
};

USTRUCT(BlueprintType)
struct FServerGetTitleDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** a dictionary object of key / value pairs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        UPlayFabJsonObject* Data;
};

USTRUCT(BlueprintType)
struct FServerGetTitleNewsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Limits the results to the last n entries. Defaults to 10 if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        int32 Count = 0;
};

USTRUCT(BlueprintType)
struct FServerGetTitleNewsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of news items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        TArray<UPlayFabJsonObject*> News;
};

USTRUCT(BlueprintType)
struct FServerSetPublisherDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Key;
    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Value;
};

USTRUCT(BlueprintType)
struct FServerSetPublisherDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerSetTitleDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** key we want to set a value on (note, this is additive - will only replace an existing key's value if they are the same name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Key;
    /** new value to set. Set to null to remove a value */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Title-Wide Data Management Models")
        FString Value;
};

USTRUCT(BlueprintType)
struct FServerSetTitleDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Player Item Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAddCharacterVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose virtual currency balance is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
    /** Amount to be added to the character balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
};

USTRUCT(BlueprintType)
struct FServerModifyCharacterVirtualCurrencyResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Balance = 0;
};

USTRUCT(BlueprintType)
struct FServerAddUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose virtual currency balance is to be increased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be incremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
    /** Amount to be added to the user balance of the specified virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
};

USTRUCT(BlueprintType)
struct FServerModifyUserVirtualCurrencyResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** User currency was subtracted from. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which was modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
    /** Amount added or subtracted from the user's virtual currency. Maximum VC balance is Int32 (2,147,483,647). Any increase over this value will be discarded. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 BalanceChange = 0;
    /** Balance of the virtual currency after modification. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Balance = 0;
};

USTRUCT(BlueprintType)
struct FServerConsumeItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique instance identifier of the item to be consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Number of uses to consume from the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 ConsumeCount = 0;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct FServerConsumeItemResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique instance identifier of the item with uses consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Number of uses remaining on the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 RemainingUses = 0;
};

USTRUCT(BlueprintType)
struct FServerEvaluateRandomResultTableRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The unique identifier of the Random Result Table to use. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString TableId;
    /** Specifies the catalog version that should be used to evaluate the Random Result Table.  If unspecified, uses default/primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FServerEvaluateRandomResultTableResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the item returned from the Random Result Table evaluation, for the given catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ResultItemId;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterInventoryRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Used to limit results to only those from a specific catalog version. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique identifier of the character for this inventory. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Array of inventory items belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Array of virtual currency balance(s) belonging to the character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetRandomResultTablesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Specifies the catalog version that should be used to retrieve the Random Result Tables.  If unspecified, uses default/primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** The unique identifier of the Random Result Table to use. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString TableIDs;
};

USTRUCT(BlueprintType)
struct FServerGetRandomResultTablesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** array of random result tables currently available */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* Tables = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetUserInventoryRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerGetUserInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Array of inventory items belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> Inventory;
    /** Array of virtual currency balance(s) belonging to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
    /** Array of remaining times and timestamps for virtual currencies. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrencyRechargeTimes = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGrantItemsToCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** String detailing any additional information concerning this operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Annotation;
    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;
};

USTRUCT(BlueprintType)
struct FServerGrantItemsToCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** String detailing any additional information concerning this operation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Annotation;
    /** Array of itemIds to grant to the user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemIds;
};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUsersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Catalog version from which items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Array of items to grant and the users to whom the items are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrants;
};

USTRUCT(BlueprintType)
struct FServerGrantItemsToUsersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of items granted to users. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> ItemGrantResults;
};

USTRUCT(BlueprintType)
struct FServerModifyItemUsesRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose item is being modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique instance identifier of the item to be modified. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Number of uses to add to the item. Can be negative to remove uses. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 UsesToAdd = 0;
};

USTRUCT(BlueprintType)
struct FServerModifyItemUsesResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique instance identifier of the item with uses consumed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Number of uses remaining on the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 RemainingUses = 0;
};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique identifier of the character that currently has the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString GivingCharacterId;
    /** Unique identifier of the character that will be receiving the item. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReceivingCharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
};

USTRUCT(BlueprintType)
struct FServerMoveItemToCharacterFromUserResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerMoveItemToUserFromCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
};

USTRUCT(BlueprintType)
struct FServerMoveItemToUserFromCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerRedeemCouponRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Generated coupon code to redeem. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CouponCode;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Catalog version of the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
    /** Optional identifier for the Character that should receive the item. If null, item is added to the player */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct FServerRedeemCouponResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Items granted to the player as a result of redeeming the coupon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
};

USTRUCT(BlueprintType)
struct FServerReportPlayerServerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFabId of the reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporterId;
    /** Unique PlayFab identifier of the reported player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ReporteeId;
    /** Optional additional comment by reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString Comment;
};

USTRUCT(BlueprintType)
struct FServerReportPlayerServerResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Deprecated: Always true */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        bool Updated = false;
    /** The number of remaining reports which may be filed today by this reporting player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 SubmissionsRemaining = 0;
};

USTRUCT(BlueprintType)
struct FServerRevokeInventoryItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
};

USTRUCT(BlueprintType)
struct FServerRevokeInventoryResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerSubtractCharacterVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
};

USTRUCT(BlueprintType)
struct FServerSubtractUserVirtualCurrencyRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose virtual currency balance is to be decreased. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Name of the virtual currency which is to be decremented. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString VirtualCurrency;
    /** Amount to be subtracted from the user balance of the specified virtual currency. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        int32 Amount = 0;
};

USTRUCT(BlueprintType)
struct FServerUnlockContainerInstanceRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** ItemInstanceId of the container to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ContainerItemInstanceId;
    /** ItemInstanceId of the key that will be consumed by unlocking this container.  If the container requires a key, this parameter is required. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString KeyItemInstanceId;
    /** Specifies the catalog version that should be used to determine container contents.  If unspecified, uses catalog associated with the item instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FServerUnlockContainerItemResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique instance identifier of the container unlocked. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString UnlockedItemInstanceId;
    /** Unique instance identifier of the key used to unlock the container, if applicable. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString UnlockedWithItemInstanceId;
    /** Items granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        TArray<UPlayFabJsonObject*> GrantedItems;
    /** Virtual currency granted to the player as a result of unlocking the container. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* VirtualCurrency;
};

USTRUCT(BlueprintType)
struct FServerUnlockContainerItemRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Catalog ItemId of the container type to unlock. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ContainerItemId;
    /** Specifies the catalog version that should be used to determine container contents.  If unspecified, uses default/primary catalog. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CatalogVersion;
};

USTRUCT(BlueprintType)
struct FServerUpdateUserInventoryItemDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString CharacterId;
    /** Unique PlayFab assigned instance identifier of the item */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString ItemInstanceId;
    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character or be null. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        UPlayFabJsonObject* Data;
    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Player Item Management Models")
        FString KeysToRemove;
};


///////////////////////////////////////////////////////
// Friend List Management
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAddFriendRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the player to add a new friend. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
    /** The PlayFab identifier of the user being added. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendPlayFabId;
    /** The PlayFab username of the user being added */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendUsername;
    /** Email address of the user being added. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendEmail;
    /** Title-specific display name of the user to being added. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendTitleDisplayName;
};

USTRUCT(BlueprintType)
struct FServerGetFriendsListRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the player whose friend list to get. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
    /** Indicates whether Steam service friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        bool IncludeSteamFriends = false;
    /** Indicates whether Facebook friends should be included in the response. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        bool IncludeFacebookFriends = false;
    /** If non-null, this determines which properties of the resulting player profiles to return. For API calls from the client, only the allowed client profile properties for the title may be requested. These allowed properties are configured in the Game Manager "Client Profile Options" tab in the "Settings" section. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        UPlayFabJsonObject* ProfileConstraints = nullptr;
};

USTRUCT(BlueprintType)
struct FServerGetFriendsListResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of friends found. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        TArray<UPlayFabJsonObject*> Friends;
};

USTRUCT(BlueprintType)
struct FServerRemoveFriendRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the friend account which is to be removed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendPlayFabId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerSetFriendTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab identifier of the player whose friend is to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString PlayFabId;
    /** PlayFab identifier of the friend account to which the tag(s) should be applied. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString FriendPlayFabId;
    /** Array of tags to set on the friend account. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Friend List Management Models")
        FString Tags;
};


///////////////////////////////////////////////////////
// Matchmaking
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerDeregisterGameRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the Game Server Instance that is being deregistered. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct FServerDeregisterGameResponse
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerNotifyMatchmakerPlayerLeftRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Instance the user is leaving. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerNotifyMatchmakerPlayerLeftResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** State of user leaving the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        EPlayerConnectionState PlayerState;
};

USTRUCT(BlueprintType)
struct FServerRedeemMatchmakerTicketRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Server authorization ticket passed back from a call to Matchmake or StartGame. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Ticket;
    /** Unique identifier of the Game Server Instance that is asking for validation of the authorization ticket. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct FServerRedeemMatchmakerTicketResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Boolean indicating whether the ticket was validated by the PlayFab service. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        bool TicketIsValid = false;
    /** Error value if the ticket was not validated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Error;
    /** User account information for the user validated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* UserInfo = nullptr;
};

USTRUCT(BlueprintType)
struct FServerRefreshGameServerInstanceHeartbeatRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Server Instance for which the heartbeat is updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct FServerRefreshGameServerInstanceHeartbeatResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerRegisterGameRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Previous lobby id if re-registering an existing game. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** IP address of the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString ServerHost;
    /** Port number for communication with the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString ServerPort;
    /** Unique identifier of the build running on the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString Build;
    /** Region in which the Game Server Instance is running. For matchmaking using non-AWS region names, set this to any AWS region and use Tags (below) to specify your custom region. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        ERegion Region;
    /** Game Mode the Game Server instance is running. Note that this must be defined in the Game Modes tab in the PlayFab Game Manager, along with the Build ID (the same Game Mode can be defined for multiple Build IDs). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString GameMode;
    /** Tags for the Game Server Instance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* Tags;
};

USTRUCT(BlueprintType)
struct FServerRegisterGameResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier generated for the Game Server Instance that is registered. If LobbyId is specified in request and the game still exists in PlayFab, the LobbyId in request is returned. Otherwise a new lobby id will be returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
};

USTRUCT(BlueprintType)
struct FServerSetGameServerInstanceDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Instance to be updated, in decimal format. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** Custom data to set for the specified game server instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString GameServerData;
};

USTRUCT(BlueprintType)
struct FServerSetGameServerInstanceDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerSetGameServerInstanceStateRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Instance to be updated, in decimal format. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** State to set for the specified game server instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        EGameInstanceState State;
};

USTRUCT(BlueprintType)
struct FServerSetGameServerInstanceStateResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerSetGameServerInstanceTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier of the Game Server Instance to be updated. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        FString LobbyId;
    /** Tags to set for the specified Game Server Instance. Note that this is the complete list of tags to be associated with the Game Server Instance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Matchmaking Models")
        UPlayFabJsonObject* Tags;
};

USTRUCT(BlueprintType)
struct FServerSetGameServerInstanceTagsResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Analytics
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerWriteEventResponse
{
    GENERATED_USTRUCT_BODY()
public:
    /** The unique identifier of the event. The values of this identifier consist of ASCII characters and are not constrained to any particular format. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventId;
};

USTRUCT(BlueprintType)
struct FServerWriteServerCharacterEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString CharacterId;
    /** The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
};

USTRUCT(BlueprintType)
struct FServerWriteServerPlayerEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString PlayFabId;
    /** The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
    /** Custom data properties associated with the event. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
};

USTRUCT(BlueprintType)
struct FServerWriteTitleEventRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the event, within the namespace scoped to the title. The naming convention is up to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString EventName;
    /** The time (in UTC) associated with this event. The value dafaults to the current time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        FString Timestamp;
    /** Custom event properties. Each property consists of a name (string) and a value (JSON object). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Analytics Models")
        UPlayFabJsonObject* Body = nullptr;
};


///////////////////////////////////////////////////////
// Shared Group Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAddSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString PlayFabIds;
};

USTRUCT(BlueprintType)
struct FServerAddSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerCreateSharedGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group (a random identifier will be assigned, if one is not specified). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FServerCreateSharedGroupResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FServerDeleteSharedGroupRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
};

USTRUCT(BlueprintType)
struct FServerGetSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
    /** Specific keys to retrieve from the shared group (if not specified, all keys will be returned, while an empty array indicates that no keys should be returned). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Keys;
    /** If true, return the list of all members of the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        bool GetMembers = false;
};

USTRUCT(BlueprintType)
struct FServerGetSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Data for the requested keys. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data = nullptr;
    /** List of PlayFabId identifiers for the members of this group, if requested. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString Members;
};

USTRUCT(BlueprintType)
struct FServerRemoveSharedGroupMembersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
    /** An array of unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString PlayFabIds;
};

USTRUCT(BlueprintType)
struct FServerRemoveSharedGroupMembersResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerUpdateSharedGroupDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the shared group. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString SharedGroupId;
    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character or be null. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        UPlayFabJsonObject* Data;
    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys in this request. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Shared Group Data Models")
        EUserDataPermission Permission;
};

USTRUCT(BlueprintType)
struct FServerUpdateSharedGroupDataResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Server-Side Cloud Script
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerExecuteCloudScriptResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The name of the function that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        FString FunctionName;
    /** The revision of the CloudScript that executed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 Revision = 0;
    /** The object returned from the CloudScript function, if any */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionResult = nullptr;
    /** Flag indicating if the FunctionResult was too large and was subsequently dropped from this event. This only occurs if the total event size is larger than 350KB. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        bool FunctionResultTooLarge = false;
    /** Entries logged during the function execution. These include both entries logged in the function code using log.info() and log.error() and error entries for API and HTTP request failures. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        TArray<UPlayFabJsonObject*> Logs;
    /** Flag indicating if the logs were too large and were subsequently dropped from this event. This only occurs if the total event size is larger than 350KB after the FunctionResult was removed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        bool LogsTooLarge = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 ExecutionTimeSeconds = 0;
    /** Processor time consumed while executing the function. This does not include time spent waiting on API calls or HTTP requests. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 ProcessorTimeSeconds = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 MemoryConsumedBytes = 0;
    /** Number of PlayFab API requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 APIRequestsIssued = 0;
    /** Number of external HTTP requests issued by the CloudScript function */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 HttpRequestsIssued = 0;
    /** Information about the error, if any, that occurred during execution */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        UPlayFabJsonObject* Error = nullptr;
};

USTRUCT(BlueprintType)
struct FServerExecuteCloudScriptServerRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** The unique user identifier for the player on whose behalf the script is being run */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        FString PlayFabId;
    /** The name of the CloudScript function to execute */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        FString FunctionName;
    /** Object that is passed in to the function as the first argument */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        UPlayFabJsonObject* FunctionParameter = nullptr;
    /** Option for which revision of the CloudScript to execute. 'Latest' executes the most recently created revision, 'Live' executes the current live, published revision, and 'Specific' executes the specified revision. The default value is 'Specific', if the SpeificRevision parameter is specified, otherwise it is 'Live'. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        ECloudScriptRevisionOption RevisionSelection;
    /** The specivic revision to execute, when RevisionSelection is set to 'Specific' */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        int32 SpecificRevision = 0;
    /** Generate a 'player_executed_cloudscript' PlayStream event containing the results of the function execution and other contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Server-Side Cloud Script Models")
        bool GeneratePlayStreamEvent = false;
};


///////////////////////////////////////////////////////
// Content
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerGetContentDownloadUrlRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Key of the content item to fetch, usually formatted as a path, e.g. images/a.png */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString Key;
    /** HTTP method to fetch item - GET or HEAD. Use HEAD when only fetching metadata. Default is GET. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString HttpMethod;
    /** True if download through CDN. CDN provides better download bandwidth and time. However, if you want latest, non-cached version of the content, set this to false. Default is true. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        bool ThruCDN = false;
};

USTRUCT(BlueprintType)
struct FServerGetContentDownloadUrlResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** URL for downloading content via HTTP GET or HEAD method. The URL will expire in 1 hour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Content Models")
        FString URL;
};


///////////////////////////////////////////////////////
// Characters
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerDeleteCharacterFromUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** If true, the character's inventory will be transferred up to the owning user; otherwise, this request will purge those items. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        bool SaveCharacterInventory = false;
};

USTRUCT(BlueprintType)
struct FServerDeleteCharacterFromUserResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerListUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerListUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** The requested list of characters. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Characters;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterLeaderboardRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;
    /** First entry in the leaderboard to be retrieved. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 StartPosition = 0;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount = 0;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterLeaderboardResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** PlayFab unique identifier of the user whose character statistics are being returned. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique identifier of the character for the statistics. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Character statistics for the requested user. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundCharacterRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Optional character type on which to filter the leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount = 0;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardAroundCharacterResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardForUsersCharactersRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for the title-specific statistic for the leaderboard. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString StatisticName;
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Maximum number of entries to retrieve. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        int32 MaxResultsCount = 0;
};

USTRUCT(BlueprintType)
struct FServerGetLeaderboardForUsersCharactersResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Ordered list of leaderboard entries. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        TArray<UPlayFabJsonObject*> Leaderboard;
};

USTRUCT(BlueprintType)
struct FServerGrantCharacterToUserRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Non-unique display name of the character being granted (1-20 characters in length). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterName;
    /** Type of the character being granted; statistics can be sliced based on this value. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterType;
};

USTRUCT(BlueprintType)
struct FServerGrantCharacterToUserResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier tagged to this character. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterStatisticsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        FString CharacterId;
    /** Statistics to be updated with the provided values. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Characters Models")
        UPlayFabJsonObject* CharacterStatistics;
};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterStatisticsResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Character Data
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerGetCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;
    /** Specific keys to search for in the custom user data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString Keys;
    /** The version that currently exists according to the caller. The call will return the data for all of the keys if the version in the system is greater than this. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 IfChangedFromDataVersion = 0;
};

USTRUCT(BlueprintType)
struct FServerGetCharacterDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;
    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 DataVersion = 0;
    /** User specific data for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* Data = nullptr;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;
};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterDataRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString PlayFabId;
    /** Unique PlayFab assigned ID for a specific character owned by a user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString CharacterId;
    /** Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace, are limited in size, and may not begin with a '!' character or be null. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        UPlayFabJsonObject* Data;
    /** Optional list of Data-keys to remove from UserData.  Some SDKs cannot insert null-values into Data due to language constraints.  Use this to delete the keys directly. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        FString KeysToRemove;
    /** Permission to be applied to all user data keys written in this request. Defaults to "private" if not set. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        EUserDataPermission Permission;
};

USTRUCT(BlueprintType)
struct FServerUpdateCharacterDataResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Indicates the current version of the data that has been set. This is incremented with every set call for that type of data (read-only, internal, etc). This version can be provided in Get calls to find updated data. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Character Data Models")
        int32 DataVersion = 0;
};


///////////////////////////////////////////////////////
// Guilds
//////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// PlayStream
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAddPlayerTagRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct FServerAddPlayerTagResult
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerGetAllActionGroupsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerGetAllActionGroupsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** List of Action Groups. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> ActionGroups;
};

USTRUCT(BlueprintType)
struct FServerGetAllSegmentsRequest
{
    GENERATED_USTRUCT_BODY()
public:
};

USTRUCT(BlueprintType)
struct FServerGetAllSegmentsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments for this title. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerSegmentsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of segments the requested player currently belongs to. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> Segments;
};

USTRUCT(BlueprintType)
struct FServerGetPlayersSegmentsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
};

USTRUCT(BlueprintType)
struct FServerGetPlayersInSegmentRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique identifier for this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString SegmentId;
    /** Number of seconds to keep the continuation token active. After token expiration it is not possible to continue paging results. Default is 300 (5 minutes). Maximum is 1,800 (30 minutes). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        int32 SecondsToLive = 0;
    /** Maximum number of profiles to load. Default is 1,000. Maximum is 10,000. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        int32 MaxBatchSize = 0;
    /** Continuation token if retrieving subsequent pages of results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString ContinuationToken;
};

USTRUCT(BlueprintType)
struct FServerGetPlayersInSegmentResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Count of profiles matching this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        int32 ProfilesInSegment = 0;
    /** Continuation token to use to retrieve subsequent pages of results. If token returns null there are no more results. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString ContinuationToken;
    /** Array of player profiles in this segment. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        TArray<UPlayFabJsonObject*> PlayerProfiles;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerTagsRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Optional namespace to filter results by */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString Namespace;
};

USTRUCT(BlueprintType)
struct FServerGetPlayerTagsResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Canonical tags (including namespace and tag's name) for the requested user */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString Tags;
};

USTRUCT(BlueprintType)
struct FServerRemovePlayerTagRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Unique PlayFab assigned ID of the user on whom the operation will be performed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString PlayFabId;
    /** Unique tag for player profile. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | PlayStream Models")
        FString TagName;
};

USTRUCT(BlueprintType)
struct FServerRemovePlayerTagResult
{
    GENERATED_USTRUCT_BODY()
public:
};


///////////////////////////////////////////////////////
// Platform Specific Methods
//////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FServerAwardSteamAchievementRequest
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of achievements to grant and the users to whom they are to be granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> Achievements;
};

USTRUCT(BlueprintType)
struct FServerAwardSteamAchievementResult
{
    GENERATED_USTRUCT_BODY()
public:
    /** Array of achievements granted. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayFab | Server | Platform Specific Methods Models")
        TArray<UPlayFabJsonObject*> AchievementResults;
};

