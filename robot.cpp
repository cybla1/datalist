// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "robot.h"

// Sets default values
Arobot::Arobot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* de = CreateDefaultSubobject<USceneComponent>(TEXT("default"));
	RootComponent = de;
	

	sc = CreateDefaultSubobject<Uuu>(TEXT("temp1"));
	sc->SetupAttachment(RootComponent);
	sc->SetRelativeLocation(FVector(0.0f, -100.0f, 0.0f));

	sc2 = CreateDefaultSubobject<Uuu>(TEXT("temp12"));
	sc2->SetupAttachment(RootComponent);
	sc2->SetRelativeLocation(FVector(0.0f, 100.0f, 00.0f));
}

// Called when the game starts or when spawned
void Arobot::BeginPlay()
{
	Super::BeginPlay();
	TArray<UActorComponent*> ActorComponents;
	GetComponents(ActorComponents);

	//UE_LOG(LogTemp, Warning, TEXT("size : %d"), ActorComponents.Num());

	for (int i = 0; i < ActorComponents.Num(); i++) {

		UE_LOG(LogTemp, Warning, TEXT("size : %s"), *ActorComponents[i]->GetName());
	}

	FVector root = RootComponent->GetComponentLocation();
	FVector pos = sc->GetComponentLocation();
	FVector pos2 = sc2->GetComponentLocation();

	DrawDebugPoint(GetWorld(), root, 10, FColor(255, 0, 0), true);
	DrawDebugPoint(GetWorld(), pos, 10, FColor(0, 255, 0), true);
	DrawDebugPoint(GetWorld(), pos2, 10, FColor(0, 0, 255), true);

}

// Called every frame
void Arobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector root = RootComponent->GetComponentLocation();
	FVector pos = sc->GetComponentLocation();
	FVector pos2 = sc2->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("root : %f %f %f"), root[0], root[1], root[2]);
	UE_LOG(LogTemp, Warning, TEXT("se : %f %f %f"), pos[0],pos[1],pos[2]);

	UE_LOG(LogTemp, Warning, TEXT("se2 : %f %f %f"), pos2[0],pos2[1],pos2[2]);


}

// Called to bind functionality to input
void Arobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool Arobot::CanBeSeenFrom(const FVector& ObservationLocation, FVector& OutSeenLocation, int32& NumberOfLoSChecksPerformed, float& OutSightStrength, const AActor* IgnoredActor) const
{
	static const FName Name_sight = FName(TEXT("TestPawn"));
	FHitResult HitResult;
	FVector SightTargetLocation = RootComponent->GetComponentLocation();

	bool hit = GetWorld()->LineTraceSingleByChannel(HitResult, ObservationLocation, SightTargetLocation, ECC_Visibility, FCollisionQueryParams(Name_sight, false, IgnoredActor));


	if (!hit || (HitResult.Actor.IsValid() && HitResult.Actor->IsOwnedBy(this)))
	{
		OutSeenLocation = SightTargetLocation;
		OutSightStrength = 1;
		return true;
	}


	OutSightStrength = 0;
	return false;
}

