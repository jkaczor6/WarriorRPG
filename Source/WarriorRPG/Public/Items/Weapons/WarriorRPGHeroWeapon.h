// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/WarriorRPGWeaponBase.h"
#include "WarriorTypes/WarriorRPGStructTypes.h"
#include "WarriorRPGHeroWeapon.generated.h"

UCLASS()
class WARRIORRPG_API AWarriorRPGHeroWeapon : public AWarriorRPGWeaponBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FWarriorRPGHeroWeaponData HeroWeaponData;
};
