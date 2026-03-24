// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GAS/CLASH_AbilitySystemComponent.h"
#include "CLASH_AttributeSet_Player.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class PROJECT_CLASH_API UCLASH_AttributeSet_Player : public UAttributeSet
{
	GENERATED_BODY()

public:
	static const float ABSOLUTE_MAX_AWAKENING;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Awakening;

	UCLASH_AttributeSet_Player();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;

	ATTRIBUTE_ACCESSORS(UCLASH_AttributeSet_Player, Awakening);
};
