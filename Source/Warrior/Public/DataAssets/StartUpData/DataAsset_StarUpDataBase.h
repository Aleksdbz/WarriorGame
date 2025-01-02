// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StarUpDataBase.generated.h"

class UWarriorGameplayAbility;
class UWarriorAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StarUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorAscToGive,int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly,Category="StartUpData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ActivateOnGiveAbility;
	UPROPERTY(EditDefaultsOnly,Category="StartUpData")
	TArray<TSubclassOf<UWarriorGameplayAbility>> ReactiveAbilities;

	void GrandAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>> & InAbilitiesToGive,UWarriorAbilitySystemComponent* InWarriorAscToGive, int32 ApplyLevel = 1);
	
};
