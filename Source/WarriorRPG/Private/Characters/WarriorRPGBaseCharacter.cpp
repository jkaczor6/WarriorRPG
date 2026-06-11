// Copyright Jakub Kaczor


#include "Characters/WarriorRPGBaseCharacter.h"

#include "AbilitySystem/WarriorRPGAbilitySystemComponent.h"
#include "AbilitySystem/WarriorRPGAttributeSet.h"

AWarriorRPGBaseCharacter::AWarriorRPGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
	
	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorRPGAbilitySystemComponent>("WarriorAbilitySystemComponent");
	WarriorAttributeSet = CreateDefaultSubobject<UWarriorRPGAttributeSet>("WarriorAttributeSet");
}

UAbilitySystemComponent* AWarriorRPGBaseCharacter::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}

void AWarriorRPGBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (WarriorAbilitySystemComponent)
	{
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}
