// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CLASH_BlueprintFunctionLibrary.generated.h"

class ACLASH_BaseCharacter;

UCLASS()
class PROJECT_CLASH_API UCLASH_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "CLASH|Utility")
    static ACLASH_BaseCharacter* GetComponentOwner(const UActorComponent* Comp);
};