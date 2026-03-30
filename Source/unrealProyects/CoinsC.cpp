// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinsC.h"

#include "Kismet/GameplayStatics.h"

#include "CoinGM.h"
#include "PhysicsEngine/PhysicsAsset.h"

// Sets default values
ACoinsC::ACoinsC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coins Mesh Component"));
	RootComponent = CoinMesh;
	//CoinMesh->SetupAttachment(GetRootComponent());
	
	//CoinMesh->SetWorldScale3D(FVector(0.6f, 0.6f, 0.1f));
	//CoinMesh->AddWorldRotation(FRotator(90.f, 0.0f, 0.0f));
	CoinMesh->OnComponentBeginOverlap.AddDynamic(this, &ACoinsC::CoinMeshBeginOverlap);

}

// Called when the game starts or when spawned
void ACoinsC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinsC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoinsC::CoinMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,	const FHitResult & SweepResult)
{
	UWorld* World = GetWorld();
	if (World)
	{
		AGameModeBase* GameModRef = UGameplayStatics::GetGameMode(World);
		if (GameModRef)
		{
			ACoinGM* CastedGameMod = Cast<ACoinGM>(GameModRef);
			if (CastedGameMod)
			{
				CastedGameMod->CoinsCounterC();				
			}
		}
	}


		
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Han pasado por encima"));
	}
	Destroy();
}