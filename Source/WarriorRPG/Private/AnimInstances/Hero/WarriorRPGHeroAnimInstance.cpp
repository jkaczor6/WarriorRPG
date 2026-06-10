// Copyright Jakub Kaczor


#include "AnimInstances/Hero/WarriorRPGHeroAnimInstance.h"

#include "Characters/WarriorRPGHeroCharacter.h"

void UWarriorRPGHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorRPGHeroCharacter>(OwningCharacter);
	}
	
}

void UWarriorRPGHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	
	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateThreshold);
	}
}
