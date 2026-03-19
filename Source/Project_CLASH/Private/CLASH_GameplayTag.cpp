#include "CLASH_GameplayTag.h"

namespace ClashGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Input.Move");
	UE_DEFINE_GAMEPLAY_TAG(Input_Look, "Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(Input_Attack_A, "Input.Attack.A");
	UE_DEFINE_GAMEPLAY_TAG(Input_Attack_B, "Input.Attack.B");
	UE_DEFINE_GAMEPLAY_TAG(Input_LockOn, "Input.LockOn");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_1, "Player.Ability.Combo.X.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_2, "Player.Ability.Combo.X.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_3, "Player.Ability.Combo.X.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_4, "Player.Ability.Combo.X.4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_Y_1, "Player.Ability.Combo.Y.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_Y_2, "Player.Ability.Combo.Y.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_Y_3, "Player.Ability.Combo.Y.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_Y_4, "Player.Ability.Combo.Y.4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_Derived_Y, "Player.Ability.Combo.Derived.Y");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_Derived_X, "Player.Ability.Combo.Derived.X");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_LockOn, "Player.Ability.LockOn");

	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_X_2, "Player.State.ReadyCombo.X.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_X_3, "Player.State.ReadyCombo.X.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_X_4, "Player.State.ReadyCombo.X.4");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_Y_2, "Player.State.ReadyCombo.Y.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_Y_3, "Player.State.ReadyCombo.Y.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_Y_4, "Player.State.ReadyCombo.Y.4");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_Derived_X, "Player.State.ReadyCombo.Derived.X");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_Derived_Y, "Player.State.ReadyCombo.Derived.Y");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_LockOn, "Player.State.LockOn");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ReadyToNextCombo, "Player.Event.ReadyToNextCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EndCombo, "Player.Event.EndCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_PlayNextCombo, "Player.Event.PlayNextCombo");
}