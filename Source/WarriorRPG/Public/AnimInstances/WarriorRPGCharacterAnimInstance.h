// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorRPGBaseAnimInstance.h"
#include "WarriorRPGCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class AWarriorRPGBaseCharacter;

UCLASS()
class WARRIORRPG_API UWarriorRPGCharacterAnimInstance : public UWarriorRPGBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY()
	TObjectPtr<AWarriorRPGBaseCharacter> OwningCharacter;
	
	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent> OwningMovementComponent;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
