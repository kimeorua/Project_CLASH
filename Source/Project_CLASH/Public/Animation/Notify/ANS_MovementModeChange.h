// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ANS_MovementModeChange.generated.h"

class ACLASH_BaseCharacter;
class UCharacterMovementComponent;

UCLASS()
class PROJECT_CLASH_API UANS_MovementModeChange : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	UPROPERTY()
	TObjectPtr<ACLASH_BaseCharacter> CachedCLASH_Character;

	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent>CachedCharacterMovementComp;
};
