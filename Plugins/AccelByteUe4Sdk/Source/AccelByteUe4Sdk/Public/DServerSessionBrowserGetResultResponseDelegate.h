#pragma once
#include "CoreMinimal.h"
#include "AccelByteModelsSessionBrowserGetResult.h"
#include "DServerSessionBrowserGetResultResponseDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FDServerSessionBrowserGetResultResponse, FAccelByteModelsSessionBrowserGetResult, Response);

