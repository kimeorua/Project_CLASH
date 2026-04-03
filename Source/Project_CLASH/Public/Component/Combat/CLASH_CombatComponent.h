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

	virtual void HitCheack(AActor* Instigator);

protected:
	virtual void BeginPlay() override;	

private:
	void ExcuteTrace();

	FAttackData TraceData;

	UPROPERTY()
	TObjectPtr<UCLASH_WeaponComponent> WeaponComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat|Collision", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat|Collision", meta = (AllowPrivateAccess = "true"))
	bool bIsTraceShow = false;

	bool RunSweep(ETraceShapeType ShapeType, const FVector& Start, const FVector& End, const FQuat Quat , FHitResult& HitResult);

	FVector LastMid;
	FVector LastEnd;

	UPROPERTY()
	TObjectPtr<AActor> HitedActor;
};