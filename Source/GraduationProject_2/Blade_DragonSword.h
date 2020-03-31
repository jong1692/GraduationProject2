// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeWeapon.h"
#include "Blade_DragonSword.generated.h"

#define WEAPON_DAMAGE 10
#define WEAPON_ATTACKSPEED 1.0f

UCLASS()
class GRADUATIONPROJECT_2_API UBlade_DragonSword : public UMeleeWeapon
{
	GENERATED_BODY()

public:
	UBlade_DragonSword();

};
