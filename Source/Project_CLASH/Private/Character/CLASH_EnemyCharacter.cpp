// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CLASH_EnemyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#include "Component/Combat/CLASH_CombatComponent_Enemy.h"
#include "Component/UI/CLASH_UIComponent_Enemy.h"

ACLASH_EnemyCharacter::ACLASH_EnemyCharacter()
{
	GetCapsuleComponent()->SetCollisionProfileName("EnemyCapsuleCollision");

	EnemyCombatComponent = CreateDefaultSubobject<UCLASH_CombatComponent_Enemy>(TEXT("EnemyCombatComponent"));
	EnemyUIComponent = CreateDefaultSubobject<UCLASH_UIComponent_Enemy>(TEXT("EnemyUIComponent"));
}

void ACLASH_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACLASH_EnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bAlreadyCreateHUD) { return; }

	if (Test_CreateUITrace())
	{
		CreateEnemyHUD();
	}
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

//TODO: 이함수는 테스트용임, 이후 AI Controller에서 담당 할 예정이다.
bool ACLASH_EnemyCharacter::Test_CreateUITrace()
{
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());

	FHitResult HitResult;

	ETraceTypeQuery Chanel = UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel3);

	return UKismetSystemLibrary::SphereTraceSingle
	(
		GetWorld(),
		GetActorLocation(),
		GetActorLocation(),
		600.0f,
		Chanel,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		HitResult,
		true
	);
}

void ACLASH_EnemyCharacter::CreateEnemyHUD()
{
	if (bAlreadyCreateHUD) { return; }

	EnemyUIComponent->InitUIComponent(this);
	bAlreadyCreateHUD = true;
}
