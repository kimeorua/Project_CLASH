// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/Combat/CLASH_CombatComponent.h"
#include "CLASH_CombatComponent_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_CLASH_API UCLASH_CombatComponent_Enemy : public UCLASH_CombatComponent
{
	GENERATED_BODY()

public:
	UCLASH_CombatComponent_Enemy();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
};
