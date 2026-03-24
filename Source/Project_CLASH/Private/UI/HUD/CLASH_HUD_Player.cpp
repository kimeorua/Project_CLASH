// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/CLASH_HUD_Player.h"
#include "Components/ProgressBar.h"

void UCLASH_HUD_Player::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCLASH_HUD_Player::UpdateAwakeningGauge(float Percent)
{
	if (!AwakeningGauge) { return; }

	AwakeningGauge->SetPercent(Percent);
}
