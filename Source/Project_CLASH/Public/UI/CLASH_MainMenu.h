// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/CLASH_BaseWiget.h"
#include "CLASH_MainMenu.generated.h"

class UCommonButtonBase;

UCLASS()
class PROJECT_CLASH_API UCLASH_MainMenu : public UCLASH_BaseWiget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UCommonButtonBase> StartButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UCommonButtonBase> QuitButton;

	UFUNCTION()
	void OnStartButtonClicked();

	UFUNCTION()
	void OnQuitButtonClicked();

protected:
	virtual void NativeConstruct() override;
};
