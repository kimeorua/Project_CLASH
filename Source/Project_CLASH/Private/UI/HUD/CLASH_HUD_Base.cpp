// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/CLASH_HUD_Base.h"
#include "Components/ProgressBar.h"

void UCLASH_HUD_Base::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCLASH_HUD_Base::UpdateFoucsBar(float Percent)
{
	if (!FocusBar) { return; }

	FocusBar->SetPercent(Percent);
}
