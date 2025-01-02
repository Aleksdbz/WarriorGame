// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

struct FInputActionValue;
class UCameraComponent;
class USpringArmComponent;
class UMyDataAsset_InputConfig;
/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorHeroCharacter();
protected:

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

	

private:
#pragma region Components

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera",Meta=(AllowPrivateAccess=true))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera",Meta=(AllowPrivateAccess=true))
	UCameraComponent* FollowCamera;

	virtual void PossessedBy(AController* NewController) override;

	
#pragma endregion

	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="CharacterData",Meta=(AllowPrivateAccess=true))
	UMyDataAsset_InputConfig* InputConfigDataAsset;
#pragma region Inputs

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
#pragma endregion
};
