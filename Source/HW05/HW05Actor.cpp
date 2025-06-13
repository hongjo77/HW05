// Fill out your copyright notice in the Description page of Project Settings.


#include "HW05Actor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AHW05Actor::AHW05Actor()
	: Position(0, 0, 0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHW05Actor::BeginPlay()
{
	Super::BeginPlay();
	Move();
}

FVector AHW05Actor::Step()
{
	return FVector(
		FMath::RandRange(0, 1),
		FMath::RandRange(0, 1),
		0
	);
}

float AHW05Actor::GetDistance(const FVector& From, const FVector& To) const
{
	return FVector::Dist2D(From, To);
}

FVector AHW05Actor::CreateEvent()
{
	UE_LOG(LogTemp, Warning, TEXT("(Event 50%% Probability) All Move + 1"));
	return FVector(1, 1, 0);
}

void AHW05Actor::Move()
{
	Count = 0;
	UE_LOG(LogTemp, Warning, TEXT("Start Location: (%.0f, %.0f)"), Position.X, Position.Y);

	for (int32 i = 0; i < 10; i++)
	{
		FVector Next = Step();
		UE_LOG(LogTemp, Warning, TEXT("Step(%d) : (%.0f, %.0f)"), i + 1, Next.X, Next.Y);

		if (FMath::RandRange(0, 1) == 0)
		{
			Next += CreateEvent();
			Count++;
		}
		float Distance = GetDistance(Position, Next + Position);
		Position += Next;

		UE_LOG(LogTemp, Warning, TEXT("Current Position : (%.0f, %.0f)"), Position.X, Position.Y);
		UE_LOG(LogTemp, Warning, TEXT("Distance : %.2f"), Distance);
		UE_LOG(LogTemp, Warning, TEXT(" "));
	}

	UE_LOG(LogTemp, Warning, TEXT("Total Event Count : %d"), Count);
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %.2f"), GetDistance(FVector(0, 0, 0), Position));
}

