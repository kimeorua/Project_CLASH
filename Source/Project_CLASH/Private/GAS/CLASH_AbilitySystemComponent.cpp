// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CLASH_AbilitySystemComponent.h"
#include "CLASH_GameplayTag.h"

#include "GAS/Ability/CLASH_GameplayAbility_Base.h"

void UCLASH_AbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
    if (!InInputTag.IsValid()) return;

    TArray<FGameplayAbilitySpecHandle> Handles;
    InputTagToAbilityHandles.MultiFind(InInputTag, Handles);

    for (FGameplayAbilitySpecHandle Hanlde : Handles)
    {
        FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(Hanlde);
        if (Spec)
        {
            TryActivateAbility(Spec->Handle);
        }
        else { return; }
    }
}

void UCLASH_AbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
    if (!InInputTag.IsValid()) return;

    if (FGameplayAbilitySpecHandle* FoundHandle = InputTagToAbilityHandles.Find(InInputTag))
    {
        FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(*FoundHandle);
        if (Spec)
        {
            return;
            // TODO 가드 해제 와 같은 기능 구현시 구현 할것!
        }
    }
}

void UCLASH_AbilitySystemComponent::RegisterAbilityWithTag(FGameplayTag InputTag, FGameplayAbilitySpecHandle Handle)
{
    if (InputTag.IsValid() && Handle.IsValid())
    {
        InputTagToAbilityHandles.Add(InputTag, Handle);
    }
}