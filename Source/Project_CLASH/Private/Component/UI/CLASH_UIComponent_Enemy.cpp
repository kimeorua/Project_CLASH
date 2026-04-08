// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UI/CLASH_UIComponent_Enemy.h"
#include "UI/HUD/CLASH_HUD_Enemy.h"

#include "Kismet/GameplayStatics.h"

#include "DebugHelper.h"

UCLASH_UIComponent_Enemy::UCLASH_UIComponent_Enemy()
{
}

void UCLASH_UIComponent_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

void UCLASH_UIComponent_Enemy::CreateHUD()
{
	UWorld* World = GetWorld();

	if (!World) { return; }

	APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);

	if (!PC) { return; }

	HUD = Cast< UCLASH_HUD_Base>(CreateWidget<UUserWidget>(PC, HUDClass));

	if (!HUD) { return; }
	HUD_Enemy = Cast<UCLASH_HUD_Enemy>(HUD);

	HUD->AddToViewport();
}