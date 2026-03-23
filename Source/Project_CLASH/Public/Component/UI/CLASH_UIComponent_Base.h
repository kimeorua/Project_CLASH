// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayEffectTypes.h"
#include "CLASH_UIComponent_Base.generated.h"

class UCLASH_HUD_Base;
class ACLASH_BaseCharacter;
class UAbilitySystemComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_CLASH_API UCLASH_UIComponent_Base : public UActorComponent
{
	GENERATED_BODY()

/* =========================
 * Basic
* ========================= */
public:	
	UCLASH_UIComponent_Base();

protected:
	virtual void BeginPlay() override;

/* =========================
 * HUD
* ========================= */
private:
	UPROPERTY(EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLASH_HUD_Base> HUDClass;

protected:
	UPROPERTY()
	TObjectPtr<UCLASH_HUD_Base> HUD;

	UPROPERTY()
	TObjectPtr <UAbilitySystemComponent>ASC;

	virtual void OnCurrentFocusChanged(const FOnAttributeChangeData& Data);
	virtual void SettingInitValue();

public:
	virtual void InitUIComponent(ACLASH_BaseCharacter* ClashCharacter);
};
