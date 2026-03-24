// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/CLASH_HUD_Base.h"
#include "Components/ProgressBar.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"

#include "UI/CLASH_WillBeadWidget.h"

void UCLASH_HUD_Base::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCLASH_HUD_Base::UpdateFoucsBar(float Percent)
{
	if (!FocusBar) { return; }

	FocusBar->SetPercent(Percent);
}

void UCLASH_HUD_Base::CreateWillBeads(float WillCount)
{
	if (!WillBaedsPanel || !WillBaedWidgetClass) return;

	for (int32 i = 0; i < FMath::FloorToInt(WillCount); ++i)
	{
		UCLASH_WillBeadWidget* WillBaed = CreateWidget<UCLASH_WillBeadWidget>(GetOwningPlayer(), WillBaedWidgetClass);

		UUniformGridSlot* GridSlot = WillBaedsPanel->AddChildToUniformGrid(WillBaed);

		if (GridSlot)
		{
			GridSlot->SetRow(0);
			GridSlot->SetColumn(i);

			GridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Center);
			GridSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Center);
		}
	}
}