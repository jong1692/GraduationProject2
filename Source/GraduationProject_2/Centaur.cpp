// Fill out your copyright notice in the Description page of Project Settings.

#include "Blade_DragonSword.h"
#include "Centaur.h"

ACentaur::ACentaur()
	: AEnemyCharacter(TEXT("SkeletalMesh'/Game/Art/QuadrapedCreatures/Centaur/Meshes/SK_Centaur'"))
{
	FVector scale = GetMesh()->GetRelativeTransform().GetScale3D();
	scale *= 0.8;
	GetMesh()->SetRelativeScale3D(scale);

	GetCapsuleComponent()->SetCapsuleHalfHeight(88.0f);
	GetCapsuleComponent()->SetCapsuleRadius(88.0f);

	weaponComponent = CreateDefaultSubobject<UBlade_DragonSword>(TEXT("WeaponComponent"));
	weaponComponent->SetOwner(this);
	weaponComponent->AttachToComponent(TEXT("SwordAction"));
}