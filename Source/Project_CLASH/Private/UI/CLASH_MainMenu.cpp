// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/CLASH_MainMenu.h"
#include "CommonButtonBase.h"
#include "Kismet/KismetSystemLibrary.h"

#include "DebugHelper.h"

void UCLASH_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	StartButton->OnClicked().AddUObject(this, &UCLASH_MainMenu::OnStartButtonClicked);
	QuitButton->OnClicked().AddUObject(this, &UCLASH_MainMenu::OnQuitButtonClicked);
}

void UCLASH_MainMenu::OnStartButtonClicked()
{
	UUserWidget::RemoveFromParent();

	DebugHelper::Print("Game Start");
}

void UCLASH_MainMenu::OnQuitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),OwnerPC, EQuitPreference::Quit, false);
}
