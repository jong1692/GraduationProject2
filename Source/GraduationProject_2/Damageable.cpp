// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "Damageable.h"

// Sets default values for this component's properties
UDamageable::UDamageable()
{
	PrimaryComponentTick.bCanEverTick = true;

	isDied = false;

	maxHp = 100;
	curHp = maxHp;
}


// Called when the game starts
void UDamageable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDamageable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UDamageable::Init(const int hpAmount)
{
	maxHp = hpAmount;
	curHp = maxHp;
}

void UDamageable::ApplyDamage(ACharacter* damager, const int damage)
{
	if (isDied) return;

	curHp -= damage;
	if (curHp <= 0)
	{
		curHp = 0;
		isDied = true;
	}
}
