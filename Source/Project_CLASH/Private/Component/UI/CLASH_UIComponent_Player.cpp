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

	const UCLASH_AttributeSet_Player* CLASHAttribute_Base = ASC->GetSet<UCLASH_AttributeSet_Player>();

	float Max = UCLASH_AttributeSet_Player::ABSOLUTE_MAX_AWAKENING;
	float Percent = CLASHAttribute_Base->GetAwakening() / Max;

	OnCurrentAwakeningChanged(Percent);
}

void UCLASH_UIComponent_Player::BindUpdage(UAbilitySystemComponent* InASC)
{
	Super::BindUpdage(InASC);

	UCLASH_AttributeSet_Player* CLASHAttribute_Player = const_cast<UCLASH_AttributeSet_Player*>(InASC->GetSet<UCLASH_AttributeSet_Player>());
	CLASHAttribute_Player->OnUpdateAwakeningUI.AddDynamic(this, &UCLASH_UIComponent_Player::OnCurrentAwakeningChanged);
}

void UCLASH_UIComponent_Player::OnCurrentAwakeningChanged(float Percent)
{
	OnAwakeningBarChanged.Broadcast(Percent);
}