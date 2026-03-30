// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "FPSChar.generated.h"

UCLASS()
class UNREALPROYECTS_API AFPSChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	class UCameraComponent* FPSCameraComp;
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* PlayerMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
