#pragma once
#include "CoreMinimal.h"
#include "AccelByteModelsPartyDataNotif.h"
#include "DPartyWriteDataResponseDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FDPartyWriteDataResponse, FAccelByteModelsPartyDataNotif, Response);

