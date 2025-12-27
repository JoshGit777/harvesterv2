// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "PlantConfiguration.h"
#include "UPlantInterface.h"
#include "Plant.generated.h"

class UStaticMeshComponent;

UCLASS()
class MYPROJECT2_API APlant : public AActor, public IUPlantInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlant();

	UPROPERTY(Category = Components, EditAnywhere, meta = (AllowPrivateAccess = "true"));
	TObjectPtr<UStaticMeshComponent> PlantMesh;
	
	UPROPERTY(Category="GrowthData", VisibleAnywhere, BlueprintReadOnly)
	float PlantTime;

	UPROPERTY(Category = "GrowthData", VisibleAnywhere, BlueprintReadOnly)
	int GrowthLevel;
	
	UPROPERTY(Category="GrowthData", VisibleAnywhere, BlueprintReadOnly)
	int PlantAge;

	UPROPERTY(Category="Configuration", EditAnywhere, BlueprintReadWrite)
	FPlantConfiguration Configuration;

	UPROPERTY(Category="Configuration", EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> SceneRoot;

	UFUNCTION(BlueprintImplementableEvent, Category = "GrowthEvents")
	void OnGrowth(int CurrentGrowthLevel);

	UFUNCTION(Category = "PlantControl")
	bool NextGrowth();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
