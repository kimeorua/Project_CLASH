// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CLASH_BaseCharacter.h"

// Sets default values
ACLASH_BaseCharacter::ACLASH_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->bRenderCustomDepth = true;
}

// Called when the game starts or when spawned
void ACLASH_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACLASH_BaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}