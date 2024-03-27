#pragma once
#include "CoreMinimal.h"
#include "Perception/AISightTargetInterface.h"
#include "GenericTeamAgentInterface.h"
#include "GenericTeamAgentInterface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Character.h"
#include "Engine/EngineTypes.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "EPD3HeistState.h"
#include "ESBZAIVisibilityNodeComputationFrequency.h"
#include "ESBZCharacterStance.h"
#include "ESBZEquipState.h"
#include "ESBZHumanShieldInstigatorState.h"
#include "ESBZHurtReactionType.h"
#include "ESBZReloadState.h"
#include "SBZAIVisibilityLeafNode.h"
#include "SBZAIVisibilityRelevant.h"
#include "SBZAgilityTraversalTrajectory.h"
#include "SBZBagHandle.h"
#include "SBZBoneDamageMultiplier.h"
#include "SBZCharacterAnimEventActiveDelegateDelegate.h"
#include "SBZCharacterMeshScaleData.h"
#include "SBZDropCharacterSound.h"
#include "SBZEquippableConfig.h"
#include "SBZEquippableRuntime.h"
#include "SBZHumanShieldSlotParameters.h"
#include "SBZHurtReactionPrediction.h"
#include "SBZMontageSectionSwitchRequest.h"
#include "SBZPawnInterface.h"
#include "SBZPawnLifetime.h"
#include "SBZProjectileInterface.h"
#include "SBZReplicatedMontage.h"
#include "SBZReplicatedReloadState.h"
#include "SBZRoomVolumeInterface.h"
#include "SBZSharedAnimBehavior.h"
#include "SBZTagReactionEffect.h"
#include "SBZTypeInterface.h"
#include "SBZVoiceComponentInterface.h"
#include "SBZZiplinerInterface.h"
#include "Templates/SubclassOf.h"
#include "SBZCharacter.generated.h"

class AActor;
class AController;
class ASBZCharacter;
class ASBZCosmeticProp;
class ASBZEquippable;
class ASBZGrenadeProjectile;
class ASBZMask;
class ASBZRoomVolume;
class ASBZThrowable;
class ASBZZipline;
class ASBZZiplineMotor;
class UAkAudioEvent;
class UAkComponent;
class UAnimInstance;
class UAnimMontage;
class UAnimSequence;
class UDamageType;
class UPaperSprite;
class UPhysicalMaterial;
class UPhysicsAsset;
class UPrimitiveComponent;
class USBZAbilitySystemComponent;
class USBZBaseCharacterAnimationCollection;
class USBZCarryType;
class USBZCharacterAbilityData;
class USBZCharacterAnimationDataTP;
class USBZCharacterFootStepComponent;
class USBZCharacterInteractableComponent;
class USBZCharacterMantlingComponent;
class USBZCharacterMovementSettings;
class USBZCharacterSlidingComponent;
class USBZCharacterVaultingComponent;
class USBZCharacterVoiceComponent;
class USBZDamageTracker;
class USBZDialogBodyGesturesData;
class USBZEmotionMapping;
class USBZEventReactionComponent;
class USBZFacialAnimationCollection;
class USBZHurtReaction;
class USBZLifeActionAffinitytData;
class USBZMeleeComponent;
class USBZMeleeDamageData;
class USBZOutlineAsset;
class USBZOutlineComponent;
class USBZTagReactionAsset;
class USBZVoiceCommentDataAsset;
class USBZZiplineAudioController;

