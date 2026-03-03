// Fill out your copyright notice in the Description page of Project Settings.

#include "Component/CLASH_BaseComponent.h"
#include "Character/CLASH_BaseCharacter.h"

UCLASH_BaseComponent::UCLASH_BaseComponent()
{
	ComponentOwenr = Cast<ACLASH_BaseCharacter>(GetOwner());
}