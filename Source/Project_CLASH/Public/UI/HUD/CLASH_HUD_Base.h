// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CLASH_HUD_Base.generated.h"

class UProgressBar;
class UImage;

UCLASS()
class PROJECT_CLASH_API UCLASH_HUD_Base : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UProgressBar> FocusBar;

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UImage> CharacterPortrait;

public:
	UFUNCTION()
	void UpdateFoucsBar(float Percent);
};
