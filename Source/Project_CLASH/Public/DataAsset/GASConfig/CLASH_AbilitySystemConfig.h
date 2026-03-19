// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "CLASH_AbilitySystemConfig.generated.h"

class UCLASH_AbilitySystemComponent;
class UCLASH_GameplayAbility_Base;
class UGameplayEffect;

UCLASS()
class PROJECT_CLASH_API UCLASH_AbilitySystemConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AbilityDataAsset|Effect")
	TArray < TSubclassOf<UGameplayEffect>> StartUpGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category = "AbilityDataAsset|GiveAbility", meta = (AllowedClasses = "/Script/Project_CLASH.CLASH_GameplayAbility_Given"))
	TArray<TSubclassOf<UCLASH_GameplayAbility_Base>> GivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "AbilityDataAsset|TriggerAbility", meta = (AllowedClasses = "/Script/Project_CLASH.CLASH_GameplayAbility_Trigger"))
	TArray<TSubclassOf<UCLASH_GameplayAbility_Base>> TriggeredAbilities;

	void GrantAbilities(TArray<TSubclassOf<UCLASH_GameplayAbility_Base>>& InAbilitiesToGive, UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
