// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorRPGGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EWarriorRPGAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

UCLASS()
class WARRIORRPG_API UWarriorRPGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "WarriorRPGAbility")
	EWarriorRPGAbilityActivationPolicy AbilityActivationPolicy{ EWarriorRPGAbilityActivationPolicy::OnTriggered };
};
