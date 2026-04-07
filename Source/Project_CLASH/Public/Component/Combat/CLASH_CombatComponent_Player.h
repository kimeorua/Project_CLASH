// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/Combat/CLASH_CombatComponent.h"

#include "CLASH_CombatComponent_Player.generated.h"

class UCLASH_AnimInstance_Player;

UCLASS()
class PROJECT_CLASH_API UCLASH_CombatComponent_Player : public UCLASH_CombatComponent
{
	GENERATED_BODY()

public:
	UCLASH_CombatComponent_Player();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void GuardMode(bool bIsGuard);

	UFUNCTION(BlueprintCallable)
	void GuardReactionActivate(bool bIsGuardReaction);

	UFUNCTION(BlueprintCallable)
	void ParryReactionActivate(bool bIsParryReaction);

	virtual void HitCheack(AActor* Instigator) override;

protected:
	virtual void BeginPlay() override;

private:
	bool CheckAngle(AActor* Instigator);

	UPROPERTY()
	TObjectPtr<UCLASH_AnimInstance_Player> PlayerAnimInst;
};
