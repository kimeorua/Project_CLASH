// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/UI/CLASH_UIComponent_Base.h"
#include "CLASH_UIComponent_Enemy.generated.h"

UCLASS()
class PROJECT_CLASH_API UCLASH_UIComponent_Enemy : public UCLASH_UIComponent_Base
{
	GENERATED_BODY()

public:
	UCLASH_UIComponent_Enemy();

protected:
	virtual void BeginPlay() override;
	virtual void CreateHUD() override;
};
