// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CLASH_InputConfigurable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCLASH_InputConfigurable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECT_CLASH_API ICLASH_InputConfigurable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool ShouldShowMouseCursor() const { return false; }
};
