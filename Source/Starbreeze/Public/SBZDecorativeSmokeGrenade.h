#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "ESBZDecorativeSmokeState.h"
#include "SBZDecorativeSmokeGrenade.generated.h"

class UAkAudioEvent;
class UMeshComponent;
class UNiagaraComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASBZDecorativeSmokeGrenade : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* GasEffectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* DetonationEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayedExplosionTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SmokeState, meta=(AllowPrivateAccess=true))
    ESBZDecorativeSmokeState SmokeState;
    
public:
    ASBZDecorativeSmokeGrenade();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnSpawned();
    
protected:
    UFUNCTION()
    void OnRep_SmokeState();
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnHitGround();
    
    UFUNCTION()
    void OnActorHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_CreateSmokeCloud();
    
};

