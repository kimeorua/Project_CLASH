#include "CLASH_BlueprintFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "CLASH_GameplayTag.h"
#include "Character/CLASH_BaseCharacter.h"
#include "Component/Interface/CLASH_OwnerInterface.h"
#include "GAS/CLASH_AbilitySystemComponent.h"

ACLASH_BaseCharacter* UCLASH_BlueprintFunctionLibrary::GetComponentOwner(const UActorComponent* Comp)
{
    if (Comp && Comp->GetClass()->ImplementsInterface(UCLASH_OwnerInterface::StaticClass()))
    {
        return ICLASH_OwnerInterface::Execute_GetOwnerCharacter(Comp);
    }
    return nullptr;
}

void UCLASH_BlueprintFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UCLASH_AbilitySystemComponent* ASC = Cast<UCLASH_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));

	if (!ASC) { return; }

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UCLASH_BlueprintFunctionLibrary::RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove)
{
	UCLASH_AbilitySystemComponent* ASC = Cast<UCLASH_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));

	if (!ASC) { return; }

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UCLASH_BlueprintFunctionLibrary::NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UCLASH_AbilitySystemComponent* ASC = Cast<UCLASH_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UCLASH_BlueprintFunctionLibrary::BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EClashConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoseActorHaveTag(InActor, TagToCheck) ? EClashConfirmType::Yes : EClashConfirmType::No;
}
