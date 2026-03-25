// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLASH_Weapon_Base.generated.h"

class UStaticMeshComponent;

UCLASS()
class PROJECT_CLASH_API ACLASH_Weapon_Base : public AActor
{
	GENERATED_BODY()
	
/* =========================
 * Basic
* ========================= */
public:	
	ACLASH_Weapon_Base();

	FORCEINLINE UStaticMeshComponent* GetWeaponMesh() const { return WeaponMesh; }

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

/* =========================
 * Component
* ========================= */
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon|Mesh", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> WeaponMesh;
};
