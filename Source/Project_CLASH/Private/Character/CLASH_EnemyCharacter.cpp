// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CLASH_EnemyCharacter.h"
#include "Components/CapsuleComponent.h"

ACLASH_EnemyCharacter::ACLASH_EnemyCharacter()
{
	GetCapsuleComponent()->SetCollisionProfileName("EnemyCapsuleCollision");
}

void ACLASH_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACLASH_EnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}
