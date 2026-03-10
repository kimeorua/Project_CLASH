// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CLASH_BaseWiget.generated.h"

class APlayerController;

UCLASS()
class PROJECT_CLASH_API UCLASH_BaseWiget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	APlayerController* GetOwnerPlayerController() const;

protected:
	UPROPERTY()
	TObjectPtr<APlayerController> OwnerPC;

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;
};