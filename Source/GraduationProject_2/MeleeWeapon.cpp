// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h"
#include "Containers/Array.h"
#include "CharacterBase.h"
#include "MeleeWeapon.h"


UMeleeWeapon::UMeleeWeapon(const wchar_t* meshPath,
	const int damage, const float attackSpeed)
	: UWeapon(meshPath, damage, attackSpeed)
{

	boxCollider->OnComponentBeginOverlap.AddDynamic(this, &UMeleeWeapon::OnOverlapBegin);
	boxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UMeleeWeapon::BeginPlay()
{
	Super::BeginPlay();

}

void UMeleeWeapon::BeginAttack()
{
	Super::BeginAttack();

	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void UMeleeWeapon::EndAttack()
{
	Super::EndAttack();

	damagedActorBuffer.Reset();
	boxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UMeleeWeapon::OnOverlapBegin(class UPrimitiveComponent* overlappedComp,
	class AActor* otherActor, class UPrimitiveComponent* otherComp,
	int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor != nullptr && otherActor != owner && otherComp)
	{
		auto target = dynamic_cast<ACharacterBase*>(otherActor);

		if (target != nullptr && !damagedActorBuffer.Contains(target))
		{
			target->ApplyDamage(owner, damage);

			damagedActorBuffer.Add(target);
		}
	}
}