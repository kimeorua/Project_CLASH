// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CLASH_BaseCharacter.generated.h"

UCLASS()
class PROJECT_CLASH_API ACLASH_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

/* =========================
 * Basic
* ========================= */
public:
	ACLASH_BaseCharacter();

protected:
	virtual void BeginPlay() override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
};
