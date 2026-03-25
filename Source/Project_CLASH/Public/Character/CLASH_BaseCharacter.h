// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CLASH_BaseCharacter.generated.h"

class UCLASH_AbilitySystemComponent;
class UCLASH_AttributeSet_Basic;
class UCLASH_AbilitySystemConfig;
class UCLASH_WeaponComponent;
class UCLASH_CombatComponent;

UCLASS()
class PROJECT_CLASH_API ACLASH_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

/* =========================
 * Basic
* ========================= */
public:
	ACLASH_BaseCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

/* =========================
 * GAS
* ========================= */
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS|ASC")
	TObjectPtr<UCLASH_AbilitySystemComponent> ClashASC;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS|AttributeSet")
	TObjectPtr<UCLASH_AttributeSet_Basic> BasicAttributeSet;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|DataAsset", meta = (AllowPrivateAccess = "true"))
	TSoftObjectPtr<UCLASH_AbilitySystemConfig> AbilitySystemConfig;

	void InitAbilitySystem();

/* =========================
 * WeaponComponent
* ========================= */
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WeaponComponent", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCLASH_WeaponComponent>WeaponComponent;

/* =========================
 * CombatComponent
* ========================= */
public:
	virtual UCLASH_CombatComponent* GetCombatComponent() const;
};
