// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CLASH_GameInstance.generated.h"

UCLASS()
class PROJECT_CLASH_API UCLASH_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;
};
