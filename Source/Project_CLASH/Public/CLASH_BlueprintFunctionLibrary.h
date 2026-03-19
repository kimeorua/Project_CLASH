// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CLASH_BlueprintFunctionLibrary.generated.h"

UENUM()
enum class EClashConfirmType : uint8
{
    Yes,
    No
};

class ACLASH_BaseCharacter;

UCLASS()
class PROJECT_CLASH_API UCLASH_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "CLASH|Utility")
    static ACLASH_BaseCharacter* GetComponentOwner(const UActorComponent* Comp);

    UFUNCTION(BlueprintCallable, Category = "CLASH|Utility")
    static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

    UFUNCTION(BlueprintCallable, Category = "CLASH|Utility")
    static void RemoveGameplayTagToActorIfFind(AActor* InActor, FGameplayTag TagToRemove);

    static bool NativeDoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

    UFUNCTION(BlueprintCallable, Category = "CLASH|Utility", meta = (DisplayName = "Dose Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
    static void BP_DoseActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EClashConfirmType& OutConfirmType);
};