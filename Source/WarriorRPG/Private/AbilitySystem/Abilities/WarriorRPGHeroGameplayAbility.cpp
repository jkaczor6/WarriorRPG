// Copyright Jakub Kaczor


#include "AbilitySystem/Abilities/WarriorRPGHeroGameplayAbility.h"
#include "Characters/WarriorRPGHeroCharacter.h"
#include "Controllers/WarriorRPGHeroController.h"
#include "Components/Combat/HeroCombatComponent.h"

AWarriorRPGHeroCharacter* UWarriorRPGHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorRPGHeroCharacter.IsValid())
	{
		CachedWarriorRPGHeroCharacter = Cast<AWarriorRPGHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedWarriorRPGHeroCharacter.IsValid() ? CachedWarriorRPGHeroCharacter.Get() : nullptr;
}

AWarriorRPGHeroController* UWarriorRPGHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorRPGHeroController.IsValid())
	{
		CachedWarriorRPGHeroController = Cast<AWarriorRPGHeroController>(CurrentActorInfo->PlayerController);
	}
	
	return CachedWarriorRPGHeroController.IsValid() ? CachedWarriorRPGHeroController.Get() : nullptr;
}

UHeroCombatComponent* UWarriorRPGHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
