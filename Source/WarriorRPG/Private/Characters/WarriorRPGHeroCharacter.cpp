// Copyright Jakub Kaczor


#include "Characters/WarriorRPGHeroCharacter.h"
#include "WarriorRPGDebugHelper.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/Input/WarriorRPGInputComponent.h"
#include "WarriorRPGGameplayTags.h"
#include "AbilitySystem/WarriorRPGAbilitySystemComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Components/Combat/HeroCombatComponent.h"


AWarriorRPGHeroCharacter::AWarriorRPGHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	
	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>("HeroCombatComponent");
}

void AWarriorRPGHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWarriorRPGHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (CharacterStartUpData.IsNull()) return;
	
	if (UDataAsset_StartUpDataBase* LoadedData{ CharacterStartUpData.LoadSynchronous() })
	{
		LoadedData->GiveToAbilitySystemComponent(WarriorAbilitySystemComponent);
	}
}

void AWarriorRPGHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	checkf(InputConfigDataAsset, TEXT("Input config data asset is null"));
	
	ULocalPlayer* LocalPlayer{ GetController<APlayerController>()->GetLocalPlayer() };
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem{ ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer) };
	check(Subsystem);
	
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);
	
	UWarriorRPGInputComponent* WarriorInputComponent{ CastChecked<UWarriorRPGInputComponent>(PlayerInputComponent) };
	
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorRPG::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorRPG::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void AWarriorRPGHeroCharacter::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MoveVector{ Value.Get<FVector2D>() };
	const FRotator MoveRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
	
	if (MoveVector.Y != 0.f)
	{
		const FVector ForwardDirection{ MoveRotation.RotateVector(FVector::ForwardVector) };
		
		AddMovementInput(ForwardDirection, MoveVector.Y);
	}
	
	if (MoveVector.X != 0.f)
	{
		const FVector RightDirection{ MoveRotation.RotateVector(FVector::RightVector) };
		
		AddMovementInput(RightDirection, MoveVector.X);
	}
}

void AWarriorRPGHeroCharacter::Input_Look(const FInputActionValue& Value)
{
	const FVector2D LookAxis{ Value.Get<FVector2D>() };	
	
	if (LookAxis.X != 0.f)
	{
		AddControllerYawInput(LookAxis.X);
	}
	if (LookAxis.Y != 0.f)
	{
		AddControllerPitchInput(LookAxis.Y);
	}
}
