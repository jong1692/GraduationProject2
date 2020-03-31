// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "CharacterBase.h"
#include "EnemyCharacter.generated.h"

/**
 *
 */
UCLASS()
class GRADUATIONPROJECT_2_API AEnemyCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	AEnemyCharacter(const wchar_t* meshPath);
	AEnemyCharacter() {}

	virtual void Tick(float DeltaTime) override;

	void SetTarget(ACharacterBase* target);
	ACharacterBase* GetTarget() const;

protected:
	virtual void BeginPlay() override;

	void SetDestination(const FVector dest);
	
protected:
	class ACharacterBase* target;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = TargetScanner)
		class UTargetScanner* targetScanner;
private:
	FRotator smoothRotator;
	const float turnSpeed = 5.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character)
	bool isTurnning;
};
