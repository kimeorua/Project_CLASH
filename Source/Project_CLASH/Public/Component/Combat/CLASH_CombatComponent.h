// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Type/GameStructs/CLASH_GameStructs.h"
#include "CLASH_CombatComponent.generated.h"

class UCLASH_WeaponComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_CLASH_API UCLASH_CombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCLASH_CombatComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetTreceData(FAttackData InAttackData);

protected:
	virtual void BeginPlay() override;	

private:
	void ExcuteTrace();

	FAttackData TraceData;

	UPROPERTY()
	TObjectPtr<UCLASH_WeaponComponent> WeaponComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat|Collision", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<ECollisionChannel> TraceChannel;

	FCollisionShape GetCollisionShapeFromData(ETraceShapeType ShapeType);

	bool RunSweep(const FVector& Start, const FVector& End, const FQuat Quat, const FCollisionShape& Shape, const FCollisionQueryParams& Params);

	FVector LastMid;
	FVector LastEnd;
};
