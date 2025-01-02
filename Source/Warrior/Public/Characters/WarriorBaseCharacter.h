// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "WarriorBaseCharacter.generated.h"

class UDataAsset_StarUpDataBase;
class UWarriorAttributeSet;
class UWarriorAbilitySystemComponent;
UCLASS()
class WARRIOR_API AWarriorBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	public:
	AWarriorBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "AbilitySystem")
	UWarriorAbilitySystemComponent* WarriorAbilitySystemComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "AbilitySystem")
	UWarriorAttributeSet* WarriorAttributeSet;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StarUpDataBase> CharacterStartUpData;

	virtual void PossessedBy(AController* NewController) override;

public:
	FORCEINLINE UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; }
	FORCEINLINE UWarriorAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }

};