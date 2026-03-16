#include "CLASH_GameplayTag.h"

namespace ClashGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG(Input_Move, "Input.Move");
	UE_DEFINE_GAMEPLAY_TAG(Input_Look, "Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(Input_Attack, "Input.Attack");

	UE_DEFINE_GAMEPLAY_TAG(Player_Combo_X_1, "Player.Combo.X.1");
	UE_DEFINE_GAMEPLAY_TAG(Player_Combo_X_2, "Player.Combo.X.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Combo_X_3, "Player.Combo.X.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Combo_X_4, "Player.Combo.X.4");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo_X_2, "Player.Status.ReadyCombo.X.2");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo_X_3, "Player.Status.ReadyCombo.X.3");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ReadyCombo_X_4, "Player.Status.ReadyCombo.X.4");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ReadyNextCombo, "Player.Event.ReadyNextCombo");
}