UCLASS(Blueprintable, NotPlaceable)
class STARBREEZE_API ASBZCharacter : public ACharacter, public IAbilitySystemInterface, public ISBZPawnLifetime, public IGenericTeamAgentInterface, public ISBZAIVisibilityRelevant, public IAISightTargetInterface, public ISBZVoiceComponentInterface, public ISBZRoomVolumeInterface, public IGameplayTagAssetInterface, public ISBZPawnInterface, public ISBZProjectileInterface, public ISBZTypeInterface, public ISBZZiplinerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZCharacterAnimEventActiveDelegate OnAnimEventActiveDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZVoiceCommentDataAsset* MarkedVoiceComment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZOutlineAsset* MarkedOutline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZOutlineComponent* OutlineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZCosmeticProp*> AttachedCosmeticProps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZCarryType* CarryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZCarryType* HumanShieldCarryType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UPhysicalMaterial>, TWeakObjectPtr<UPhysicalMaterial>> DeathImpactMaterialOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPhysicalMaterial*> DeathImpactMaterialOverridesArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZZiplineAudioController* ZiplineAudioController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASBZZiplineMotor> ZiplineMotorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZZiplineMotor* CurrentZiplineMotor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ZiplineAttachmentBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZCharacterMeshScaleData MeshScaleData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_RandomMeshScaleEnabled, meta=(AllowPrivateAccess=true))
    bool bRandomMeshScaleEnabled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AdditiveBoundExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RagdollAdditiveBoundExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USBZEventReactionComponent* EventReactionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> BagActorArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_BagHandleArray, meta=(AllowPrivateAccess=true))
    TArray<FSBZBagHandle> BagHandleArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 MaxCarryBagCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<USBZCarryType*> CurrentCarryTypeArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FSBZReplicatedMontage ReplicatedMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsAlive, meta=(AllowPrivateAccess=true))
    uint8 bIsAlive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsRagdolled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsLocallyControlled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsRunning: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsJumping: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsTargeting: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsHurtReactionScope: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsHurtReactionScopeStackAllowedOnce: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsPlayReady: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsCarried: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsCarriedPredicted: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsCarriedDropAnimation: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsDropAndCarryScope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsCarryChangedUsingInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ReplicatedReloadState, meta=(AllowPrivateAccess=true))
    FSBZReplicatedReloadState ReplicatedReloadState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESBZReloadState StartReloadState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsCurrentAnimationMagazineRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName LastReloadAnimationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* LastLocalReloadMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* LastRecoilMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZCharacterMovementSettings* MovementSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Stance, meta=(AllowPrivateAccess=true))
    ESBZCharacterStance Stance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CompatibleStances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxStartAimOffsetYawDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAimOffsetYawDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxStartAimOffsetYawDegreesTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAimOffsetYawDegreesTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    uint8 RemoteViewYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAbilitySystemComponent* AbilitySystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSBZEquippableConfig> EquippableConfigArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSBZEquippableConfig> LoadedEquippableConfigArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CurrentEquippableIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastEquippableIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastRequiredEquippableIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZEquippable*> EquippableArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZEquippable*> PendingReplicatedEquippableArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZEquippableConfig CurrentEquippableConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZEquippableRuntime CurrentEquippableRuntime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZEquippable* CurrentEquippable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSBZEquippableRuntime> EquippableRuntimeArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESBZEquipState EquipState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_EquipStateAndIndex, meta=(AllowPrivateAccess=true))
    uint8 EquipStateAndIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EquippableAttachementSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> LinkedAnimationClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZBaseCharacterAnimationCollection* AnimationCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZFacialAnimationCollection* FacialAnimationCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZEmotionMapping* EmotionMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZCharacterAnimationDataTP* AnimationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZLifeActionAffinitytData* DefaultLifeActionAffinityData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZLifeActionAffinitytData* RandomizedMeshScaleLifeActionAffinityData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanEverHaveFacialAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSBZMontageSectionSwitchRequest> MontageSectionSwitchRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 TargetEquippableIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialEquippableIndex;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int8 ForbiddenEquippableIndexCountArray[7];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int8 EquippableVisibleCount;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int8 EquippedCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsInitialEquipped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FGenericTeamId TeamId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZCharacterVoiceComponent* VoiceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USBZDamageTracker* DamageTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZCharacterFootStepComponent* FootStepComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZCharacterSlidingComponent* SlidingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZCharacterMantlingComponent* MantlingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZCharacterVaultingComponent* VaultingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESBZAIVisibilityNodeComputationFrequency AIVisibilityNodeComputationFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZAIVisibilityLeafNode AIVisibilityNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZCharacterAbilityData* AbilityData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FHitResult FloorHitLeftFoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FHitResult FloorHitRightFoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FSBZBoneDamageMultiplier> BoneDamageMultiplierMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZTagReactionAsset* TagReactionAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USBZTagReactionAsset* CurrentTagReactionAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESBZCharacterStance, USBZTagReactionAsset*> TagReactionStanceMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSBZTagReactionEffect> CurrentTagReactionEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* LastTagReactionMontage;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZHurtReaction* HurtReactionArray[24];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval SprintForwardHurtVelocityInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LandSoundEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZDropCharacterSound VictimDropCharacterSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZDropCharacterSound InstigatorDropCharacterSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinInteractionDurationToUnequip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentThrowableIndex, meta=(AllowPrivateAccess=true))
    int32 CurrentThrowableIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> GadgetIndexArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> GadgetMaxIndexArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentPlaceableIndex, meta=(AllowPrivateAccess=true))
    int32 CurrentPlaceableIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZCharacterInteractableComponent* Interactable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZMeleeComponent* MeleeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZMeleeDamageData* MeleeDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* CurrentCarryActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZCharacter* CurrentCarryInstigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CarryActorSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* PhysicsAssetWhenCarried;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* PhysicsAssetWhenNotCarried;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimClassWhenCarriedDead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HumanShieldInstigatorState, meta=(AllowPrivateAccess=true))
    ESBZHumanShieldInstigatorState HumanShieldInstigatorState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform OffsetWhenCarried;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform OffsetWhenHumanShield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HumanShieldInstigatorAcceptableRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSBZHumanShieldSlotParameters> HumanShieldSlotParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZVoiceCommentDataAsset* MeleeComment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* CurrentHumanShieldInstigatorEnterMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarryingFromCrouchAcceptableRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Seed, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZSharedAnimBehavior SharedAnimBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AController* LastController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CharacterTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USBZDialogBodyGesturesData* DialogBodyGesturesData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* ForcedFacialAnimaton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CharacterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZMask* EquippedMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPaperSprite* DisplayIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer HitImmunityGrantingTags;
    
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HurtReactionOffset[24];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastAppliedHurtReactionIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESBZHurtReactionType CurrentHurtReactionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HurtReactionEndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PredictedHurtReactionEndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* CurrentMeleeMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZRoomVolume*> RoomVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZRoomVolume* LastKnownRoom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ExplosionLineTraceBoneArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeadBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StatisticName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StatisticKillString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarryWeightTierOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZThrowable* CurrentlyUsedThrowable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZThrowable*> ReplicatedThrowableArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZGrenadeProjectile*> ReplicatedGrenadeProjectileArray;
    
