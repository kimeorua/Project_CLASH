// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/GASConfig/CLASH_AbilitySystemConfig.h"

#include "GAS/CLASH_AbilitySystemComponent.h"
#include "GAS/Ability/CLASH_GameplayAbility_Base.h"

void UCLASH_AbilitySystemConfig::GiveToAbilitySystemComponent(UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(GivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilitiesWithTags(TriggeredAbilities, InASCToGive, ApplyLevel);

	if (!StartUpGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass) continue;

			FGameplayEffectContextHandle ContextHandle = InASCToGive->MakeEffectContext();
			ContextHandle.AddSourceObject(InASCToGive->GetAvatarActor()); 
			InASCToGive->ApplyGameplayEffectSpecToSelf(*InASCToGive->MakeOutgoingSpec(EffectClass, ApplyLevel, ContextHandle).Data.Get());
		}
	}
}

void UCLASH_AbilitySystemConfig::GrantAbilities(TArray<TSubclassOf<UCLASH_GameplayAbility_Base>>& InAbilitiesToGive, UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) { return; }
	for (const TSubclassOf<UCLASH_GameplayAbility_Base>& Ability : InAbilitiesToGive)
	{
		if (!Ability) { continue; }
		FGameplayAbilitySpec AbilitySpec(Ability, ApplyLevel);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		InASCToGive->GiveAbility(AbilitySpec);
	}
}

void UCLASH_AbilitySystemConfig::GrantAbilitiesWithTags(const TArray<FCLASH_AbilityBindInfo>& InAbilitiesToGive, UCLASH_AbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	for (const FCLASH_AbilityBindInfo& Info : InAbilitiesToGive)
	{
		if (!Info.AbilityClass) continue;

		FGameplayAbilitySpec Spec(Info.AbilityClass, ApplyLevel);
		Spec.SourceObject = InASCToGive->GetAvatarActor();
		FGameplayAbilitySpecHandle Handle = InASCToGive->GiveAbility(Spec);

		InASCToGive->RegisterAbilityWithTag(Info.InputTag, Handle);
	}
}
