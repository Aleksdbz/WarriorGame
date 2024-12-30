// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsseet/Input/MyDataAsset_InputConfig.h"

UInputAction* UMyDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag InInputTag) const
{
	for (const FWarriorInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
