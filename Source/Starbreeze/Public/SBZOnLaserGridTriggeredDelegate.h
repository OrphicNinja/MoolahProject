#pragma once
#include "CoreMinimal.h"
#include "SBZOnLaserGridTriggeredDelegate.generated.h"

class ASBZLaserGrid;
class ASBZPlayerCharacter;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSBZOnLaserGridTriggered, ASBZLaserGrid*, LaserGrid, ASBZPlayerCharacter*, PlayerCharacter);

