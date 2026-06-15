// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorRPGGameplayAbility.h"
#include "WarriorRPGHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class AWarriorRPGHeroController;
class AWarriorRPGHeroCharacter;

/**
 * 
 */
UCLASS()
class WARRIORRPG_API UWarriorRPGHeroGameplayAbility : public UWarriorRPGGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "WarriorRPG|Ability")
	AWarriorRPGHeroCharacter* GetHeroCharacterFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "WarriorRPG|Ability")
	AWarriorRPGHeroController* GetHeroControllerFromActorInfo();
	
	UFUNCTION(BlueprintPure, Category = "WarriorRPG|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
	
private:
	TWeakObjectPtr<AWarriorRPGHeroCharacter> CachedWarriorRPGHeroCharacter;
	TWeakObjectPtr<AWarriorRPGHeroController> CachedWarriorRPGHeroController;
};
