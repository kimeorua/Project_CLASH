// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/Notify/ANS_AttackTrace.h"
#include "Character/CLASH_BaseCharacter.h"
#include "Component/Combat/CLASH_CombatComponent.h"


void UANS_AttackTrace::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	OwnerBaseCharacter = Cast<ACLASH_BaseCharacter>(MeshComp->GetOwner());

	if (!OwnerBaseCharacter) { return; }

	CombatComponent = OwnerBaseCharacter->GetCombatComponent();

	if (!CombatComponent) { return; }

	CombatComponent->SetTreceData(AttackData);
	CombatComponent->SetComponentTickEnabled(true);
}

void UANS_AttackTrace::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!CombatComponent) { return; }

	CombatComponent->SetTreceData(FAttackData());
	CombatComponent->SetComponentTickEnabled(false);
}
