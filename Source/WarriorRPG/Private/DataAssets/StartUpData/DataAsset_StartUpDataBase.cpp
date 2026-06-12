// Copyright Jakub Kaczor


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/Abilities/WarriorRPGGameplayAbility.h"
#include "AbilitySystem/WarriorRPGAbilitySystemComponent.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorRPGAbilitySystemComponent* InWarriorRPGASCToGive,
	int32 ApplyLevel)
{
	check(InWarriorRPGASCToGive);
	
	GrantAbilities(ActivateOnGivenAbilities, InWarriorRPGASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InWarriorRPGASCToGive, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(
	const TArray<TSubclassOf<UWarriorRPGGameplayAbility>>& InAbilitiesToGive,
	UWarriorRPGAbilitySystemComponent* InWarriorRPGASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty()) return;
	
	for (const auto& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;
		
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InWarriorRPGASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		
		InWarriorRPGASCToGive->GiveAbility(AbilitySpec);
	}
}
