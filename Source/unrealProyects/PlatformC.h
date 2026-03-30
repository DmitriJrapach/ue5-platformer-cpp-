// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class UBoxComponent;
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformC.generated.h"

UCLASS()
class UNREALPROYECTS_API APlatformC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformC();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	UBoxComponent* BoxCollision;

	UPROPERTY()
	FVector InitialPosition;

	UPROPERTY()
	FVector CurrentLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Movement")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Movement")
	FVector MovementDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Movement")
	float MaximumDistance = 400;

	UPROPERTY()
	float LocalSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnPlatformBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnPlatformEndOverlap (
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
	
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
