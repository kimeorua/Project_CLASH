// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EWeaponAttachType : uint8
{
    None UMETA(DisplayName = "None"),
    LeftHand UMETA(DisplayName = "LeftHand"),
    RightHand UMETA(DisplayName = "RightHand"),
    Max UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ETraceShapeType : uint8
{
    None UMETA(DisplayName = "None"),
    Sphere UMETA(DisplayName = "Sphere"),
    Box UMETA(DisplayName = "Box"),
    Max UMETA(Hidden)
};