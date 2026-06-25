// Copyright Jakub Kaczor


#include "AnimInstances/Hero/WarriorRPGHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/WarriorRPGHeroAnimInstance.h"

UWarriorRPGHeroAnimInstance* UWarriorRPGHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorRPGHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
