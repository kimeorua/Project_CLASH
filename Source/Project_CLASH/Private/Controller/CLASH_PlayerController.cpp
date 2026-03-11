// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/CLASH_PlayerController.h"

void ACLASH_PlayerController::CharacterPosses(APawn* SelectedChar)
{
    if (SelectedChar)
    {
        Possess(SelectedChar);
    }
    else { return; }
}