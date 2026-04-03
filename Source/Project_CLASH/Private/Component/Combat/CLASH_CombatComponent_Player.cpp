// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/CLASH_CombatComponent_Player.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Animation/CLASH_AnimInstance_Player.h"
#include "CLASH_BlueprintFunctionLibrary.h"
#include "CLASH_GameplayTag.h"

#include "DebugHelper.h"

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

void UCLASH_CombatComponent_Player::HitCheack(AActor* Instigator)
{
	if (IsGuard(Instigator)) { DebugHelper::Print("Guard!"); }
	else { DebugHelper::Print("Guard Faild - Hit!"); }
}

void UCLASH_CombatComponent_Player::BeginPlay()
{
	Super::BeginPlay();
}

bool UCLASH_CombatComponent_Player::IsGuard(AActor* Instigator)
{
    if (!Instigator) return false;

    bool bIsGuarding = UCLASH_BlueprintFunctionLibrary::NativeDoseActorHaveTag(GetOwner(), ClashGameplayTags::Player_State_UseGuard);

    if (!bIsGuarding) return false;

    const float DefenseAngle = 100.0f;
    const float HalfAngleRad = FMath::DegreesToRadians(DefenseAngle * 0.5f);
    const float CosThreshold = FMath::Cos(HalfAngleRad);

    FVector DirToInstigator = (Instigator->GetActorLocation() - GetOwner()->GetActorLocation()).GetSafeNormal();
    float LocationDot = FVector::DotProduct(GetOwner()->GetActorForwardVector(), DirToInstigator);
    bool bIsInsideFan = LocationDot > CosThreshold;

    FVector InstigatorForward = Instigator->GetActorForwardVector();
    FVector PlayerForward = GetOwner()->GetActorForwardVector();
    float RotationDot = FVector::DotProduct(InstigatorForward, PlayerForward);
    bool bIsFacingEachOther = RotationDot < -CosThreshold;

    return bIsInsideFan && bIsFacingEachOther;
}
