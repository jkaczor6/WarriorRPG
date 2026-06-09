// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorRPGInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIORRPG_API UWarriorRPGInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template <class UserObject, typename CallbackFunc>
void UWarriorRPGInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input config data asset is null"));
	
	if (UInputAction* FoundAction{ InInputConfig->FindNativeInputActionByTag(InInputTag) })
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
