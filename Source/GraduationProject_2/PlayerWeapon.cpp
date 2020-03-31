// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWeapon.h"


UPlayerWeapon::UPlayerWeapon()
	: UMeleeWeapon
		(TEXT("SkeletalMesh'/Game/Art/InfinityBladeWeapons/Weapons/Blade/Axes/Blade_Hatchet/SK_Blade_Hatchet'"),
			WEAPON_DAMAGE, WEAPON_ATTACKSPEED)
{
	//FVector vector = GetLocation();
	//vector.Z -= 5;
	//SetLocation(vector);

	FRotator rotator = GetRotation();
	rotator.Yaw = -90;
	SetRotation(rotator);

	FVector vector = GetScale();
	vector.X *= 0.7;
	vector.Y *= 0.7;
	vector.Z *= 1.0;
	SetScale(vector);

	boxCollider->SetBoxExtent(FVector(6.4f, 6.4f, 64.0f));
	boxCollider->SetRelativeLocation(FVector(0, 0, 50));
}