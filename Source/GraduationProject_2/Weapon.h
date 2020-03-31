// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Weapon.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GRADUATIONPROJECT_2_API UWeapon : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UWeapon() {}
	UWeapon(const wchar_t* meshPath, 
		const int damage = 10, const float attackSpeed = 1.0f);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	void SetAttackSpeed(const float attackSpeed);

	void SetDamage(const int damage);

	void SetOwner(class ACharacter* owner);

	void AttachToComponent(const wchar_t* socketName);

	void SetRotation(const FRotator& rotator);
	void SetRotation(const float x, const float y, const float z);
	FRotator GetRotation() const;

	void SetLocation(const FVector& vector);
	void SetLocation(const float x, const float y, const float z);
	FVector GetLocation() const;

	void SetScale(const FVector& vector);
	void SetScale(const float x, const float y, const float z);
	FVector GetScale() const;


	USkeletalMeshComponent* GetWeaponMesh() const;

	virtual void BeginAttack();
	virtual void EndAttack();

protected:


public:


protected:
	int damage;
	float attackSpeed;
	class ACharacter* owner;

	UPROPERTY(VisibleAnywhere, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
		class USkeletalMeshComponent* weaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
		bool isAttacking;
	UPROPERTY(VisibleAnywhere, Category = "Collider")
		UBoxComponent* boxCollider;
};
