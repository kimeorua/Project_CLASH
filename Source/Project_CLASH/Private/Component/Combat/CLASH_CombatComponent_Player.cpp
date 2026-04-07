// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/CLASH_CombatComponent_Player.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

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
    if (!PlayerAnimInst) { return; }
    PlayerAnimInst->SettingGuardAnim(bIsGuard);
}

void UCLASH_CombatComponent_Player::GuardReactionActivate(bool bIsGuardReaction)
{
    if (!PlayerAnimInst) { return; }
    PlayerAnimInst->SettingGuardReactionAnim(bIsGuardReaction);
}

void UCLASH_CombatComponent_Player::ParryReactionActivate(bool bIsParryReaction)
{
    if (!PlayerAnimInst) { return; }
    PlayerAnimInst->SettingParryReactionAnim(bIsParryReaction);
}

void UCLASH_CombatComponent_Player::HitCheack(AActor* Instigator)
{
    bool bIsParrying = UCLASH_BlueprintFunctionLibrary::NativeDoseActorHaveTag(GetOwner(), ClashGameplayTags::Player_State_ParryAbale);
    bool bIsGuarding = UCLASH_BlueprintFunctionLibrary::NativeDoseActorHaveTag(GetOwner(), ClashGameplayTags::Player_State_UseGuard);

    if (!bIsParrying && !bIsGuarding)
    {
        DebugHelper::Print("Hit!");
        // TODO: 피격 로직 실행
        return;
    }

    FGameplayEventData Data;
    Data.Instigator = Instigator;
    Data.Target = GetOwner();

    if (CheckAngle(Instigator))
    {
        if (bIsParrying)
        {
            UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), ClashGameplayTags::Player_Event_ParryReaction, Data);
            DebugHelper::Print("Parry!!!");
        }

        else if (bIsGuarding)
        {
            UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwner(), ClashGameplayTags::Player_Event_GuardReaction, Data);
        }
    }
    else
    {
        DebugHelper::Print("Hit! Guard Faild");
    }
}

void UCLASH_CombatComponent_Player::BeginPlay()
{
	Super::BeginPlay();

    if (!PlayerAnimInst)
    {
        if (ACharacter* OwnerChar = Cast<ACharacter>(GetOwner()))
        {
            PlayerAnimInst = Cast<UCLASH_AnimInstance_Player>(OwnerChar->GetMesh()->GetAnimInstance());
        }
    }
}

bool UCLASH_CombatComponent_Player::CheckAngle(AActor* Instigator)
{
    if (!Instigator) return false;

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