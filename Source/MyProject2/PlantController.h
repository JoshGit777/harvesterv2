// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UPlantInterface.h"
#include "Plant.h"
#include "PlantController.generated.h"

UCLASS()
class MYPROJECT2_API APlantController : public AActor, public IUPlantInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantController();

	UPROPERTY(Category="Data", BlueprintReadOnly)
	float CurrentTime;

	UPROPERTY(Category="Data", BlueprintReadOnly)
	FTimerHandle UpdateTimer;

	UPROPERTY(Category="Data", BlueprintReadOnly)
	TArray<APlant*> PlantRegistery;

	virtual void AddPlantToRegistery(APlant PlantToAdd);

	virtual void RemovePlantFromRegistery(APlant PlantToRemove);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
		 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
