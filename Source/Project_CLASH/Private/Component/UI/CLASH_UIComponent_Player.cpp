// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/UI/CLASH_UIComponent_Player.h"
#include "Blueprint/UserWidget.h"

#include "UI/HUD/CLASH_HUD_Player.h"
#include "GameFramework/Character.h"
#include "GAS/AttributeSet/CLASH_AttributeSet_Player.h"

#include "DebugHelper.h"

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

	if (!PC) { return; }

	UUserWidget* HUD = CreateWidget<UUserWidget>(PC, HUDClass);

	if (!HUD)	{ return; }

	UCLASH_HUD_Player* HUD_Player = Cast<UCLASH_HUD_Player>(HUD);

	if (!HUD_Player) { return;}

	HUD_Player->BindToBaseUIComponent(this);
	HUD_Player->BindToPlayerUIComponent(this);
	HUD_Player->AddToViewport();
}

void UCLASH_UIComponent_Player::SettingInitValue()
{
	Super::SettingInitValue();

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
	float Max = UCLASH_AttributeSet_Player::ABSOLUTE_MAX_AWAKENING;
	float Percent = Data.NewValue / Max;
	OnAwakeningBarChanged.Broadcast(Percent);
}