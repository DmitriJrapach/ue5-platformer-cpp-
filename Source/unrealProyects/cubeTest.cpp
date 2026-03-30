// Fill out your copyright notice in the Description page of Project Settings.


#include "cubeTest.h"

// Sets default values
AcubeTest::AcubeTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcubeTest::BeginPlay()
{
	Super::BeginPlay();
	//Health = Health - DamageTaken;
	CalculateDamage(Health, DamageTaken);
	playerDead(bPlayerState, Health);
	//playerDead(bPlayerState);
	//UE_LOG(LogTemp, Warning, TEXT("The current health of cube is %d"), Health);
	//UE_LOG(LogTemp, Warning, TEXT("EL cubo esta %s"), ( bPlayerState ? TEXT("MUERTO"): TEXT("VIVO") ))

}

// Called every frame
void AcubeTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

bool AcubeTest::playerDead(bool bInput, int32 HealthInput, int32& HealthOut)
{
	
	if (Health <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("The player is dead"));
		bInput = true;
	}
	else if (Health <= 15)
	{
		UE_LOG(LogTemp, Warning, TEXT("The player is wound"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The player is alive"));
		bInput = false;
	}
	//UE_LOG(LogTemp, Warning, TEXT("The boolean value is %s"), ( value ? TEXT("true"): TEXT("false") ));
	HealthOut = HealthInput;
	return bInput;
}

bool AcubeTest::playerDead(bool bInput, int32& HealthInput)
{
	if (Health <= 0)
	{
		HealthInput = -1000;
		UE_LOG(LogTemp, Warning, TEXT("The player super muerto  %d"), Health);
		bInput = true;
	}
	else if (Health <= 15)
	{
		UE_LOG(LogTemp, Warning, TEXT("The player is wound"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The player is alive"));
		bInput = false;
	}
	//UE_LOG(LogTemp, Warning, TEXT("The boolean value is %s"), ( value ? TEXT("true"): TEXT("false") ));
	
	return bInput;
}
int32 AcubeTest::CalculateDamage(int32& HealthValue, int32 DamageValue)
{
	HealthValue -= DamageValue;
	return HealthValue;
}