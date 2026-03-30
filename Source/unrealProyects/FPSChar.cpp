// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSChar.h"

// Sets default values
AFPSChar::AFPSChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FPSCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	FPSCameraComp -> SetupAttachment(GetRootComponent());
	PlayerMesh = ACharacter::GetMesh();
	PlayerMesh -> SetupAttachment(FPSCameraComp);
}

// Called when the game starts or when spawned
void AFPSChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

