// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CLASH_CharacterSelectMenu.h"
#include "CommonButtonBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "Controller/CLASH_PlayerController.h"
#include "GameMode/CLASH_GameMode.h"

void UCLASH_CharacterSelectMenu::NativeConstruct()
{
	Super::NativeConstruct();

	Select_1stButton->OnClicked().AddUObject(this, &UCLASH_CharacterSelectMenu::OnSelect_1stButtonClicked);
	Select_2ndButton->OnClicked().AddUObject(this, &UCLASH_CharacterSelectMenu::OnSelect_2ndButtonClicked);
}

ACharacter* UCLASH_CharacterSelectMenu::FindSelectedCharacter(FName Tag) const
{
    ACLASH_PlayerController* CLASH_PC = Cast<ACLASH_PlayerController>(OwnerPC);
    if (!CLASH_PC) return nullptr;

    TArray<AActor*> OutActors;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), Tag, OutActors);

    if (OutActors.Num() > 0)
    {
        ACharacter* SelectedChar = Cast<ACharacter>(OutActors[0]);
        return SelectedChar;
    }
    return nullptr;
}

void UCLASH_CharacterSelectMenu::CharacterSetting(FName Tag)
{
    if (!OwnerPC) { return; }

    ACLASH_PlayerController* CLASH_PC = Cast<ACLASH_PlayerController>(OwnerPC);

    if (!CLASH_PC) { return; }

    APawn* OldPawn = OwnerPC->GetPawn();

    APawn* NewPawn = FindSelectedCharacter(Tag);

    CLASH_PC->CharacterPosses(NewPawn);

    if (OldPawn)
    {
        OldPawn->Destroy();
    }

    UUserWidget::RemoveFromParent();

    ACLASH_GameMode* CLASH_GM = Cast<ACLASH_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));

    if (!CLASH_GM) { return; }

    CLASH_GM->StartBattle(NewPawn);
}

void UCLASH_CharacterSelectMenu::OnSelect_1stButtonClicked()
{
    CharacterSetting("Tag_1st");
}

void UCLASH_CharacterSelectMenu::OnSelect_2ndButtonClicked()
{
    CharacterSetting("Tag_2nd");
}