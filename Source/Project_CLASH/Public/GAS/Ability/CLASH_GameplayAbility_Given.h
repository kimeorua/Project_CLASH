// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Ability/CLASH_GameplayAbility_Base.h"
#include "CLASH_GameplayAbility_Given.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_CLASH_API UCLASH_GameplayAbility_Given : public UCLASH_GameplayAbility_Base
{
	GENERATED_BODY()

private:
	UCLASH_GameplayAbility_Given();

public:
	void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
};
