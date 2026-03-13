// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GAS/CLASH_AbilitySystemComponent.h"
#include "CLASH_AttributeSet_Basic.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class PROJECT_CLASH_API UCLASH_AttributeSet_Basic : public UAttributeSet
{
	GENERATED_BODY()

public:
	static const float ABSOLUTE_MAX_WILLCOUNT;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Focus;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxFocus;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData WillCount;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxWillCount;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AttackPower;

	UCLASH_AttributeSet_Basic();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override;

	ATTRIBUTE_ACCESSORS(UCLASH_AttributeSet_Basic, Focus);
	ATTRIBUTE_ACCESSORS(UCLASH_AttributeSet_Basic, MaxFocus);
	ATTRIBUTE_ACCESSORS(UCLASH_AttributeSet_Basic, WillCount);
	ATTRIBUTE_ACCESSORS(UCLASH_AttributeSet_Basic, MaxWillCount);
	ATTRIBUTE_ACCESSORS(UCLASH_AttributeSet_Basic, AttackPower);
};
