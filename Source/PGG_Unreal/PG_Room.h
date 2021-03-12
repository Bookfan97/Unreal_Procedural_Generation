// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PG_Room.generated.h"

UCLASS()
class PGG_UNREAL_API APG_Room : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APG_Room();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Floor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> ObjectClass;
	void SpawnObject(UClass* ObjectToSpawn);
};
