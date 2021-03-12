// Fill out your copyright notice in the Description page of Project Settings.

#include "PG_Room.h"

// Sets default values
APG_Room::APG_Room()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
}

// Called when the game starts or when spawned
void APG_Room::BeginPlay()
{
	Super::BeginPlay();
	SpawnObject(ObjectClass);
	SpawnObject(ObjectClass);
	SpawnObject(ObjectClass);
	SpawnObject(ObjectClass);
}

// Called every frame
void APG_Room::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APG_Room::SpawnObject(UClass* ObjectToSpawn)
{
	float XCoordinate = FMath::FRandRange(-500.f, 500.f);
	float YCoordinate = FMath::FRandRange(-500.f, 500.f);
	float Yaw = FMath::FRandRange(0.f, 360.f);
	FVector location(XCoordinate, YCoordinate, 0.0f);
	FRotator rotation(0.0f, Yaw, 0.0f);
	GetWorld()->SpawnActor<AActor>(ObjectToSpawn, location, rotation);
}