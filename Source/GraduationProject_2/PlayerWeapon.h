// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeWeapon.h"
#include "PlayerWeapon.generated.h"

#define WEAPON_DAMAGE 10
#define WEAPON_ATTACKSPEED 1.0f

UCLASS()
class GRADUATIONPROJECT_2_API UPlayerWeapon : public UMeleeWeapon
{
	GENERATED_BODY()
	
public:
	UPlayerWeapon();

};
