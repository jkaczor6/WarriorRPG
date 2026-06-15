// Copyright Jakub Kaczor


#include "Components/Combat/PawnCombatComponent.h"
#include "WarriorRPGDebugHelper.h"
#include "Items/Weapons/WarriorRPGWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,
	AWarriorRPGWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	check(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister));
	check(InWeaponToRegister);
	
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	
	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}
	
	const FString WeaponString{ FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString()) };
	Debug::Print(WeaponString);
}

AWarriorRPGWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (AWarriorRPGWeaponBase* const* FoundWeapon{ CharacterCarriedWeaponMap.Find(InWeaponTagToGet) })
		{
			return *FoundWeapon;
		}
	}
	
	return nullptr;
}

AWarriorRPGWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid()) return nullptr;
	
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
