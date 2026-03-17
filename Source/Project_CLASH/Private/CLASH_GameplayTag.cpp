#include "CLASH_GameplayTag.h"

namespace ClashGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Input.Move");
	UE_DEFINE_GAMEPLAY_TAG(Input_Look, "Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(Input_Attack, "Input.Attack");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_1, "Player.Ability.Combo.X.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_2, "Player.Ability.Combo.X.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_3, "Player.Ability.Combo.X.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Combo_X_4, "Player.Ability.Combo.X.4");

	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_X_2, "Player.State.ReadyCombo.X.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_X_3, "Player.State.ReadyCombo.X.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_State_ReadyCombo_X_4, "Player.State.ReadyCombo.X.4");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ReadyToNextCombo, "Player.Event.ReadyToNextCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EndCombo, "Player.Event.EndCombo");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_PlayNextCombo, "Player.Event.PlayNextCombo");
}