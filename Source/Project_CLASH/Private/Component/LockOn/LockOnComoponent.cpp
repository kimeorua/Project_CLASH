// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/LockOn/LockOnComoponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/SizeBox.h"

#include "Animation/CLASH_AnimInstance_Player.h"
#include "Character/CLASH_EnemyCharacter.h"

ULockOnComoponent::ULockOnComoponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void ULockOnComoponent::BeginPlay()
{
	Super::BeginPlay();
}

void ULockOnComoponent::TargetLockOnActivate(float DeltaTime)
{
	if (bIsLockOn)
	{
		FVector LookAtLocation = TargetActor->GetActorLocation();
		FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), LookAtLocation);

		TargetRotation.Pitch = FMath::Clamp(TargetRotation.Pitch, -20.0f, 5.0f);

		APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
		if (!PC) { return; }

		const FRotator CurrentContrlloerRot = PC->GetControlRotation();
		const FRotator TargetRot = FMath::RInterpTo(CurrentContrlloerRot, TargetRotation, DeltaTime, CameraSpeed);

		PC->SetControlRotation(FRotator(TargetRot.Pitch, TargetRot.Yaw, 0.f));
	}
}

void ULockOnComoponent::LockOnUIOnOff(bool IsLockOn)
{
	if (IsLockOn)
	{
		APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
		LockOnUI = CreateWidget<UUserWidget>(PC, LockOnWidgetClass);
		LockOnUI->AddToViewport();

		if (LockOnUISize == FVector2D::ZeroVector)
		{
			LockOnUI->WidgetTree->ForEachWidget
			(
				[this](UWidget* FoundWidget)
				{
					if (USizeBox* FoundSizeBox = Cast<USizeBox>(FoundWidget))
					{
						LockOnUISize.X = FoundSizeBox->GetWidthOverride();
						LockOnUISize.Y = FoundSizeBox->GetHeightOverride();
					}
				}
			);
		}
	}
	else
	{
		if (LockOnUI)
		{
			LockOnUI->RemoveFromParent();
			LockOnUI = nullptr;
		}
	}
}

void ULockOnComoponent::UIPostionSetting()
{
	if (!LockOnUI || !bIsLockOn || !CachedEnemy) { return; }

	APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
	FVector2D ScreenPosition;

	bool bIsOnScreen = UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(
		PC,
		CachedEnemy->GetUISokcetPosition(),
		ScreenPosition,
		true
	);

	if (bIsOnScreen)
	{
		LockOnUI->SetVisibility(ESlateVisibility::HitTestInvisible);
		ScreenPosition -= (LockOnUISize / 2.f);
		LockOnUI->SetPositionInViewport(ScreenPosition, false);
	}
	else
	{
		LockOnUI->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void ULockOnComoponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (!IsValid(TargetActor))
	{
		SettingTargetActor(nullptr);
		return;
	}

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TargetLockOnActivate(DeltaTime);
	UIPostionSetting();
}

void ULockOnComoponent::SettingTargetActor(AActor* Target)
{ 
	TargetActor = Target;
	bIsLockOn = IsValid(TargetActor);
	CachedEnemy = bIsLockOn ? Cast<ACLASH_EnemyCharacter>(TargetActor) : nullptr;
	SetComponentTickEnabled(bIsLockOn);

	LockOnUIOnOff(bIsLockOn);

	if (ACharacter* OwnerChar = Cast<ACharacter>(GetOwner()))
	{
		if (UCLASH_AnimInstance_Player* AnimInst = Cast<UCLASH_AnimInstance_Player>(OwnerChar->GetMesh()->GetAnimInstance()))
		{
			AnimInst->SettingLockOnAnim(bIsLockOn);
		}
	}
}