// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantController.h"
#include "EngineUtils.h"
#include "Plant.h"

// Sets default values
APlantController::APlantController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

void APlantController::IteratePlants()
{

	if (ToObjectPtr<UWorld> World = GetWorld())
	{
		TArray<APlant> IteratedPlants;


		for (TObjectIterator<APlant> CurrentPlant; CurrentPlant; ++CurrentPlant)
		{
			if (CurrentPlant->IsA(APlant::StaticClass()))
			{

				ToObjectPtr<APlant> DerivedPlant = *CurrentPlant;

				ToObjectPtr<APlant> CastedPlant = Cast<APlant>(DerivedPlant);

				IteratedPlants.Add(CastedPlant);
			}
			else
			{
				continue;
			}
		}
	}


}
