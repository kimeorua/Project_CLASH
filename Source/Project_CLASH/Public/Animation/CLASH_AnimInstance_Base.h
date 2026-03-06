// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UObject/ObjectPtr.h"
#include "CLASH_AnimInstance_Base.generated.h"

class ACLASH_BaseCharacter;
class UCharacterMovementComponent;

UCLASS()
class PROJECT_CLASH_API UCLASH_AnimInstance_Base : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;

protected:
	UPROPERTY()
	TObjectPtr<ACLASH_BaseCharacter> OwningCharacter;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> CharacterMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData")
	float LocomationDirection;
};
