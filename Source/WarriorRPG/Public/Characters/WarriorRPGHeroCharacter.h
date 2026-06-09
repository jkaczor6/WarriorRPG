// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorRPGBaseCharacter.h"
#include "WarriorRPGHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class WARRIORRPG_API AWarriorRPGHeroCharacter : public AWarriorRPGBaseCharacter
{
	GENERATED_BODY()
	
public:
	AWarriorRPGHeroCharacter();
protected:
	virtual void BeginPlay();
	
private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> FollowCamera;
#pragma endregion
};
