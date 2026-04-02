// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/CLASH_CombatComponent_Player.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Animation/CLASH_AnimInstance_Player.h"

UCLASH_CombatComponent_Player::UCLASH_CombatComponent_Player()
{
}

void UCLASH_CombatComponent_Player::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCLASH_CombatComponent_Player::GuardMode(bool bIsGuard)
{
	if (ACharacter* OwnerChar = Cast<ACharacter>(GetOwner()))
	{
		if (UCLASH_AnimInstance_Player* AnimInst = Cast<UCLASH_AnimInstance_Player>(OwnerChar->GetMesh()->GetAnimInstance()))
		{
			AnimInst->SettingGuardAnim(bIsGuard);
		}
	}
}

void UCLASH_CombatComponent_Player::BeginPlay()
{
	Super::BeginPlay();
}