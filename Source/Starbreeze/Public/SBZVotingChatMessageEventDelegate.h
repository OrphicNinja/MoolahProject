#pragma once
#include "CoreMinimal.h"
#include "SBZVotingChatEvent.h"
#include "SBZVotingChatMessageEventDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZVotingChatMessageEvent, const FSBZVotingChatEvent&, ChatEventData);

