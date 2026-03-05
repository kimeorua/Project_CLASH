// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Ability/CLASH_GameplayAbility_Base.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "GAS/CLASH_AbilitySystemComponent.h"
#include "Character/CLASH_BaseCharacter.h"

UCLASH_AbilitySystemComponent* UCLASH_GameplayAbility_Base::GetClashAbilitySystemComponentFromActorInfo() const
{
	return Cast<UCLASH_AbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

ACLASH_BaseCharacter* UCLASH_GameplayAbility_Base::GetClashBaseCharacterFromActorInfo() const
{
	return Cast<ACLASH_BaseCharacter>(CurrentActorInfo->AvatarActor);
}