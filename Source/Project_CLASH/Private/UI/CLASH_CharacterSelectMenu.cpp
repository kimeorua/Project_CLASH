// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/CLASH_CharacterSelectMenu.h"
#include "CommonButtonBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "Controller/CLASH_PlayerController.h"

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

void UCLASH_CharacterSelectMenu::OnSelect_1stButtonClicked()
{
    APawn* OldPawn = OwnerPC->GetPawn();

	ACLASH_PlayerController* CLASH_PC = Cast<ACLASH_PlayerController>(OwnerPC);
    CLASH_PC->CharacterPosses(FindSelectedCharacter("Tag_1st"));

    UUserWidget::RemoveFromParent();

    OldPawn->Destroy();
}

void UCLASH_CharacterSelectMenu::OnSelect_2ndButtonClicked()
{
    APawn* OldPawn = OwnerPC->GetPawn();

    ACLASH_PlayerController* CLASH_PC = Cast<ACLASH_PlayerController>(OwnerPC);
    CLASH_PC->CharacterPosses(FindSelectedCharacter("Tag_2nd"));

    UUserWidget::RemoveFromParent();

    OldPawn->Destroy();
}