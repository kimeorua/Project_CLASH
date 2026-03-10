// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CLASH_BaseWiget.h"
#include "UI/Interface/CLASH_InputConfigurable.h"

#include "DebugHelper.h"

APlayerController* UCLASH_BaseWiget::GetOwnerPlayerController() const
{
	return OwnerPC ? OwnerPC : nullptr;
}

void UCLASH_BaseWiget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	OwnerPC = GetOwningPlayer();
}

void UCLASH_BaseWiget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCLASH_BaseWiget::NativeOnActivated()
{
	Super::NativeOnActivated();

	if (!OwnerPC) { return; }

	ICLASH_InputConfigurable* InputConfigurable = Cast<ICLASH_InputConfigurable>(this);
	if (InputConfigurable && InputConfigurable->ShouldShowMouseCursor())
	{
		FInputModeGameAndUI InputMode;
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture);
		InputMode.SetHideCursorDuringCapture(false);

		OwnerPC->SetInputMode(InputMode);
		OwnerPC->SetShowMouseCursor(true);
	}
}

void UCLASH_BaseWiget::NativeOnDeactivated()
{
	Super::NativeOnDeactivated();

	if (!OwnerPC) { return; }

	if (Cast<ICLASH_InputConfigurable>(this))
	{
		FInputModeGameOnly Mode;
		OwnerPC->SetInputMode(Mode);
		OwnerPC->bShowMouseCursor = false;
	}
}