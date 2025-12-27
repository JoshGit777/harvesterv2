// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "PlantController.h"
#include "Misc/DateTime.h"

class AActor;
// Sets default values
APlant::APlant()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PlantTime = 0;
	GrowthLevel = 0;
	PlantAge = 0;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	PlantMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantMesh"));
	PlantMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	GrowthLevel = 0;

	FDateTime Now = FDateTime::UtcNow();

	int UnixTimestamp = Now.ToUnixTimestamp();

	PlantTime = UnixTimestamp;

	APlantController* CurrentPlantController =
		Cast<APlantController>(
			UGameplayStatics::GetActorOfClass(GetWorld(), APlantController::StaticClass())
		);

	ToObjectPtr<APlant> CurrentPlant = this;

	CurrentPlantController->AddPlantToRegistery(CurrentPlant);
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool APlant::NextGrowth()
{
	UE_LOG(
		LogTemp,
		Warning,
		TEXT("Next Growth Triggered")
	)

		GrowthLevel++;

	FTransform NextTransform = Configuration.GrowthData[GrowthLevel].NewRelativeTransform;

	OnGrowth(GrowthLevel);

	return true;
}

APlant::~APlant()
{
	APlantController* CurrentPlantController =
		Cast<APlantController>(
			UGameplayStatics::GetActorOfClass(GetWorld(), APlantController::StaticClass())
		);
}