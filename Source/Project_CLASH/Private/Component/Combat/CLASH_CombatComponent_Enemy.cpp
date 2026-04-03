// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/CLASH_CombatComponent_Enemy.h"

UCLASH_CombatComponent_Enemy::UCLASH_CombatComponent_Enemy()
{
}

void UCLASH_CombatComponent_Enemy::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCLASH_CombatComponent_Enemy::BeginPlay()
{
	Super::BeginPlay();
}