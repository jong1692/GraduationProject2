// Fill out your copyright notice in the Description page of Project Settings.


#include "Blade_DragonSword.h"

UBlade_DragonSword::UBlade_DragonSword()
	: UMeleeWeapon
	(TEXT("SkeletalMesh'/Game/Art/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_DragonSword/SK_Blade_DragonSword'"),
		WEAPON_DAMAGE, WEAPON_ATTACKSPEED)
{
	//FVector vector = GetLocation();
	//vector.Z -= 5;
	//SetLocation(vector);

	/*FRotator rotator = GetRotation();
	rotator.Yaw = -90;
	SetRotation(rotator);

	FVector vector = GetScale();
	vector.X *= 0.7;
	vector.Y *= 0.7;
	vector.Z *= 1.0;
	SetScale(vector);*/

	boxCollider->SetBoxExtent(FVector(6.4f, 6.4f, 64.0f));
	boxCollider->SetRelativeLocation(FVector(0, 0, 50));
}