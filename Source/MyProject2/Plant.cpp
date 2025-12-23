// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "GameFramework/Actor.h"
#include "Misc/datetimeapi.h"

class AActor;
// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GrowthLevel = 0;
	
	FDateTime Now = FDateTime::UtcNow();

	int64 UnixTimeSeconds = Now.ToUnixTimestamp();

	PlantTime = UnixTimeSeconds;
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{	
	Super::BeginPlay();
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


