// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayEffectTypes.h"
#include "CLASH_UIComponent_Base.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFoucsBarChanged, float, Percent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWiilCountCreated, float, WillCount);

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

	FOnFoucsBarChanged OnFoucsBarChanged;
	FOnWiilCountCreated OnWiilCountCreated;

protected:
	virtual void BeginPlay() override;

/* =========================
 * HUD
* ========================= */

protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLASH_HUD_Base> HUDClass;

	UPROPERTY()
	TObjectPtr <UAbilitySystemComponent>ASC;

	void OnCurrentFocusChanged(const FOnAttributeChangeData& Data);
	virtual void CreateHUD();
	virtual void SettingInitValue();
	virtual void BindUpdage(UAbilitySystemComponent* InASC);

public:
	void InitUIComponent(ACLASH_BaseCharacter* ClashCharacter);
};
