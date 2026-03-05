// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AttributeSet/CLASH_AttributeSet_Basic.h"
#include "GameplayEffectExtension.h"

UCLASH_AttributeSet_Basic::UCLASH_AttributeSet_Basic()
{
	InitTestFloat(10.0f);
}

void UCLASH_AttributeSet_Basic::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetTestFloatAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, 10.0f);
	}
}

void UCLASH_AttributeSet_Basic::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	FGameplayAttribute ModifiedAttribute = Data.EvaluatedData.Attribute;

	if (ModifiedAttribute == GetTestFloatAttribute())
	{
		SetTestFloat(FMath::Clamp(GetTestFloat(), 0.0f, 10.0f));
	}
}
