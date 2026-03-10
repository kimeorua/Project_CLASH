// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterSelectPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PROJECT_CLASH_API ACharacterSelectPawn : public APawn
{
	GENERATED_BODY()

/*=========================
* Basic
* ========================= */
public:
	ACharacterSelectPawn();

protected:
	virtual void BeginPlay() override;

/* =========================
 * Component
* ========================= */
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera|SpringArm", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera|Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;
};
