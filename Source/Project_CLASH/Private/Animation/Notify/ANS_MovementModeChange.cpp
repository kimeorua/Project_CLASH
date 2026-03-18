// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/Notify/ANS_MovementModeChange.h"
#include "Character/CLASH_BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UANS_MovementModeChange::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	CachedCLASH_Character = Cast<ACLASH_BaseCharacter>(MeshComp->GetOwner());

	if (!CachedCLASH_Character) { return; }

	CachedCharacterMovementComp = CachedCLASH_Character->GetCharacterMovement();

	if (!CachedCharacterMovementComp) { return; }

	CachedCharacterMovementComp->SetMovementMode(MOVE_Flying);
}

void UANS_MovementModeChange::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!CachedCLASH_Character) { return; }
	if (!CachedCharacterMovementComp) { return; }

	CachedCharacterMovementComp->SetMovementMode(MOVE_Walking);
}