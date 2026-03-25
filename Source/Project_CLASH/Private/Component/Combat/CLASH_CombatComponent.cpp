// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Combat/CLASH_CombatComponent.h"
#include "Component/Weapon/CLASH_WeaponComponent.h"
#include "DrawDebugHelpers.h"

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

	FVector CurrentStart = WeaponComp->GetSocketLocation(TraceData.WeaponAttachType, TraceData.StartSocket);
	FVector CurrentEnd = WeaponComp->GetSocketLocation(TraceData.WeaponAttachType, TraceData.EndSocket);
	FVector CurentMid = (CurrentStart + CurrentEnd) * 0.5f;
	FQuat CurrentQuat = WeaponComp->GetSocketQuat(TraceData.WeaponAttachType, TraceData.StartSocket);
	FCollisionShape SweepShape = GetCollisionShapeFromData(TraceData.TraceShape);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	bool Correction1 = false;
	bool Correction2 = false;
	bool Main = false;

	if (!LastEnd.IsZero())
	{
		Correction1 = RunSweep(LastEnd, CurrentEnd, CurrentQuat, SweepShape, Params);
		Correction2 = RunSweep(LastMid, CurentMid, CurrentQuat, SweepShape, Params);
	}
	Main = RunSweep(CurrentStart, CurrentEnd, CurrentQuat, SweepShape, Params);

#if !UE_BUILD_SHIPPING
	FColor MainColor = Main ? FColor::Green : FColor::Red;
	FColor Correction1Color = Correction1 ? FColor::Green : FColor::Purple;
	FColor Correction2Color = Correction2 ? FColor::Green : FColor::Blue;
	float DebugDrawTime = 0.5f; 

	float Radius = TraceData.ShapeDimensions.X;
	float HalfHeight = (TraceData.TraceShape == ETraceShapeType::Capsule) ? TraceData.ShapeDimensions.Y : Radius;

	{
		FVector MainDir = CurrentStart - CurrentEnd;
		FVector MainCenter = (CurrentStart + CurrentEnd) * 0.5f;
		float MainHalfHeight = MainDir.Size() * 0.5f;
		FQuat MainRot = MainDir.IsNearlyZero() ? CurrentQuat : FRotationMatrix::MakeFromZ(MainDir).ToQuat();

		DrawDebugCapsule(GetWorld(), MainCenter, MainHalfHeight + HalfHeight, Radius, MainRot, MainColor, false, DebugDrawTime);
	}

	if (!LastEnd.IsZero())
	{
		FVector Corr1Dir = LastEnd - CurrentEnd;
		FVector Corr1Center = (LastEnd + CurrentEnd) * 0.5f;
		float Corr1HalfHeight = Corr1Dir.Size() * 0.5f;
		FQuat Corr1Rot = Corr1Dir.IsNearlyZero() ? CurrentQuat : FRotationMatrix::MakeFromZ(Corr1Dir).ToQuat();

		DrawDebugCapsule(GetWorld(), Corr1Center, Corr1HalfHeight + HalfHeight, Radius, Corr1Rot, Correction1Color, false, DebugDrawTime);
	}

	if (!LastMid.IsZero())
	{
		FVector Corr2Dir = LastMid - CurentMid;
		FVector Corr2Center = (LastMid + CurentMid) * 0.5f;
		float Corr2HalfHeight = Corr2Dir.Size() * 0.5f;
		FQuat Corr2Rot = Corr2Dir.IsNearlyZero() ? CurrentQuat : FRotationMatrix::MakeFromZ(Corr2Dir).ToQuat();

		DrawDebugCapsule(GetWorld(), Corr2Center, Corr2HalfHeight + HalfHeight, Radius, Corr2Rot, Correction2Color, false, DebugDrawTime);
	}
#endif

	LastMid = CurentMid;
	LastEnd = CurrentEnd;
}

FCollisionShape UCLASH_CombatComponent::GetCollisionShapeFromData(ETraceShapeType ShapeType)
{
	switch (ShapeType)
	{
	case ETraceShapeType::Sphere:
		return FCollisionShape::MakeSphere(TraceData.ShapeDimensions.X);

	case ETraceShapeType::Box:
		return FCollisionShape::MakeBox(TraceData.ShapeDimensions);

	case ETraceShapeType::Capsule:
		return FCollisionShape::MakeCapsule(TraceData.ShapeDimensions.X, TraceData.ShapeDimensions.Y);

	default:
		return FCollisionShape::MakeSphere(TraceData.ShapeDimensions.X);
	}
}

bool UCLASH_CombatComponent::RunSweep(const FVector& Start, const FVector& End, const FQuat Quat, const FCollisionShape& Shape, const FCollisionQueryParams& Params)
{
	FHitResult OutHit;
	return GetWorld()->SweepSingleByChannel(OutHit, Start, End, Quat, TraceChannel, Shape, Params);
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
}