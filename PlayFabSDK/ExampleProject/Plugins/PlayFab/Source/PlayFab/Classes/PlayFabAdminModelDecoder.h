#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
// Automatically generated model file for the UE4 PlayFab plugin.
// This model file contains the request and response USTRUCTS
//
// API: Admin
//////////////////////////////////////////////////////////////////////////////////////////////

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayFabEnums.h"
#include "PlayFabAdminModels.h"
#include "PlayFabAdminModelDecoder.generated.h"

class UPlayFabJsonObject;

UCLASS()
class PLAYFAB_API UPlayFabAdminModelDecoder : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //////////////////////////////////////////////////////////////////////////
    // Generated PlayFab Admin API Functions
    //////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    // Authentication
    //////////////////////////////////////////////////////

    /** Decode the GetPolicyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication Models")
        static FAdminGetPolicyResponse decodeGetPolicyResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdatePolicyResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Authentication Models")
        static FAdminUpdatePolicyResponse decodeUpdatePolicyResponseResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Account Management
    //////////////////////////////////////////////////////

    /** Decode the BanUsersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminBanUsersResult decodeBanUsersResultResponse(UPlayFabJsonObject* response);

    /** Decode the LookupUserAccountInfoResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminLookupUserAccountInfoResult decodeLookupUserAccountInfoResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserBansResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminGetUserBansResult decodeGetUserBansResultResponse(UPlayFabJsonObject* response);

    /** Decode the BlankResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminBlankResult decodeBlankResultResponse(UPlayFabJsonObject* response);

    /** Decode the RevokeAllBansForUserResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminRevokeAllBansForUserResult decodeRevokeAllBansForUserResultResponse(UPlayFabJsonObject* response);

    /** Decode the RevokeBansResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminRevokeBansResult decodeRevokeBansResultResponse(UPlayFabJsonObject* response);

    /** Decode the SendAccountRecoveryEmailResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminSendAccountRecoveryEmailResult decodeSendAccountRecoveryEmailResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateBansResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminUpdateBansResult decodeUpdateBansResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateUserTitleDisplayNameResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Account Management Models")
        static FAdminUpdateUserTitleDisplayNameResult decodeUpdateUserTitleDisplayNameResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Player Data Management
    //////////////////////////////////////////////////////

    /** Decode the CreatePlayerStatisticDefinitionResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminCreatePlayerStatisticDefinitionResult decodeCreatePlayerStatisticDefinitionResultResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteUsersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminDeleteUsersResult decodeDeleteUsersResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetDataReportResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminGetDataReportResult decodeGetDataReportResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerStatisticDefinitionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminGetPlayerStatisticDefinitionsResult decodeGetPlayerStatisticDefinitionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerStatisticVersionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminGetPlayerStatisticVersionsResult decodeGetPlayerStatisticVersionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminGetUserDataResult decodeGetUserDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the IncrementPlayerStatisticVersionResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminIncrementPlayerStatisticVersionResult decodeIncrementPlayerStatisticVersionResultResponse(UPlayFabJsonObject* response);

    /** Decode the RefundPurchaseResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminRefundPurchaseResponse decodeRefundPurchaseResponseResponse(UPlayFabJsonObject* response);

    /** Decode the ResetUserStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminResetUserStatisticsResult decodeResetUserStatisticsResultResponse(UPlayFabJsonObject* response);

    /** Decode the ResolvePurchaseDisputeResponse response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminResolvePurchaseDisputeResponse decodeResolvePurchaseDisputeResponseResponse(UPlayFabJsonObject* response);

    /** Decode the UpdatePlayerStatisticDefinitionResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminUpdatePlayerStatisticDefinitionResult decodeUpdatePlayerStatisticDefinitionResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateUserDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Data Management Models")
        static FAdminUpdateUserDataResult decodeUpdateUserDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Title-Wide Data Management
    //////////////////////////////////////////////////////

    /** Decode the AddNewsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminAddNewsResult decodeAddNewsResultResponse(UPlayFabJsonObject* response);

    /** Decode the DeleteStoreResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminDeleteStoreResult decodeDeleteStoreResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCatalogItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminGetCatalogItemsResult decodeGetCatalogItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPublisherDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminGetPublisherDataResult decodeGetPublisherDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetRandomResultTablesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminGetRandomResultTablesResult decodeGetRandomResultTablesResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetStoreItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminGetStoreItemsResult decodeGetStoreItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTitleDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminGetTitleDataResult decodeGetTitleDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListVirtualCurrencyTypesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminListVirtualCurrencyTypesResult decodeListVirtualCurrencyTypesResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateCatalogItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminUpdateCatalogItemsResult decodeUpdateCatalogItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateStoreItemsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminUpdateStoreItemsResult decodeUpdateStoreItemsResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetTitleDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminSetTitleDataResult decodeSetTitleDataResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetupPushNotificationResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminSetupPushNotificationResult decodeSetupPushNotificationResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateRandomResultTablesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Title-Wide Data Management Models")
        static FAdminUpdateRandomResultTablesResult decodeUpdateRandomResultTablesResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Player Item Management
    //////////////////////////////////////////////////////

    /** Decode the ModifyUserVirtualCurrencyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management Models")
        static FAdminModifyUserVirtualCurrencyResult decodeModifyUserVirtualCurrencyResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetUserInventoryResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management Models")
        static FAdminGetUserInventoryResult decodeGetUserInventoryResultResponse(UPlayFabJsonObject* response);

    /** Decode the GrantItemsToUsersResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management Models")
        static FAdminGrantItemsToUsersResult decodeGrantItemsToUsersResultResponse(UPlayFabJsonObject* response);

    /** Decode the RevokeInventoryResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Player Item Management Models")
        static FAdminRevokeInventoryResult decodeRevokeInventoryResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Matchmaking
    //////////////////////////////////////////////////////

    /** Decode the GetMatchmakerGameInfoResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking Models")
        static FAdminGetMatchmakerGameInfoResult decodeGetMatchmakerGameInfoResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetMatchmakerGameModesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking Models")
        static FAdminGetMatchmakerGameModesResult decodeGetMatchmakerGameModesResultResponse(UPlayFabJsonObject* response);

    /** Decode the ModifyMatchmakerGameModesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Matchmaking Models")
        static FAdminModifyMatchmakerGameModesResult decodeModifyMatchmakerGameModesResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Custom Server Management
    //////////////////////////////////////////////////////

    /** Decode the AddServerBuildResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management Models")
        static FAdminAddServerBuildResult decodeAddServerBuildResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetServerBuildInfoResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management Models")
        static FAdminGetServerBuildInfoResult decodeGetServerBuildInfoResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetServerBuildUploadURLResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management Models")
        static FAdminGetServerBuildUploadURLResult decodeGetServerBuildUploadURLResultResponse(UPlayFabJsonObject* response);

    /** Decode the ListBuildsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management Models")
        static FAdminListBuildsResult decodeListBuildsResultResponse(UPlayFabJsonObject* response);

    /** Decode the ModifyServerBuildResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management Models")
        static FAdminModifyServerBuildResult decodeModifyServerBuildResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemoveServerBuildResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Custom Server Management Models")
        static FAdminRemoveServerBuildResult decodeRemoveServerBuildResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Shared Group Data
    //////////////////////////////////////////////////////

    /** Decode the SetPublisherDataResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Shared Group Data Models")
        static FAdminSetPublisherDataResult decodeSetPublisherDataResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Server-Side Cloud Script
    //////////////////////////////////////////////////////

    /** Decode the GetCloudScriptRevisionResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        static FAdminGetCloudScriptRevisionResult decodeGetCloudScriptRevisionResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCloudScriptVersionsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        static FAdminGetCloudScriptVersionsResult decodeGetCloudScriptVersionsResultResponse(UPlayFabJsonObject* response);

    /** Decode the SetPublishedRevisionResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        static FAdminSetPublishedRevisionResult decodeSetPublishedRevisionResultResponse(UPlayFabJsonObject* response);

    /** Decode the UpdateCloudScriptResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Server-Side Cloud Script Models")
        static FAdminUpdateCloudScriptResult decodeUpdateCloudScriptResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Content
    //////////////////////////////////////////////////////

    /** Decode the GetContentListResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content Models")
        static FAdminGetContentListResult decodeGetContentListResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetContentUploadUrlResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Content Models")
        static FAdminGetContentUploadUrlResult decodeGetContentUploadUrlResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // Characters
    //////////////////////////////////////////////////////

    /** Decode the ResetCharacterStatisticsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | Characters Models")
        static FAdminResetCharacterStatisticsResult decodeResetCharacterStatisticsResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // PlayStream
    //////////////////////////////////////////////////////

    /** Decode the AddPlayerTagResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream Models")
        static FAdminAddPlayerTagResult decodeAddPlayerTagResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetAllActionGroupsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream Models")
        static FAdminGetAllActionGroupsResult decodeGetAllActionGroupsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetAllSegmentsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream Models")
        static FAdminGetAllSegmentsResult decodeGetAllSegmentsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerSegmentsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream Models")
        static FAdminGetPlayerSegmentsResult decodeGetPlayerSegmentsResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayersInSegmentResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream Models")
        static FAdminGetPlayersInSegmentResult decodeGetPlayersInSegmentResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetPlayerTagsResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream Models")
        static FAdminGetPlayerTagsResult decodeGetPlayerTagsResultResponse(UPlayFabJsonObject* response);

    /** Decode the RemovePlayerTagResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | PlayStream Models")
        static FAdminRemovePlayerTagResult decodeRemovePlayerTagResultResponse(UPlayFabJsonObject* response);



    ///////////////////////////////////////////////////////
    // ScheduledTask
    //////////////////////////////////////////////////////

    /** Decode the EmptyResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask Models")
        static FAdminEmptyResult decodeEmptyResultResponse(UPlayFabJsonObject* response);

    /** Decode the CreateTaskResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask Models")
        static FAdminCreateTaskResult decodeCreateTaskResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetActionsOnPlayersInSegmentTaskInstanceResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask Models")
        static FAdminGetActionsOnPlayersInSegmentTaskInstanceResult decodeGetActionsOnPlayersInSegmentTaskInstanceResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetCloudScriptTaskInstanceResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask Models")
        static FAdminGetCloudScriptTaskInstanceResult decodeGetCloudScriptTaskInstanceResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTaskInstancesResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask Models")
        static FAdminGetTaskInstancesResult decodeGetTaskInstancesResultResponse(UPlayFabJsonObject* response);

    /** Decode the GetTasksResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask Models")
        static FAdminGetTasksResult decodeGetTasksResultResponse(UPlayFabJsonObject* response);

    /** Decode the RunTaskResult response object*/
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Admin | ScheduledTask Models")
        static FAdminRunTaskResult decodeRunTaskResultResponse(UPlayFabJsonObject* response);



};
