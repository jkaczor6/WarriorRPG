// Copyright Jakub Kaczor


#include "AbilitySystem/WarriorRPGAbilitySystemComponent.h"

void UWarriorRPGAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;
	
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;
		
		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UWarriorRPGAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}
