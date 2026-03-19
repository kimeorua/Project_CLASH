// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/LockOn/LockOnComoponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"

#include "DebugHelper.h"

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

		TargetRotation.Pitch = FMath::Clamp(TargetRotation.Pitch, -40.0f, 20.0f);

		APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
		if (!PC) { return; }

		const FRotator CurrentContrlloerRot = PC->GetControlRotation();
		const FRotator TargetRot = FMath::RInterpTo(CurrentContrlloerRot, TargetRotation, DeltaTime, CameraSpeed);

		PC->SetControlRotation(FRotator(TargetRot.Pitch, TargetRot.Yaw, 0.f));
		GetOwner()->SetActorRotation(FRotator(0.f, TargetRot.Yaw, 0.f));
	}
}

void ULockOnComoponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TargetLockOnActivate(DeltaTime);
	if (!IsValid(TargetActor))
	{
		SettingTargetActor(nullptr);
		return;
	}
}

void ULockOnComoponent::SettingTargetActor(AActor* Target)
{ 
	TargetActor = Target;
	bIsLockOn = IsValid(TargetActor);

	SetComponentTickEnabled(bIsLockOn);
}