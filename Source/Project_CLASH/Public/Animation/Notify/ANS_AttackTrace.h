// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Type/GameStructs/CLASH_GameStructs.h"
#include "ANS_AttackTrace.generated.h"

class ACLASH_BaseCharacter;
class UCLASH_CombatComponent;

UCLASS()
class PROJECT_CLASH_API UANS_AttackTrace : public UAnimNotifyState
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FAttackData AttackData;

	UPROPERTY()
	TObjectPtr<ACLASH_BaseCharacter>OwnerBaseCharacter;

	UPROPERTY()
	TObjectPtr<UCLASH_CombatComponent>CombatComponent;


protected:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
