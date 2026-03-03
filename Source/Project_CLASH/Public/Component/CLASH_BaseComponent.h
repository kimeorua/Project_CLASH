// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CLASH_BaseComponent.generated.h"

class ACLASH_BaseCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_CLASH_API UCLASH_BaseComponent : public UActorComponent
{
	GENERATED_BODY()

	UCLASH_BaseComponent();

/* =========================
 * GetOwner()
* ========================= */
protected:
	ACLASH_BaseCharacter* ComponentOwenr;
};