public:
    ASBZCharacter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetStance(ESBZCharacterStance InStance);
    
    UFUNCTION(Reliable, Server)
    void Server_TransferBagFrom(ASBZCharacter* ToCharacter);
    
protected:
    UFUNCTION(Reliable, Server)
    void Server_SetEquipStateAndIndex(uint8 InEquipStateAndIndex);
    
    UFUNCTION(Reliable, Server)
    void Server_OnThrowCarryActorFailed(uint32 NetID);
    
    UFUNCTION(Reliable, Server)
    void Server_OnPickupCarryActorFailed(uint32 NetID);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void Server_HumanShieldInstigatorSlotReached();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveLooseGameplayTags(const FGameplayTagContainer& GameplayTags, int32 Count);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RemoveLooseGameplayTag(const FGameplayTag& GameplayTag, int32 Count);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStopZipline(const ASBZZipline* Zipline, bool bIsMovingZiplineForward);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStopTraversal(const FSBZAgilityTraversalTrajectory& Trajectory);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStopSlide();
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStartZipline(const ASBZZipline* Zipline, bool bIsMovingZiplineForward);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStartTraversal(const FSBZAgilityTraversalTrajectory& Trajectory);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStartSlide();
    
protected:
    UFUNCTION()
    void OnReplicatedEquippableDestroyedOnClient(AActor* InEquippableActor);
    
public:
    UFUNCTION()
    void OnRep_Stance(ESBZCharacterStance InStance);
    
protected:
    UFUNCTION()
    void OnRep_Seed();
    
    UFUNCTION()
    void OnRep_ReplicatedReloadState(const FSBZReplicatedReloadState& OldReplicatedReloadState);
    
public:
    UFUNCTION()
    void OnRep_RandomMeshScaleEnabled();
    
