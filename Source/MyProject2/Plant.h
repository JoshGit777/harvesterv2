// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Plant.generated.h"


class UStaticMeshComponent;

UCLASS()
class MYPROJECT2_API APlant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlant();

	UPROPERTY(Category = Plant, VisibleAnywhere, meta = (AllowPrivateAccess = "true"));
	TObjectPtr<UStaticMeshComponent> PlantMesh;
	
	UPROPERTY(Category="GrowthData", VisibleAnywhere, BlueprintReadOnly)
	float PlantTime;

	UPROPERTY(Category = "GrowthData", VisibleAnywhere, BlueprintReadOnly)
	int GrowthLevel;

	UFUNCTION(BlueprintImplementableEvent, Category = "GrowthEvents")
	void OnGrowth(int CurrentGrowthLevel);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
