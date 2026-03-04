// Fill out your copyright notice in the Description page of Project Settings.
#include "GameMode/CLASH_GameMode.h"
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
}

void ACLASH_GameMode::BeginPlay()
{
	Super::BeginPlay();
	DebugHelper::Print("GameMode - Begin Play");
}
