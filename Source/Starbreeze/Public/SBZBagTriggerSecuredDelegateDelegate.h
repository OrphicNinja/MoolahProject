#pragma once
#include "CoreMinimal.h"
#include "SBZBagHandle.h"
#include "SBZBagTriggerSecuredDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_TwoParams(FSBZBagTriggerSecuredDelegate, FSBZBagHandle, BagHandle, int32, Count);

