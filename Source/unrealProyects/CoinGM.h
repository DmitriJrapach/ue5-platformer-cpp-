	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CoinGM.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROYECTS_API ACoinGM : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	ACoinGM();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FTimerHandle CountdownTimerHandle;
	void CountDownTick();
	
	UFUNCTION(BlueprintCallable)
	void CallTimerUpdate();
	
	UWorld* World ;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;		
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TimeRemaining = 10 ;

	int32 DisplayKey = -1;
	float DisplayTime = 5.0f;
	FColor DisplayColor = FColor::Green;
	FString DisplayMessage = FString::Printf(TEXT("The memory value of this object is: %d"), sizeof(ACoinGM));


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsGatheredC ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsNeededToWinC = 3 ;

	UFUNCTION(BlueprintCallable)
	void CoinsCounterC();

	UFUNCTION()
	void WinningConditionCheck();
	
	UFUNCTION(BlueprintCallable)
	void FadeOutSound(float FadeOutValue);

	UPROPERTY(EditAnywhere, Category="Sound")
	float FadeOutTime = 0.3f;

	UPROPERTY(BlueprintReadOnly)
	int32 CoinsFound;

	UFUNCTION()
	void GetAllCoinsInWorld(TSubclassOf<AActor> ActorClass);

	UFUNCTION()
	void DisablePlayerInput(APawn* Player);
	
protected:	

	UPROPERTY(EditAnywhere, Category="Sound")
	USoundBase* MusicSound;

	UPROPERTY()
	UAudioComponent* MusicAudioComponent;
	
};
