// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorRPGCharacterAnimInstance.h"
#include "WarriorRPGHeroAnimInstance.generated.h"

class AWarriorRPGHeroCharacter;

UCLASS()
class WARRIORRPG_API UWarriorRPGHeroAnimInstance : public UWarriorRPGCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
	TObjectPtr<AWarriorRPGHeroCharacter> OwningHeroCharacter;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold{ 5.f };
	
	float IdleElapsedTime;
};
