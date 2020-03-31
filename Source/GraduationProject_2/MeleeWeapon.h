// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "MeleeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GRADUATIONPROJECT_2_API UMeleeWeapon : public UWeapon
{
	GENERATED_BODY()

public:
	UMeleeWeapon() {}
	UMeleeWeapon(const wchar_t* meshPath, 
		const int damage = 10, const float attackSpeed = 1.0f);

	virtual void BeginAttack() override;
	virtual void EndAttack() override;

protected:

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void BeginPlay() override;

private:
	TArray<class ACharacterBase*> damagedActorBuffer;

	const int damagedBufferSize = 32;
};
