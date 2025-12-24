// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "PlantConfiguration.generated.h"
#include "Growth.h"

USTRUCT(BlueprintType)
struct MYPROJECT2_API FGrowthData
{
	GENERATED_BODY();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeToGrow;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTransform NewRelativeTransform;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> NewGrowthMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AGrowth AddedGrowth;
};

USTRUCT(BlueprintType)
struct MYPROJECT2_API FPlantConfiguration
{
	GENERATED_BODY();


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FGrowthData> GrowthData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ItemizeUponGrowth;

	
};
