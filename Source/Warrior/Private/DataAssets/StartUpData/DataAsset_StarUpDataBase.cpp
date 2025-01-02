// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StarUpDataBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "GameplayAbilitySpec.h"

void UDataAsset_StarUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InWarriorAscToGive,
                                                           int32 ApplyLevel)
{
	check(InWarriorAscToGive);
	GrandAbilities(ActivateOnGiveAbility,InWarriorAscToGive,ApplyLevel);
	GrandAbilities(ReactiveAbilities,InWarriorAscToGive,ApplyLevel);
}

void UDataAsset_StarUpDataBase::GrandAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,
	UWarriorAbilitySystemComponent* InWarriorAscToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InWarriorAscToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InWarriorAscToGive->GiveAbility(AbilitySpec);
	}
	
	
}
