// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UWarriorRPGAbilitySystemComponent;
class UWarriorRPGGameplayAbility;

/**
 * 
 */
UCLASS()
class WARRIORRPG_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UWarriorRPGAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
protected:
	
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<UWarriorRPGGameplayAbility>> ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<UWarriorRPGGameplayAbility>> ReactiveAbilities;
	
	void GrantAbilities(const TArray<TSubclassOf<UWarriorRPGGameplayAbility>>& InAbilitiesToGive, UWarriorRPGAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
};
