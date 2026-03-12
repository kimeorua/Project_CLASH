// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Weapon/CLASH_Weapon_Base.h"
#include "Components/StaticMeshComponent.h"

ACLASH_Weapon_Base::ACLASH_Weapon_Base()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetCollisionProfileName("NoCollision");

	WeaponMesh->SetRenderCustomDepth(true);
}

void ACLASH_Weapon_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACLASH_Weapon_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

