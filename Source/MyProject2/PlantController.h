// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantController.generated.h"

UCLASS()
class MYPROJECT2_API APlantController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantController();

	UPROPERTY(Category="Data", BlueprintReadOnly)
	float CurrentTime;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void IteratePlants();
		 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
