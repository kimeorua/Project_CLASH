// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/UI/CLASH_UIComponent_Base.h"
#include "CLASH_UIComponent_Player.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAwakeningBarChanged, float, Percent);

class UCLASH_HUD_Player;

UCLASS()
class PROJECT_CLASH_API UCLASH_UIComponent_Player : public UCLASH_UIComponent_Base
{
	GENERATED_BODY()

public:
	UCLASH_UIComponent_Player();
	FOnAwakeningBarChanged OnAwakeningBarChanged;

protected:
	virtual void BeginPlay() override;
	virtual void CreateHUD() override;
	virtual void SettingInitValue() override;
	virtual void BindUpdate(UAbilitySystemComponent* InASC) override;

private:
	UFUNCTION()
	void OnCurrentAwakeningChanged(float Percent);
};
