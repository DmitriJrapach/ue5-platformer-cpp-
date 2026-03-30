// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformC.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

// Sets default values
APlatformC::APlatformC()
{
	PrimaryActorTick.bCanEverTick = true;

	// Crear el mesh primero (root provisional)
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	PlatformMesh->SetupAttachment(GetRootComponent());

	// Crear el box como hijo del mesh
	MovementDirection = FVector(0.0f, 0.0f, 1.0f); Speed = 10.0f;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision Mesh"));
	BoxCollision->SetupAttachment(PlatformMesh);
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APlatformC::OnPlatformBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &APlatformC::OnPlatformEndOverlap);
}

// Called when the game starts or when spawned
void APlatformC::BeginPlay()
{
	Super::BeginPlay();

	InitialPosition = GetActorLocation();
	CurrentLocation = InitialPosition;
	LocalSpeed = Speed;
	
	
}

void APlatformC::OnPlatformBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult)
{
	if (OtherActor && OtherComp)
	{
		ACharacter* PlayerCharacter = Cast <ACharacter>(OtherActor);

		if (PlayerCharacter)
		{
			Speed = 0.0f;
		}
	}
} 

void APlatformC::OnPlatformEndOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor && OtherComp)
	{
		ACharacter* PlayerCharacter = Cast <ACharacter>(OtherActor);

		if (PlayerCharacter)
		{
			Speed = LocalSpeed;
		}
	}
}


// Called every frame
void APlatformC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentLocation = CurrentLocation + (MovementDirection * Speed * DeltaTime);
	
	SetActorLocation(CurrentLocation);

	float CurrentDistance = FVector::Dist(InitialPosition, CurrentLocation);

	if (CurrentDistance > MaximumDistance)
	{
		InitialPosition = CurrentLocation;
		MovementDirection  *= -1.0f;
	}
}

