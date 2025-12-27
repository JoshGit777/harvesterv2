// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantController.h"
#include "Misc/DateTime.h"
#include "Plant.h"

// Sets default values
APlantController::APlantController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentTime = 0;
}

void APlantController::AddPlantToRegistery(APlant PlantToAdd)
{

}

void APlantController::RemovePlantFromRegistery(APlant PlantToRemove)
{

}

// Called when the game starts or when spawned
void APlantController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlantController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FDateTime Now = FDateTime();

	CurrentTime = Now.ToUnixTimestamp();

}


