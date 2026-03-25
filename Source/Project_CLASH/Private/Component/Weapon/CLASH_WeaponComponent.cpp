// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Weapon/CLASH_WeaponComponent.h"
#include "Character/CLASH_BaseCharacter.h"
#include "Actor/Weapon/CLASH_Weapon_Base.h"

UCLASH_WeaponComponent::UCLASH_WeaponComponent()
{
	WeaponMap.Empty();
}

void UCLASH_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();
}

ACLASH_BaseCharacter* UCLASH_WeaponComponent::GetOwnerCharacter_Implementation() const
{
	return Cast<ACLASH_BaseCharacter>(GetOwner());
}

void UCLASH_WeaponComponent::RegisterWeapons(EWeaponAttachType Type, ACLASH_Weapon_Base* WeaponActor)
{
	if (!WeaponActor) { return; }

	WeaponMap.Add(Type, WeaponActor);
}

const FVector UCLASH_WeaponComponent::GetSocketLocation(EWeaponAttachType Type, FName SocketName)
{
	if (!WeaponMap.Contains(Type)) { return FVector(); }

	ACLASH_Weapon_Base* FoundWeapon = WeaponMap.FindRef(Type);

	if (FoundWeapon && FoundWeapon->GetWeaponMesh())
	{
		return FoundWeapon->GetWeaponMesh()->GetSocketLocation(SocketName);
	}

	return GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
}

const FQuat UCLASH_WeaponComponent::GetSocketQuat(EWeaponAttachType Type, FName SocketName)
{
	if (!WeaponMap.Contains(Type)) { return FQuat::Identity; }

	ACLASH_Weapon_Base* FoundWeapon = WeaponMap.FindRef(Type);

	if (FoundWeapon && FoundWeapon->GetWeaponMesh())
	{
		return FoundWeapon->GetWeaponMesh()->GetSocketQuaternion(SocketName);
	}
	return FQuat::Identity;
}
