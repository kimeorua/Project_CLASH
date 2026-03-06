// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/CLASH_AnimInstance_Base.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"

#include "Character/CLASH_BaseCharacter.h"

void UCLASH_AnimInstance_Base::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ACLASH_BaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		CharacterMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UCLASH_AnimInstance_Base::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter || !CharacterMovementComponent) { return; }

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = CharacterMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.0f;
	LocomationDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(), OwningCharacter->GetActorRotation());
}