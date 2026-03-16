// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "NativeGameplayTags.h"

namespace ClashGameplayTags
{
	// Input Tag //
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Move);
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Look);
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Attack);
	// Input Tag //

	// Player Ability Tag //
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Combo_X_1);
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Combo_X_2);
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Combo_X_3);
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Combo_X_4);

	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_ReadyCombo_X_2);
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_ReadyCombo_X_3);
	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_ReadyCombo_X_4);

	PROJECT_CLASH_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_ReadyNextCombo);
	// Player Ability Tag //
}