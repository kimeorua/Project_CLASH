// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CLASH_BaseCharacter.h"
#include "GameplayTagContainer.h"
#include "InputActionValue.h"
#include "CLASH_PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UCLASH_InputConfig;

UCLASS()
class PROJECT_CLASH_API ACLASH_PlayerCharacter : public ACLASH_BaseCharacter
{
	GENERATED_BODY()

/* =========================
 * Basic
* ========================= */
public:
	ACLASH_PlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;

private:
	void PlayerCharacterInit();

/* =========================
 * Component
* ========================= */
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera|SpringArm", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera|Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

/* =========================
 * MovementSpeed
* ========================= */
private:
	static constexpr float DEFAULT_WALK_SPEED = 500.0f;

/* =========================
 * Input
* ========================= */
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DataAsset|InputDataAsset", meta = (AllowPrivateAccess = "true"))
	UCLASH_InputConfig* InputConfig;

	void InputMove(const FInputActionValue& InputActionValue);
	void InputLook(const FInputActionValue& InputActionValue);

	void InputAbilityInputPressed(FGameplayTag InInputTag);
	void InputAbilityInputReleased(FGameplayTag InInputTag);
};
