// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "uu.h"
#include "Perception/AISightTargetInterface.h"
#include "robot.generated.h"

UCLASS()
class CLICK_API Arobot : public APawn, public IAISightTargetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	Arobot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY()
	Uuu* sc;

	UPROPERTY()
	Uuu* sc2;


	virtual bool CanBeSeenFrom(const FVector& ObservationLocation, FVector& OutSeenLocation, int32& NumberOfLoSChecksPerformed, float& OutSightStrength, const AActor* IgnoredActor = NULL) const;
};
