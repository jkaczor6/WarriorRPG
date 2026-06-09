// Copyright Jakub Kaczor


#include "Characters/WarriorRPGBaseCharacter.h"

AWarriorRPGBaseCharacter::AWarriorRPGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}

