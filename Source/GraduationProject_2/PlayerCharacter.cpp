// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Engine.h"
#include "PlayerWeapon.h"
#include "Damageable.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
	: ACharacterBase(TEXT("SkeletalMesh'/Game/Art/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Barbarous'"))
{
	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->TargetArmLength = 300.0f;
	cameraBoom->bUsePawnControlRotation = true;

	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	followCamera->bUsePawnControlRotation = false;

	weaponComponent = CreateDefaultSubobject<UPlayerWeapon>(TEXT("WeaponComponent"));
	weaponComponent->SetOwner(this);
	weaponComponent->AttachToComponent(TEXT("hand_rSocket"));
}

void APlayerCharacter::BeginAttack()
{
	Super::BeginAttack();
}

void APlayerCharacter::EndAttack()
{
	Super::EndAttack();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveSide", this, &APlayerCharacter::MoveSide);

	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::BeginJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::EndJump);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::BeginAttack);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &APlayerCharacter::EndAttack);
}

void APlayerCharacter::MoveForward(const float value)
{
	if (value != 0)
	{
		const FVector direction = FRotationMatrix(GetActorRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(direction, value);
	}
}

void APlayerCharacter::MoveSide(const float value)
{
	if (value != 0)
	{
		const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(direction, value);
	}
}
