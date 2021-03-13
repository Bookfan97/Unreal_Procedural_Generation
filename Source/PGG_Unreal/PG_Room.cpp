// Fill out your copyright notice in the Description page of Project Settings.

#include "PG_Room.h"

#include "DrawDebugHelpers.h"

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
	
	/*SpawnObject(ObjectClass);
	SpawnObject(ObjectClass);
	SpawnObject(ObjectClass);
	SpawnObject(ObjectClass);*/
	objectRadius = 24.f;
	gridSizeX = 5;
	gridSizeY=5;
	squareWidth=200;
	topLeft= FVector(0.f);
	bottomRight = FVector(1000.f,1000.f,0.f);
	gridHeight=1.f;
	roomLength=1000.f;
	roomWidth = 1000.f;
	CreateGrid();
	PlacePointsOnGrid();
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

void APG_Room::CreateGrid()
{
	for (int32 i = 0; i < gridSizeX; ++i)
	{
		FVector start = topLeft + FVector(i*squareWidth, 0.f, gridHeight);
		FVector end = start + FVector(0.f, roomLength, gridHeight);
		DrawDebugLine(GetWorld(), start, end, FColor::Blue, true);
	}
	for (int32 i = 0; i < gridSizeX; ++i)
	{
		FVector start = topLeft + FVector(0.f, i*squareWidth, gridHeight);
		FVector end = start + FVector(roomWidth, 0.f, gridHeight);
		DrawDebugLine(GetWorld(), start, end, FColor::Blue, true);
	}
}

void APG_Room::PlacePointsOnGrid()
{
	for (int32 x = 0; x < gridSizeX; ++x)
	{
		for (int y = 0; y < gridSizeY; ++y)
		{
			FVector upperLeft(x *squareWidth + objectRadius, y * squareWidth + objectRadius, gridHeight);
			FVector lowerRight(x * squareWidth + squareWidth - objectRadius, y * squareWidth + squareWidth - objectRadius, gridHeight);
			FVector randPoint = GetRandomPointInSquare(upperLeft, lowerRight);
			//DrawDebugPoint(GetWorld(), randPoint, 5.f, FColor::Red, true);
			//DrawDebugSphere(GetWorld(), randPoint, 5.f, 48, FColor::Red);
			float RandYaw = FMath::FRandRange(0.f, 360.f);
			GetWorld()->SpawnActor<AActor>(ObjectClass, randPoint, FRotator(0.f, RandYaw, 0.f));
		}
	}
}

FVector APG_Room::GetRandomPointInSquare(const FVector& upperLeft, const FVector& lowerRight)
{
	float randomX = FMath::FRandRange(upperLeft.X, lowerRight.X);
	float randomY = FMath::FRandRange(upperLeft.Y, lowerRight.Y);
	return FVector(randomX, randomY, 5.f);
}
