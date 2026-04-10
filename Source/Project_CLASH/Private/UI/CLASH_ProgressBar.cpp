// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CLASH_ProgressBar.h"
#include "Components/Image.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "DebugHelper.h"

void UCLASH_ProgressBar::NativeConstruct()
{
	Super::NativeConstruct();
	SetPrograssParmaeter(Current, 1.0f);
	SetPrograssParmaeter(Previos, 1.0f);
}

void UCLASH_ProgressBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!FMath::IsNearlyEqual(CahcedValue, CurrentValue, 0.001f))
	{
		CahcedValue = FMath::FInterpConstantTo(CahcedValue, CurrentValue, InDeltaTime, InterSpeed);
		SetPrograssParmaeter(Previos, CahcedValue);
	}
	else if (CahcedValue != CurrentValue)
	{
		CahcedValue = CurrentValue;
		SetPrograssParmaeter(Previos, CahcedValue);
	}
}

void UCLASH_ProgressBar::UpdateBar(float Percent)
{
	if (CurrentValue <= 0.0f) { return; }

	CahcedValue = CurrentValue;
	CurrentValue = Percent;

	SetPrograssParmaeter(Current, CurrentValue);
}

void UCLASH_ProgressBar::SetPrograssParmaeter(const FName ParameterName, const float NewValue)
{
	if (!IsValid(Progress)) { return; }

	UMaterialInstanceDynamic* ProgressMaterial = Progress->GetDynamicMaterial();

	if (!IsValid(ProgressMaterial)) { return; }

	ProgressMaterial->SetScalarParameterValue(ParameterName, NewValue);
}