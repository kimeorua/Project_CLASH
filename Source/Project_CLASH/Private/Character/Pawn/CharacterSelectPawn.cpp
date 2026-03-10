// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Pawn/CharacterSelectPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACharacterSelectPawn::ACharacterSelectPawn()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 10.0f;
	SpringArm->SocketOffset = FVector(0.0f, 20.0f, 60.0f);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->SetFieldOfView(90.0f);
}

void ACharacterSelectPawn::BeginPlay()
{
	Super::BeginPlay();
}