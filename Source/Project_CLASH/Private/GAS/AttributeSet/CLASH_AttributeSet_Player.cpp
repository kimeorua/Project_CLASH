// Fill out your copyright notice in the Description page of Project Settings.

#include "GAS/AttributeSet/CLASH_AttributeSet_Player.h"
#include "GameplayEffectExtension.h"

const float UCLASH_AttributeSet_Player::ABSOLUTE_MAX_AWAKENING = 100.0f;

UCLASH_AttributeSet_Player::UCLASH_AttributeSet_Player()
{
	InitAwakening(0.0f);
}

void UCLASH_AttributeSet_Player::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetAwakeningAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, ABSOLUTE_MAX_AWAKENING);
	}
}

void UCLASH_AttributeSet_Player::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	FGameplayAttribute ModifiedAttribute = Data.EvaluatedData.Attribute;
}