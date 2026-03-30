// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cubeTest.generated.h"

UCLASS()
class UNREALPROYECTS_API AcubeTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcubeTest();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Cube Properties", meta = (DisplayName = "Cubes Max Health"))
	int32 Health { 100 };
	float Height = 1.8 ;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category= "Cube Properties", meta = (DisplayName = "Cubes Damage Taken"));
	int32 DamageTaken = 25;

	UPROPERTY(BlueprintReadWrite, Category= "Cube Properties", meta = (DisplayName = "Cubes Alive or Dead"))
	bool bPlayerState = false;

	UFUNCTION(BlueprintCallable)
	bool playerDead(bool bInput, int32 HealthInput, int32& HealthOut);

	bool playerDead(bool bInput, int32& HealthInput);

	
	UFUNCTION(BlueprintCallable)
	int32 CalculateDamage(int32& HealthValue, int32 DamageValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
