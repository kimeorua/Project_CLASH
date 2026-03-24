// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UI/CLASH_UIComponent_Player.h"
#include "Blueprint/UserWidget.h"

#include "UI/HUD/CLASH_HUD_Player.h"
#include "GameFramework/Character.h"
#include "GAS/AttributeSet/CLASH_AttributeSet_Player.h"

UCLASH_UIComponent_Player::UCLASH_UIComponent_Player()
{
}

void UCLASH_UIComponent_Player::BeginPlay()
{
	Super::BeginPlay();
}

void UCLASH_UIComponent_Player::CreateHUD()
{
	APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
	HUD = Cast< UCLASH_HUD_Base>(CreateWidget<UUserWidget>(PC, HUDClass));

	if (!HUD) { return; }

	HUD_Player = Cast<UCLASH_HUD_Player>(HUD);

	HUD->AddToViewport();
}

void UCLASH_UIComponent_Player::SettingInitValue()
{
	Super::SettingInitValue();

	if (!HUD || !ASC) { return; }

	FOnAttributeChangeData InitAwakeningData;
	InitAwakeningData.NewValue = ASC->GetNumericAttribute(UCLASH_AttributeSet_Player::GetAwakeningAttribute());
	OnCurrentAwakeningChanged(InitAwakeningData);
}

void UCLASH_UIComponent_Player::BindUpdage(UAbilitySystemComponent* InASC)
{
	Super::BindUpdage(InASC);
	InASC->GetGameplayAttributeValueChangeDelegate(UCLASH_AttributeSet_Player::GetAwakeningAttribute()).AddUObject(this, &UCLASH_UIComponent_Player::OnCurrentAwakeningChanged);
}

void UCLASH_UIComponent_Player::OnCurrentAwakeningChanged(const FOnAttributeChangeData& Data)
{
	if (!HUD || !ASC || !HUD_Player) { return; }

	float Max = UCLASH_AttributeSet_Player::ABSOLUTE_MAX_AWAKENING;
	float Percent = Data.NewValue / Max;

	HUD_Player->UpdateAwakeningGauge(Percent);
}