// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CLASH_GameplayAbility_Base.generated.h"

class UCLASH_AbilitySystemComponent;
class ACLASH_BaseCharacter;

UCLASS()
class PROJECT_CLASH_API UCLASH_GameplayAbility_Base : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Clash|Ability|Util")
	UCLASH_AbilitySystemComponent* GetClashAbilitySystemComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Clash|Ability|Util")
	ACLASH_BaseCharacter* GetClashBaseCharacterFromActorInfo() const;
};