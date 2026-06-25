// Copyright Jakub Kaczor


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/WarriorRPGHeroWeapon.h"

AWarriorRPGHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag)
{
	return Cast<AWarriorRPGHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
