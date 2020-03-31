// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterBase.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetScanner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRADUATIONPROJECT_2_API UTargetScanner : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTargetScanner();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, 
		FActorComponentTickFunction* ThisTickFunction) override;

	void SetCanDetect(const bool active);
	
	void SetTarget(ACharacterBase* target);

	void SetOwner(ACharacterBase* owner);

	bool GetIsTargetInRange() const;

protected:
	virtual void BeginPlay() override;
	
private:
	void DetectTarget();

private:
	class  ACharacterBase* target;
	class ACharacterBase* owner;

	bool canDetect;
	bool isTargetInRange;
	float detectionDistance;
};
