// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/Weapon/CLASH_WeaponConfig.h"

TArray<FWeaponData> UCLASH_WeaponConfig::GetWeaponDatas() const
{
    return WeaponDatas.IsEmpty() ? TArray<FWeaponData>() : WeaponDatas;
}