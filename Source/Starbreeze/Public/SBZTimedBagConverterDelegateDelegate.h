#pragma once
#include "CoreMinimal.h"
#include "SBZTimedBagConverterDelegateDelegate.generated.h"

class ASBZTimedBagConverter;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZTimedBagConverterDelegate, ASBZTimedBagConverter*, BagConverter);

