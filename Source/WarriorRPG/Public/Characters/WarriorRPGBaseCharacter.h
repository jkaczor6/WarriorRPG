// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "WarriorRPGBaseCharacter.generated.h"

class UWarriorRPGAbilitySystemComponent;
class UWarriorRPGAttributeSet;

UCLASS()
class WARRIORRPG_API AWarriorRPGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AWarriorRPGBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	
	virtual void PossessedBy(AController* NewController) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorRPGAbilitySystemComponent> WarriorAbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UWarriorRPGAttributeSet> WarriorAttributeSet;
	
public:
	FORCEINLINE UWarriorRPGAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; }
	FORCEINLINE UWarriorRPGAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }
};
