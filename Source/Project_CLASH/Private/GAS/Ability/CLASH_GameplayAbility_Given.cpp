// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/CLASH_GameplayAbility_Given.h"
#include "GAS/CLASH_AbilitySystemComponent.h"

#include "DebugHelper.h"

UCLASH_GameplayAbility_Given::UCLASH_GameplayAbility_Given()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	bRetriggerInstancedAbility = false;
}

void UCLASH_GameplayAbility_Given::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (ActorInfo && !Spec.IsActive())
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
	}
}

void UCLASH_GameplayAbility_Given::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (ActorInfo)
	{
		ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
	}
}
