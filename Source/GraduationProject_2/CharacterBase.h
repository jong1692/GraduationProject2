// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

#define MAX_HP 100

UCLASS()
class GRADUATIONPROJECT_2_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase(const wchar_t* meshPath);
	ACharacterBase() {}

	virtual void Tick(float DeltaTime) override;

	void ApplyDamage(ACharacter* damager, const int damage);

protected:
	virtual void BeginPlay() override;

	void BeginJump();
	void EndJump();

	virtual void BeginAttack();
	virtual void EndAttack();

public:	

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Damageable)
		class UDamageable* damageableComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
		class UWeapon* weaponComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
		bool canAttack;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
		bool isDamaged;
};
