// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WarriorRPGWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class WARRIORRPG_API AWarriorRPGWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AWarriorRPGWeaponBase();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapons")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapons")
	TObjectPtr<UBoxComponent> WeaponCollisionBox;
	
public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }
};
