// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HW05Actor.generated.h"

UCLASS()
class HW05_API AHW05Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHW05Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector Position;
	int32 Count;

	FVector Step();
	void Move();
	float GetDistance(const FVector& from, const FVector& to) const;
	FVector CreateEvent();
};