protected:
    UFUNCTION()
    void OnRep_IsAlive();
    
    UFUNCTION()
    void OnRep_HumanShieldInstigatorState();
    
    UFUNCTION()
    void OnRep_EquipStateAndIndex();
    
    UFUNCTION()
    void OnRep_CurrentThrowableIndex(int32 OldThrowableIndex);
    
    UFUNCTION()
    void OnRep_CurrentPlaceableIndex(int32 OldPlaceableIndex);
    
    UFUNCTION()
    void OnRep_BagHandleArray(const TArray<FSBZBagHandle>& OldBagHandleArray);
    
private:
    UFUNCTION()
    void OnEquipStateTimerDone();
    
protected:
    UFUNCTION()
    void OnCharacterMontageInstanceEnded(int32 AnimMontageInstanceID, bool bInterrupted);
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SwitchMontageSection(UAnimMontage* Montage, const FName& SectionName);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_StopTargeting();
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_StopRecoil(bool bWasCancelled);
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_StopOverrideMaxWalkSpeed();
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_StopMontage(UAnimMontage* Montage, bool bAllowExitSectionSwitch);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_StartTargeting();
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SnapVictimOntoInstigator(const FVector& SnapLocation, const ASBZCharacter* HSInstigator);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetStance(ESBZCharacterStance NewStance);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetReloadState(const FSBZReplicatedReloadState& InReplicatedReloadState);
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetMontageNextSection(UAnimMontage* Montage, const FName& NextSectionName);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetMarked(bool bIsMarked);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetEquipStateAndIndex(uint8 InEquipStateAndIndex);
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetEnableRandomMeshScale(bool bInEnableRandomMeshScale);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetCurrentThrowableIndex(int32 NewThrowableIndex);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetCurrentPlaceableIndex(int32 NewPlaceableIndex);
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetActiveGadget(int32 NewIndex);
    
private:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_PredictedRagdollDenied(int32 HurtReactionIndex);
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_PlayMontageMoveTo(UAnimMontage* Montage, const TArray<FTransform>& TargetTransforms, bool bDisableAutoBlendOut);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_PlayMontageMoveMulti(FName MontageName, const TArray<FTransform>& TargetTransforms);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_PlayMontageMove(FName MontageName, const FVector& EndMoveToWorldPosition, float PlayRate);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_PlayMontage(UAnimMontage* Montage, bool bPlayOnDedicatedServer, bool bStopAllActiveMontages);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_OverrideMaxWalkSpeed(float MaxWalkSpeed);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_OnThrowCarryActor(uint32 NetID);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_OnPickupCarryActor(uint32 NetID);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_OnKill();
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_HumanShieldInstigatorSlotReached();
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_ExplodedInHand(int32 Index);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_EnableThrowState();
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_DisableThrowState();
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_CancelMelee();
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_ApplyHurtReaction(const FSBZHurtReactionPrediction& HurtReactionPrediction);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_ActivateMelee();
    
    UFUNCTION()
    void HandleTakePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser);
    
    UFUNCTION(BlueprintPure)
    int32 GetSeed() const;
    
    UFUNCTION(BlueprintPure)
    ASBZRoomVolume* GetLastKnownRoom() const;
    
    UFUNCTION(BlueprintPure)
    USBZCarryType* GetLastCurrentCarryType() const;
    
    UFUNCTION(BlueprintPure)
    FSBZBagHandle GetLastBagHandle() const;
    
    UFUNCTION(BlueprintPure)
    ASBZRoomVolume* GetCurrentRoom_Implementation() const;
    
    UFUNCTION(Client, Reliable)
    void Client_OnThrowCarryActorFailed(uint32 NetID);
    
protected:
    UFUNCTION(Client, Reliable)
    void Client_OnPickupCarryActorFailed(uint32 NetID);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void BP_OnKill();
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_OnHeistStateChanged(EPD3HeistState OldState, EPD3HeistState NewState);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddLooseGameplayTags(const FGameplayTagContainer& GameplayTags, int32 Count);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddLooseGameplayTag(const FGameplayTag& GameplayTag, int32 Count);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(GetOwnedGameplayTags,);
    
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
    {
        return AbilitySystem;
    }
};

