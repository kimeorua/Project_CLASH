// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Type/GameEums/CLASH_GameEnums.h"
#include "CLASH_GameStructs.generated.h"

USTRUCT(BlueprintType)
struct FAttackData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	ETraceShapeType TraceShape = ETraceShapeType::Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	FVector ShapeDimensions = FVector(10.f, 10.f, 10.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	FName StartSocket = FName("StartSocket");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	FName EndSocket = FName("EndSocket");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	EWeaponAttachType WeaponAttachType = EWeaponAttachType::LeftHand;
};