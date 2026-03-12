// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component/Interface/CLASH_OwnerInterface.h"
#include "Type/GameEums/CLASH_GameEnums.h"
#include "CLASH_WeaponComponent.generated.h"

class ACLASH_Weapon_Base;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_CLASH_API UCLASH_WeaponComponent : public UActorComponent, public ICLASH_OwnerInterface
{
	GENERATED_BODY()

/* =========================
 * Basic
* ========================= */
public:	
	UCLASH_WeaponComponent();

protected:
	virtual void BeginPlay() override;

/* =========================
 * OwnerInterface
* ========================= */
public:
	ACLASH_BaseCharacter* GetOwnerCharacter_Implementation() const;

/* =========================
 * Weapons
* ========================= */
private:
	TMultiMap<EWeaponAttachType, ACLASH_Weapon_Base*>WeaponMap;

	UPROPERTY(VisibleAnywhere)
	TArray<TObjectPtr<ACLASH_Weapon_Base>> GCProtectionArray;

public:
	UFUNCTION(BlueprintCallable)
	void RegisterWeapons(EWeaponAttachType Type, ACLASH_Weapon_Base* WeaponActor);
};
