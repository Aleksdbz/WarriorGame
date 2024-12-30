// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAsseet/Input/MyDataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

struct FGameplayTag;
class UMyDataAsset_InputConfig;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:

	template<class UserObject,typename CallbackFunc>
	void BindNativeInputAction(const UMyDataAsset_InputConfig* InInputConfig,
		const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent, UserObject* ContextObject,CallbackFunc Func);
};

template <class UserObject, typename CallbackFunc>
void UWarriorInputComponent::BindNativeInputAction(const UMyDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig,TEXT("You must provide a valid InputConfig"));
	if (UInputAction* FoundAction  =  InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		 BindAction(FoundAction,TriggerEvent,ContextObject,Func);
	}
}
