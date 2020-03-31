// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine.h"
#include "PlayerWeapon.h"
#include "Damageable.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterBase.h"


ACharacterBase::ACharacterBase(const wchar_t* meshPath)
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	static ConstructorHelpers::
		FObjectFinder<USkeletalMesh> characterMesh(meshPath);

	if (characterMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(characterMesh.Object);
	}

	damageableComponent = CreateDefaultSubobject<UDamageable>(TEXT("Damageable"));
	check(damageableComponent);
	damageableComponent->Init(MAX_HP);
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACharacterBase::BeginAttack()
{
	canAttack = true;

	if (weaponComponent != nullptr)
		weaponComponent->BeginAttack();
}

void ACharacterBase::EndAttack()
{
	if (weaponComponent != nullptr)
		weaponComponent->EndAttack();
}

void ACharacterBase::ApplyDamage(ACharacter* damager, const int damage)
{
	if (damageableComponent != nullptr)
	{
		damageableComponent->ApplyDamage(damager, damage);
		isDamaged = true;
	}
}

void ACharacterBase::BeginJump()
{
	bPressedJump = true;
}

void ACharacterBase::EndJump()
{
	bPressedJump = false;
}

