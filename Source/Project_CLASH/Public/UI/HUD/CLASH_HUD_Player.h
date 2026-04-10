// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/HUD/CLASH_HUD_Base.h"
#include "CLASH_HUD_Player.generated.h"

class UCLASH_ProgressBar;
class UCLASH_UIComponent_Player;

UCLASS()
class PROJECT_CLASH_API UCLASH_HUD_Player : public UCLASH_HUD_Base
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UCLASH_ProgressBar> AwakeningGauge;

public:
	UFUNCTION()
	void UpdateAwakeningGauge(float Percent);

	void BindToPlayerUIComponent(UCLASH_UIComponent_Player* TargetComponent);
};
