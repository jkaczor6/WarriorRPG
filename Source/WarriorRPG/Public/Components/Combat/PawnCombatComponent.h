// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionsComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AWarriorRPGWeaponBase;
/**
 * 
 */
UCLASS()
class WARRIORRPG_API UPawnCombatComponent : public UPawnExtensionsComponentBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "WarriorRPG|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorRPGWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "WarriorRPG|Combat")
	AWarriorRPGWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;
	
	UPROPERTY(BlueprintReadWrite, Category = "WarriorRPG|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "WarriorRPG|Combat")
	AWarriorRPGWeaponBase* GetCharacterCurrentEquippedWeapon() const;
	
private:
	TMap<FGameplayTag, AWarriorRPGWeaponBase*> CharacterCarriedWeaponMap;
};
