// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CLASH_OwnerInterface.generated.h"

class ACLASH_BaseCharacter;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCLASH_OwnerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECT_CLASH_API ICLASH_OwnerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	ACLASH_BaseCharacter* GetOwnerCharacter() const;
};