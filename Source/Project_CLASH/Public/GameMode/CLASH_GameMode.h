// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "CLASH_GameMode.generated.h"

class ATargetPoint;

UCLASS()
class PROJECT_CLASH_API ACLASH_GameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)override;
	virtual void StartPlay()override;

/* =========================
 * Battle Start
* ========================= */
private:
	UPROPERTY()
	TObjectPtr<ATargetPoint> BattleStartPoint;

public:
	void StartBattle(APawn* Pawn);

protected:
	virtual void BeginPlay() override;
};
