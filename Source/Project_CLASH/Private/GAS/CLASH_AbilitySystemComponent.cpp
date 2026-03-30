// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CLASH_AbilitySystemComponent.h"
#include "CLASH_GameplayTag.h"

#include "GAS/Ability/CLASH_GameplayAbility_Base.h"

#include "DebugHelper.h"

void UCLASH_AbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
    if (!InInputTag.IsValid()) return;

    TArray<FGameplayAbilitySpecHandle> Handles;
    InputTagToAbilityHandles.MultiFind(InInputTag, Handles);

    for (FGameplayAbilitySpecHandle Hanlde : Handles)
    {
        FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Hanlde);

        if (!Spec) { continue; }

        if (Spec->IsActive())
        {
            AbilityLocalInputPressed(Spec->InputID);
        }
        else 
        {
            TryActivateAbility(Spec->Handle);
        }
    }
}

void UCLASH_AbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
    if (!InInputTag.IsValid()) return;

    TArray<FGameplayAbilitySpecHandle> Handles;
    InputTagToAbilityHandles.MultiFind(InInputTag, Handles);

    for (FGameplayAbilitySpecHandle Hanlde : Handles)
    {
        FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Hanlde);

        if (Spec && Spec->IsActive())
        {
            AbilityLocalInputReleased(Spec->InputID);
        }
    }
}

void UCLASH_AbilitySystemComponent::RegisterAbilityWithTag(FGameplayTag& InputTag, FGameplayAbilitySpecHandle& Handle)
{
    if (InputTag.IsValid() && Handle.IsValid())
    {
        InputTagToAbilityHandles.Add(InputTag, Handle);
    }
}