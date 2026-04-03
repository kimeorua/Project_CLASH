// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CLASH_BaseCharacter.h"
#include "CLASH_EnemyCharacter.generated.h"

class UCLASH_CombatComponent_Enemy;

UCLASS()
class PROJECT_CLASH_API ACLASH_EnemyCharacter : public ACLASH_BaseCharacter
{
	GENERATED_BODY()

/* =========================
 * Basic
* ========================= */
public:
	ACLASH_EnemyCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

/* =========================
 * LockOn UI Position
* ========================= */
public:
	FVector GetUISokcetPosition() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "UI|Socket", meta = (AllowPrivateAccess = "true"))
	FName UISocketName;

/* =========================
 * CombatComponent
* ========================= */
public:
	virtual UCLASH_CombatComponent* GetCombatComponent() const override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCLASH_CombatComponent_Enemy> EnemyCombatComponent;
};
