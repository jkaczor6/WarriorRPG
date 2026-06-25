// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorRPGBaseAnimInstance.h"
#include "WarriorRPGHeroLinkedAnimLayer.generated.h"

class UWarriorRPGHeroAnimInstance;

UCLASS()
class WARRIORRPG_API UWarriorRPGHeroLinkedAnimLayer : public UWarriorRPGBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UWarriorRPGHeroAnimInstance* GetHeroAnimInstance() const; 
};
