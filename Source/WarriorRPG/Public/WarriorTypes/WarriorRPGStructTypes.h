// Copyright Jakub Kaczor

#pragma once

#include "WarriorRPGStructTypes.generated.h"

class UWarriorRPGHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FWarriorRPGHeroWeaponData
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorRPGHeroLinkedAnimLayer> WeaponAnimLayerToLink;
};