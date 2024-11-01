#pragma once
#include "CoreMinimal.h"
#include "SBZBaseMenuWidget.h"
#include "SBZActionPhaseMenuWidget.generated.h"

class USBZMenuNavBar;

UCLASS(Blueprintable, EditInlineNew)
class USBZActionPhaseMenuWidget : public USBZBaseMenuWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZMenuNavBar* Widget_NavBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MenuStackValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsPaused;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsMenuShown;
    
public:
    USBZActionPhaseMenuWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void ToggleShowMenu();
    
    UFUNCTION(BlueprintCallable)
    void SetMenuShown(bool bIsShown);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMenuShown(bool bIsShown);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnPausedChanged(bool bInIsPaused);
    
};

