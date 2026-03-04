// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset/Input/CLASH_InputConfig.h"

UInputAction* UCLASH_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FClashInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
