// Fill out your copyright notice in the Description page of Project Settings.


#include "DeadChekerC.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
ADeadChekerC::ADeadChekerC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = BoxCollision;
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ADeadChekerC::DeadTriggerOverlap);

}

// Called when the game starts or when spawned
void ADeadChekerC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeadChekerC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADeadChekerC::DeadTriggerOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AActor* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (OtherActor && OtherActor == PlayerCharacter)
	{
		if (GEngine)
		{
			PlayerCharacter->SetActorLocation(TargetActor->GetActorLocation());
		}
	}
	

}
