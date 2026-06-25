// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AWarriorRPGHeroWeapon;

/**
 * 
 */
UCLASS()
class WARRIORRPG_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WarriorRPG|Combat")
	AWarriorRPGHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag);
};
