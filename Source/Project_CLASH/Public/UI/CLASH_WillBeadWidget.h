// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CLASH_WillBeadWidget.generated.h"

class UImage;

UCLASS()
class PROJECT_CLASH_API UCLASH_WillBeadWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, Category = "HUD|Widgets", meta = (BindWidget, AllowPrivateAccess = "true"))
	TObjectPtr<UImage> WillBaed;
};