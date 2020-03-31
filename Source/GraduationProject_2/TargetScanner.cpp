// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "TargetScanner.h"

// Sets default values for this component's properties
UTargetScanner::UTargetScanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	canDetect = true;
	isTargetInRange = false;
	detectionDistance = 500.f;
}


// Called when the game starts
void UTargetScanner::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UTargetScanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (canDetect)
	{
		DetectTarget();
	}
}

void UTargetScanner::SetCanDetect(const bool active)
{
	canDetect = active;
}

void UTargetScanner::SetTarget(ACharacterBase* target)
{
	this->target = target;
}

void UTargetScanner::SetOwner(ACharacterBase* owner)
{
	this->owner = owner;
}

bool UTargetScanner::GetIsTargetInRange() const
{
	return isTargetInRange;
}

void UTargetScanner::DetectTarget()
{
	if (target == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("target"))
	}
	if (owner == nullptr) {
		UE_LOG(LogTemp, Log, TEXT("owner"))
	}
	if (detectionDistance <= 0) {
		UE_LOG(LogTemp, Log, TEXT("detectionDistance"))
	}

	if (detectionDistance <= 0 || target == nullptr || owner == nullptr) return;

	FVector const destVec = target->GetActorLocation();
	FVector const startVec = owner->GetActorLocation();

	float const distance = FVector::Distance(destVec, startVec);

	if (distance < detectionDistance)
	{
		isTargetInRange = true;
		canDetect = false;
	}
	else
	{
		isTargetInRange = false;
	}
}

