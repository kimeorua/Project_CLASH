// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/CLASH_CombatComponent_Player.h"

UCLASH_CombatComponent_Player::UCLASH_CombatComponent_Player()
{
}

void UCLASH_CombatComponent_Player::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCLASH_CombatComponent_Player::BeginPlay()
{
	Super::BeginPlay();
}