// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockOnComoponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_CLASH_API ULockOnComoponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	ULockOnComoponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SettingTargetActor(AActor* Target);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(EditDefaultsOnly, Category = "Camera|Speed", meta = (AllowPrivateAccess = "true"))
	float CameraSpeed = 50.0f;

	bool bIsLockOn = false;

	void TargetLockOnActivate(float DeltaTime);
};
