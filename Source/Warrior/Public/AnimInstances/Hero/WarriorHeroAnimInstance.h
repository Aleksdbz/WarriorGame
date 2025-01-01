// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class AWarriorHeroCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()
	
public:


	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AnimData||Refrences")
	AWarriorHeroCharacter* OwningHeroCharacter;
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AnimData||LocomotionData")
	bool bShouldEnterRelaxedState;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="AnimData||LocomotionData")
	float EnterRelaxedStateThreshold = 5.f;

	float IdleElapsedTime;

	
	
};
