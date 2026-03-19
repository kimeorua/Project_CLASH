// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/GASConfig/CLASH_AbilitySystemConfig.h"
#include "CLASH_PlayerAbilitySystemConfig.generated.h"

class UCLASH_AbilitySystemComponent;
class UCLASH_GameplayAbility_Base;

USTRUCT(BlueprintType)
struct FCLASH_AbilityBindInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Ability", meta = (AllowedClasses = "/Script/Project_CLASH.CLASH_GameplayAbility_Trigger"))
	TSubclassOf<UCLASH_GameplayAbility_Base> AbilityClass;

	UPROPERTY(EditAnywhere, Category = "Ability")
	FGameplayTag InputTag;
};

UCLASS()
class PROJECT_CLASH_API UCLASH_PlayerAbilitySystemConfig : public UCLASH_AbilitySystemConfig
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AbilityDataAsset|InputAbility")
	TArray<FCLASH_AbilityBindInfo>InputAbilities;

	void GrantAbilitiesWithTags(const TArray<FCLASH_AbilityBindInfo>& InAbilitiesToGive, UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
