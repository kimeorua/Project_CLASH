// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Component/UI/CLASH_UIComponent_Base.h"
#include "CLASH_UIComponent_Player.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_CLASH_API UCLASH_UIComponent_Player : public UCLASH_UIComponent_Base
{
	GENERATED_BODY()

/* =========================
 * Basic
* ========================= */
public:
	UCLASH_UIComponent_Player();

protected:
	virtual void BeginPlay() override;

/* =========================
	 * HUD
* ========================= */
public:
	virtual void InitUIComponent(ACLASH_BaseCharacter* ClashCharacter) override;
};
