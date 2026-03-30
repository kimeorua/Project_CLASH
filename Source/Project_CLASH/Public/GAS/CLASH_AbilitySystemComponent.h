// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CLASH_AbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_CLASH_API UCLASH_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	void RegisterAbilityWithTag(FGameplayTag& InputTag, FGameplayAbilitySpecHandle& Handle);

protected:
	TMultiMap<FGameplayTag, FGameplayAbilitySpecHandle> InputTagToAbilityHandles;
};
