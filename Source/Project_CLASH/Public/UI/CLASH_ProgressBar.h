// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CLASH_ProgressBar.generated.h"

class UImage;
class UWidgetAnimation;

UCLASS()
class PROJECT_CLASH_API UCLASH_ProgressBar : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateBar(float Percent);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	void SetPrograssParmaeter(const FName ParameterName, const float NewValue);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UImage> Progress;

	UPROPERTY(EditAnywhere, Category  = "Value", meta = (AllowPrivateAccess = "true"))
	FName Current = FName("Current");

	UPROPERTY(EditAnywhere, Category = "Value", meta = (AllowPrivateAccess = "true"))
	FName Previos = FName("Previos");

	UPROPERTY(EditAnywhere, Category = "Value", meta = (AllowPrivateAccess = "true"))
	float InterSpeed = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Value", meta = (AllowPrivateAccess = "true"))
	float CurrentValue = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Value", meta = (AllowPrivateAccess = "true"))
	float CahcedValue = 1.0f;
};
