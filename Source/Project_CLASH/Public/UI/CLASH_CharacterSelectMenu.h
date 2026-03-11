// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/CLASH_BaseWiget.h"
#include "UI/Interface/CLASH_InputConfigurable.h"
#include "CLASH_CharacterSelectMenu.generated.h"

class UCommonButtonBase;
class ACharacter;

UCLASS()
class PROJECT_CLASH_API UCLASH_CharacterSelectMenu : public UCLASH_BaseWiget, public ICLASH_InputConfigurable
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UCommonButtonBase> Select_1stButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	TObjectPtr<UCommonButtonBase> Select_2ndButton;

	UFUNCTION()
	void OnSelect_1stButtonClicked();

	UFUNCTION()
	void OnSelect_2ndButtonClicked();

	virtual bool ShouldShowMouseCursor() const override { return true; }

protected:
	virtual void NativeConstruct() override;

private:
	ACharacter* FindSelectedCharacter(FName Tag) const;
	void CharacterSetting(FName Tag);
};
