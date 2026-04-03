// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CLASH_EnemyCharacter.h"
#include "Components/CapsuleComponent.h"

#include "Component/Combat/CLASH_CombatComponent_Enemy.h"

ACLASH_EnemyCharacter::ACLASH_EnemyCharacter()
{
	GetCapsuleComponent()->SetCollisionProfileName("EnemyCapsuleCollision");

	EnemyCombatComponent = CreateDefaultSubobject<UCLASH_CombatComponent_Enemy>(TEXT("EnemyCombatComponent"));
}

void ACLASH_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACLASH_EnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

FVector ACLASH_EnemyCharacter::GetUISokcetPosition() const
{
	if (UISocketName == "") { return FVector::ZeroVector; }

	return GetMesh()->GetSocketLocation(UISocketName);
}

UCLASH_CombatComponent* ACLASH_EnemyCharacter::GetCombatComponent() const
{
	return EnemyCombatComponent ? EnemyCombatComponent : nullptr;
}
