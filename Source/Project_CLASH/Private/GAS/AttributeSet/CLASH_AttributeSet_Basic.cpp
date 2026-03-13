// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/AttributeSet/CLASH_AttributeSet_Basic.h"
#include "GameplayEffectExtension.h"

const float UCLASH_AttributeSet_Basic::ABSOLUTE_MAX_WILLCOUNT = 5.0f;

UCLASH_AttributeSet_Basic::UCLASH_AttributeSet_Basic()
{
	InitAttackPower(10.0f);
	InitFocus(100.0f);
	InitMaxFocus(100.0f);
	InitWillCount(3.0f);
	InitMaxWillCount(3.0f);
}

void UCLASH_AttributeSet_Basic::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetAttackPowerAttribute())
	{
		NewValue = FMath::Max(NewValue, 10.0f);
	}
	else if (Attribute == GetFocusAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxFocus());
	}
	else if (Attribute == GetMaxFocusAttribute())
	{
		NewValue = FMath::Max(NewValue, 100.0f);
	}
	else if (Attribute == GetWillCountAttribute() || Attribute == GetMaxWillCountAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, ABSOLUTE_MAX_WILLCOUNT);
	}
}

void UCLASH_AttributeSet_Basic::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	FGameplayAttribute ModifiedAttribute = Data.EvaluatedData.Attribute;
}