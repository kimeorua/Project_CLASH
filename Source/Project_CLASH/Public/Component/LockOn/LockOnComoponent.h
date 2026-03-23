// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockOnComoponent.generated.h"

class UUserWidget;
class ACLASH_EnemyCharacter;

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

	UPROPERTY()
	TObjectPtr<ACLASH_EnemyCharacter> CachedEnemy;

	UPROPERTY(EditDefaultsOnly, Category = "Camera|Speed", meta = (AllowPrivateAccess = "true"))
	float CameraSpeed = 50.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Camera|UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> LockOnWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UUserWidget> LockOnUI;
	
	FVector2D LockOnUISize = FVector2D::ZeroVector;

	bool bIsLockOn = false;

	void TargetLockOnActivate(float DeltaTime);
	void LockOnUIOnOff(bool IsLockOn);
	void UIPostionSetting();
};
