// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CLASH_AnimInstance_Base.h"
#include "CLASH_AnimInstance_Player.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_CLASH_API UCLASH_AnimInstance_Player : public UCLASH_AnimInstance_Base
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;

	FORCEINLINE void SettingLockOnAnim(const bool IsLockOn) { bIsLockOn = IsLockOn; }
	FORCEINLINE void SettingGuardAnim(const bool IsGuard) { bIsGuard = IsGuard; }

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData", meta = (AllowPrivateAccess = "true"))
	bool bIsLockOn = false;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomationData", meta = (AllowPrivateAccess = "true"))
	bool bIsGuard = false;
};
