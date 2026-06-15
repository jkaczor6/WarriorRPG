// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorRPGBaseCharacter.h"
#include "WarriorRPGHeroCharacter.generated.h"

class UDataAsset_InputConfig;
class USpringArmComponent;
class UCameraComponent;
class UHeroCombatComponent;
struct FInputActionValue;

UCLASS()
class WARRIORRPG_API AWarriorRPGHeroCharacter : public AWarriorRPGBaseCharacter
{
	GENERATED_BODY()
	
public:
	AWarriorRPGHeroCharacter();
protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
private:
	
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> FollowCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = true))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent;
#pragma endregion
	
	
#pragma region Inputs
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = true))
	UDataAsset_InputConfig* InputConfigDataAsset;
	
	void Input_Move(const FInputActionValue& Value);
	void Input_Look(const FInputActionValue& Value);
#pragma endregion
	
public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};
