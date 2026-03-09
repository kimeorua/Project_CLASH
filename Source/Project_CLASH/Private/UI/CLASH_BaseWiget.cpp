// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CLASH_BaseWiget.h"

void UCLASH_BaseWiget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	OwnerPC = GetOwningPlayer();
}

void UCLASH_BaseWiget::NativeConstruct()
{
	Super::NativeConstruct();
}