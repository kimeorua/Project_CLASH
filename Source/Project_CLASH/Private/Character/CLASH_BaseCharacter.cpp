// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CLASH_BaseCharacter.h"

#include "GAS/CLASH_AbilitySystemComponent.h"
#include "GAS/AttributeSet/CLASH_AttributeSet_Basic.h"
#include "DataAsset/GASConfig/CLASH_AbilitySystemConfig.h"
#include "Component/Weapon/CLASH_WeaponComponent.h"

#include "DebugHelper.h"

// Sets default values
ACLASH_BaseCharacter::ACLASH_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->bRenderCustomDepth = true;

	ClashASC = CreateDefaultSubobject<UCLASH_AbilitySystemComponent>(TEXT("ClashASC"));
	BasicAttributeSet = CreateDefaultSubobject<UCLASH_AttributeSet_Basic>(TEXT("BasicAttributeSet"));
	WeaponComponent = CreateDefaultSubobject<UCLASH_WeaponComponent>(TEXT("WeaponComponent"));
}

// Called when the game starts or when spawned
void ACLASH_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystem();
}

void ACLASH_BaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ClashASC && BasicAttributeSet)
	{
		ClashASC->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ACLASH_BaseCharacter::GetAbilitySystemComponent() const
{
	return ClashASC;
}

void ACLASH_BaseCharacter::InitAbilitySystem()
{
	if (!AbilitySystemConfig.IsNull())
	{
		if (UCLASH_AbilitySystemConfig* LodedData = AbilitySystemConfig.LoadSynchronous())
		{
			int32 AbilityApplyLevel = 1;
			LodedData->GiveToAbilitySystemComponent(ClashASC, AbilityApplyLevel);
		}
	}
}

UCLASH_CombatComponent* ACLASH_BaseCharacter::GetCombatComponent() const
{
	return nullptr;
}