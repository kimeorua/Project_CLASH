// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/CLASH_CombatComponent.h"
#include "Component/Weapon/CLASH_WeaponComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#include "DebugHelper.h"

UCLASH_CombatComponent::UCLASH_CombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UCLASH_CombatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCLASH_CombatComponent::ExcuteTrace()
{
	if (!WeaponComp) { return; }

	if (HitedActor != nullptr) { return; }

	FVector CurrentStart = WeaponComp->GetSocketLocation(TraceData.WeaponAttachType, TraceData.StartSocket);
	FVector CurrentEnd = WeaponComp->GetSocketLocation(TraceData.WeaponAttachType, TraceData.EndSocket);
	FVector CurrentMid = (CurrentStart + CurrentEnd) * 0.5f;
	FQuat CurrentQuat = WeaponComp->GetSocketQuat(TraceData.WeaponAttachType, TraceData.StartSocket);

	FHitResult HitResult;
	bool bResultHit = false;

	if (!LastEnd.IsZero() && !LastMid.IsZero())
	{
		bResultHit = RunSweep(TraceData.TraceShape, LastEnd, CurrentEnd, CurrentQuat, HitResult);

		if (!bResultHit)
		{
			bResultHit = RunSweep(TraceData.TraceShape, LastMid, CurrentMid, CurrentQuat, HitResult);
		}
	}
	if (!bResultHit)
	{
		bResultHit = RunSweep(TraceData.TraceShape, CurrentStart, CurrentEnd, CurrentQuat, HitResult);
	}

	if (bResultHit)
	{
		AActor* Victim = HitResult.GetActor();
		if (HitedActor != Victim)
		{
			HitedActor = Victim;

			DebugHelper::Print("Hit : " + HitedActor->GetActorNameOrLabel());
		}
		else
		{
			DebugHelper::Print("Already Hit!");
		}
	}

	LastMid = CurrentMid;
	LastEnd = CurrentEnd;
}

bool UCLASH_CombatComponent::RunSweep(ETraceShapeType ShapeType, const FVector& Start, const FVector& End, const FQuat Quat, FHitResult& HitResult)
{
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());

	ETraceTypeQuery Chanel = UEngineTypes::ConvertToTraceType(TraceChannel);

	switch (ShapeType)
	{
	case ETraceShapeType::Sphere:
		return UKismetSystemLibrary::SphereTraceSingle
		(
			GetWorld(),
			Start,
			End,
			TraceData.ShapeDimensions.X,
			Chanel,
			false,
			ActorsToIgnore,
			bIsTraceShow ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None,
			HitResult,
			true
		);
	case ETraceShapeType::Box:
		return UKismetSystemLibrary::BoxTraceSingle
		(
			GetWorld(), 
			Start,
			End, 
			TraceData.ShapeDimensions, 
			Quat.Rotator(),
			Chanel,
			false,
			ActorsToIgnore, 
			bIsTraceShow ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None,
			HitResult, 
			true
		);
	default:
		return false;
	};
}

void UCLASH_CombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ExcuteTrace();
}

void UCLASH_CombatComponent::SetTreceData(FAttackData InAttackData)
{
	if (!WeaponComp) 
	{ 
		WeaponComp = GetOwner()->FindComponentByClass<UCLASH_WeaponComponent>(); 
	}
	TraceData = InAttackData;

	LastEnd = FVector::ZeroVector;
	LastMid = FVector::ZeroVector;
	HitedActor = nullptr;
}