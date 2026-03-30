// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/GASConfig/CLASH_PlayerAbilitySystemConfig.h"

#include "GAS/CLASH_AbilitySystemComponent.h"
#include "GAS/Ability/CLASH_GameplayAbility_Base.h"

void UCLASH_PlayerAbilitySystemConfig::GiveToAbilitySystemComponent(UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);
	GrantAbilitiesWithTags(InputAbilities, InASCToGive, ApplyLevel);
}

void UCLASH_PlayerAbilitySystemConfig::GrantAbilitiesWithTags(const TArray<FCLASH_AbilityBindInfo>& InAbilitiesToGive, UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	for (const FCLASH_AbilityBindInfo& Info : InAbilitiesToGive)
	{
		if (!Info.AbilityClass) continue;

		int32 InputID = static_cast<int32>(Info.InputID);
		FGameplayAbilitySpec Spec(Info.AbilityClass, ApplyLevel, InputID);
		Spec.SourceObject = InASCToGive->GetAvatarActor();
		FGameplayAbilitySpecHandle Handle = InASCToGive->GiveAbility(Spec);
		FGameplayTag InputTag = Info.InputTag;

		InASCToGive->RegisterAbilityWithTag(InputTag, Handle);
	}
}