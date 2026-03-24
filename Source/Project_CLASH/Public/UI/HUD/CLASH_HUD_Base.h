// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CLASH_HUD_Base.generated.h"

class UProgressBar;
class UImage;
class UUniformGridPanel;
class UCLASH_WillBeadWidget;

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

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UUniformGridPanel>WillBaedsPanel;

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Widgets", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCLASH_WillBeadWidget>WillBaedWidgetClass;

public:
	UFUNCTION()
	void UpdateFoucsBar(float Percent);

	UFUNCTION()
	void CreateWillBeads(float WillCount);
};
