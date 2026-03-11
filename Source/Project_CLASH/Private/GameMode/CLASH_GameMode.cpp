// Fill out your copyright notice in the Description page of Project Settings.
#include "GameMode/CLASH_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

#include "DebugHelper.h"

void ACLASH_GameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	DebugHelper::Print("GameMode - Init Game");
}

void ACLASH_GameMode::StartPlay()
{
	Super::StartPlay();
	DebugHelper::Print("GameMode - Start Play");
	ATargetPoint* StartPoint;

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Start Point"), OutActors);

	if (OutActors.Num() > 0)
	{
		StartPoint = Cast<ATargetPoint>(OutActors[0]);
	}
	BattleStartPoint = StartPoint;
}

void ACLASH_GameMode::StartBattle(APawn* Pawn)
{
	if (!BattleStartPoint) { return; }
	Pawn->TeleportTo(BattleStartPoint->GetActorLocation(), BattleStartPoint->GetActorRotation());

	FRotator TargetRot = Pawn->GetActorRotation();
	Pawn->GetController()->SetControlRotation(TargetRot);
}

void ACLASH_GameMode::BeginPlay()
{
	Super::BeginPlay();
	DebugHelper::Print("GameMode - Begin Play");
}
