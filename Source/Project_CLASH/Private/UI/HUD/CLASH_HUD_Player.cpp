// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/CLASH_HUD_Player.h"

#include "UI/CLASH_ProgressBar.h"
#include "Component/UI/CLASH_UIComponent_Player.h"

void UCLASH_HUD_Player::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCLASH_HUD_Player::UpdateAwakeningGauge(float Percent)
{
	if (!AwakeningGauge) { return; }

	AwakeningGauge->UpdateBar(Percent);
}

void UCLASH_HUD_Player::BindToPlayerUIComponent(UCLASH_UIComponent_Player* TargetComponent)
{
	if (!TargetComponent) { return; }
	TargetComponent->OnAwakeningBarChanged.AddDynamic(this, &UCLASH_HUD_Player::UpdateAwakeningGauge);
}
