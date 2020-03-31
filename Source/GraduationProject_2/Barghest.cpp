// Fill out your copyright notice in the Description page of Project Settings.


#include "Barghest.h"

ABarghest::ABarghest()
	: AEnemyCharacter(TEXT("SkeletalMesh'/Game/Art/QuadrapedCreatures/Barghest/Meshes/SK_Barghest'"))
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(40.0f);
	GetCapsuleComponent()->SetCapsuleRadius(40.0f);
}