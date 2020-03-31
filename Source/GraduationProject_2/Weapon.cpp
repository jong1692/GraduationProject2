// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Engine.h" 
#include "UObject/ConstructorHelpers.h"
//#include "Components/BoxComponent.h"



// Sets default values
UWeapon::UWeapon(const wchar_t* meshPath, 
	const int damage, const float attackSpeed)
{
	PrimaryComponentTick.bCanEverTick = true;

	ConstructorHelpers::
		FObjectFinder<USkeletalMesh> weaponMesh(meshPath);
	
	this->weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMeshComponent"));
	check(weaponMesh.Succeeded())
		this->weaponMesh->SetSkeletalMesh(weaponMesh.Object);

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	check(boxCollider != nullptr)
		boxCollider->SetupAttachment(this->weaponMesh);

	this->damage = damage;
	this->attackSpeed = attackSpeed;
}

// Called when the game starts or when spawned
void UWeapon::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeapon::BeginAttack()
{
}

void UWeapon::EndAttack()
{
	
}

void UWeapon::SetDamage(const int damage)
{
	if (damage >= 0)
		this->damage = damage;
	else
		this->damage = 0;
}

void UWeapon::SetAttackSpeed(const float attackSpeed)
{
	if (attackSpeed >= 0)
		this->attackSpeed = attackSpeed;
	else
		this->attackSpeed = 0;
}

void UWeapon::SetOwner(class ACharacter* owner)
{
	if (owner != nullptr)
		this->owner = owner;
}

void UWeapon::SetRotation(const FRotator& rotator)
{
	weaponMesh->SetRelativeRotation(rotator);
}

void UWeapon::SetRotation(const float x, const float y, const float z)
{
	weaponMesh->SetRelativeRotation(FRotator(x, y, z));
}

FRotator UWeapon::GetRotation() const
{
	return weaponMesh->GetRelativeTransform().Rotator();
}

void UWeapon::SetLocation(const FVector& vector)
{
	weaponMesh->SetRelativeLocation(vector);
}

void UWeapon::SetLocation(const float x, const float y, const float z)
{
	weaponMesh->SetRelativeLocation(FVector(x, y, z));
}

FVector UWeapon::GetLocation() const
{
	return weaponMesh->GetRelativeTransform().GetLocation();
}

void UWeapon::SetScale(const FVector& vector)
{
	weaponMesh->SetRelativeScale3D(vector);
}

void UWeapon::SetScale(const float x, const float y, const float z)
{
	weaponMesh->SetRelativeScale3D(FVector(x,y,z));
}

FVector UWeapon::GetScale() const
{
	return weaponMesh->GetRelativeTransform().GetScale3D();
}


void UWeapon::AttachToComponent(const wchar_t* socketName)
{
	weaponMesh->AttachToComponent(this->owner->GetMesh(),
		FAttachmentTransformRules::SnapToTargetNotIncludingScale, socketName);
}

USkeletalMeshComponent* UWeapon::GetWeaponMesh() const
{
	return weaponMesh;
}


