// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Type/GameEums/CLASH_GameEnums.h"
#include "CLASH_WeaponConfig.generated.h"

class ACLASH_Weapon_Base;

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponData|Mesh")
    TSubclassOf<ACLASH_Weapon_Base> WeaponClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponData|AttackSocket")
    FName AttachSocketName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "WeaponData|WeaponAttachType")
    EWeaponAttachType WeaponAttachType;

    FWeaponData() : WeaponClass(nullptr), AttachSocketName(NAME_None), WeaponAttachType(EWeaponAttachType::None) {}
};

UCLASS()
class PROJECT_CLASH_API UCLASH_WeaponConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "WeaponData")
    TArray<FWeaponData> WeaponDatas;

    UFUNCTION(BlueprintPure)
    TArray<FWeaponData> GetWeaponDatas() const;
};
