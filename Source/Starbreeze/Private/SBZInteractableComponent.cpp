#include "SBZInteractableComponent.h"
#include "Net/UnrealNetwork.h"

USBZInteractableComponent::USBZInteractableComponent() {
    this->OnStart2DAudioEvent = NULL;
    this->OnFinish2DAudioEvent = NULL;
    this->OnCancel2DAudioEvent = NULL;
    this->OnStart3DAudioEvent = NULL;
    this->OnFinish3DAudioEvent = NULL;
    this->OnCancel3DAudioEvent = NULL;
    this->LoopingAkComponent = NULL;
    this->GameplayInteractionQuery = NULL;
    this->SharedKeyItemQuery = NULL;
    this->PredictedInteractor = NULL;
    this->PredictionTimeoutSeconds = -1.00f;
    this->bCurrentlyInteracting = false;
    this->bInteractionEnabled = true;
    this->bLocalEnabled = true;
    this->bPredictLocalEnd = false;
    this->bSyncInteracting = true;
    this->bSyncAbortEvent = false;
    this->bRepeatable = false;
    this->bClearInteractorsOnComplete = true;
    this->bIsAllowedInCasing = false;
    this->bIsIllegal = true;
    this->CompletedComment = NULL;
    FProperty* p_bReplicates = GetClass()->FindPropertyByName("bReplicates");
    *p_bReplicates->ContainerPtrToValuePtr<uint8>(this) = true;
}

void USBZInteractableComponent::Stop3DSound(UAkAudioEvent* AudioEvent) {
}

void USBZInteractableComponent::SetLocalEnabled(bool bEnabled) {
}

void USBZInteractableComponent::SetInteractionEnabled(bool bEnabled) {
}

void USBZInteractableComponent::SetDefaultsForTimed() {
}

void USBZInteractableComponent::SetDefaultsForInstant() {
}

void USBZInteractableComponent::Play3DSound(UAkAudioEvent* AudioEvent) {
}

void USBZInteractableComponent::OnSharedKeyItemTagChanged(const FSBZSharedKeyItemTagChangedEvent& SharedKeyItemTagChangedEventData) {
}

void USBZInteractableComponent::OnRep_InteractionEnabled(bool bOldInteractionEnabled) {
}

void USBZInteractableComponent::Multicast_SetInteractionEnabled_Implementation(bool bEnabled) {
}

void USBZInteractableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USBZInteractableComponent, bInteractionEnabled);
}

