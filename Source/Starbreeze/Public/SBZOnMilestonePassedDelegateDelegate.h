#pragma once
#include "CoreMinimal.h"
#include "ESBZMilestoneType.h"
#include "SBZOnMilestonePassedDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSBZOnMilestonePassedDelegate, const ESBZMilestoneType, MilestoneType, const FString&, MilestoneName);

