#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NavigationSystem.h"
#include "Kismet/KismetMathLibrary.h"
#include "TargetScanner.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter(const wchar_t* meshPath)
	: ACharacterBase(meshPath)
{
	GetCharacterMovement()->bOrientRotationToMovement = true;

	targetScanner = CreateDefaultSubobject<UTargetScanner>(TEXT("TargetScanner"));
	targetScanner->SetOwner(this);

	isTurnning = false;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	//TArray<AActor*> actors;
	UWorld* world = AActor::GetWorld();
	//UGameplayStatics::GetAllActorsOfClass(world, APlayerCharacter::StaticClass(), actors);

	APlayerCharacter* playerCharacter;
	for (TActorIterator<AActor> iter(world); iter; ++iter)
	{
		AActor* actor = *iter;

		playerCharacter = Cast<APlayerCharacter>(actor);

		if (playerCharacter != nullptr)
		{
			SetTarget(playerCharacter);
			targetScanner->SetTarget(playerCharacter);

			return;
		}
	}
}


void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (targetScanner != nullptr)
	{
		if (targetScanner->GetIsTargetInRange())
		{
			SetDestination(target->GetActorLocation());

			FRotator rotator =
				UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), target->GetActorLocation());

			if (rotator.Yaw > 10) isTurnning = true;
			else isTurnning = false;

			smoothRotator = FMath::RInterpTo(smoothRotator, rotator, DeltaTime, turnSpeed);

			smoothRotator.Pitch = 0;
			SetActorRotation(smoothRotator);
		}
	}
}

void AEnemyCharacter::SetTarget(ACharacterBase* target)
{
	this->target = target;
}

ACharacterBase* AEnemyCharacter::GetTarget() const
{
	return target;
}

void AEnemyCharacter::SetDestination(const FVector dest)
{
	//UAIBlueprintHelperLibrary::SimpleMoveToLocation(this->GetController(), dest);
}
