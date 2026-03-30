// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinGM.h"

#include "Kismet/GameplayStatics.h"

#include "Components/AudioComponent.h"

#include "CoinsC.h"

ACoinGM::ACoinGM()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MusicAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
}
void ACoinGM::BeginPlay()
{
	Super::BeginPlay();

	GetAllCoinsInWorld(ACoinsC::StaticClass());
	
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACoinGM::CountDownTick, 1.0f, true
		);

	if (MusicSound)
	{
		MusicAudioComponent->SetSound(MusicSound);
		MusicAudioComponent->Play();
	}
}

// Called every frame
void ACoinGM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ACoinGM::CoinsCounterC()
{
	CoinsGatheredC++;
	
	if (World)
	{
		AGameModeBase* GameMod = UGameplayStatics::GetGameMode(World);
		if (GameMod)
		{
			UFunction* BPFunctionName = GameMod->FindFunction(FName("CoinsGatheredUpdate"));
			if (BPFunctionName)
			{
				GameMod->ProcessEvent(BPFunctionName, nullptr);
			}
		}
	}
	WinningConditionCheck();
}
void ACoinGM::WinningConditionCheck()
{
	if (CoinsGatheredC == CoinsFound)
	{
		if (World)
		{
			AGameModeBase* GameMod = UGameplayStatics::GetGameMode(World);
			
			FadeOutSound(FadeOutTime);
			
			if (GameMod)
			{
				UFunction* BPFunctionName = GameMod->FindFunction(FName("WinningShowMessage"));
				if (BPFunctionName)
				{
					GameMod->ProcessEvent(BPFunctionName, nullptr);


					APlayerController* PlayerController = World->GetFirstPlayerController();
					if (PlayerController)
					{
						APawn* PlayerPawn = PlayerController ->GetPawn();
						if (PlayerPawn)
						{
							DisablePlayerInput(PlayerPawn);	
						}						
					}					
				}
			}
		}
	}
}
void ACoinGM::CountDownTick()
{
	if (TimeRemaining != 0)
	{
		TimeRemaining --;
	}
	if (TimeRemaining == 0)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		
		if (GEngine)
		GEngine->AddOnScreenDebugMessage(3, 11.3f, FColor::Red, TEXT("El timer esta en 0"));
		
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(4, 0.3f, FColor::Purple, TEXT("El timer se esta ejecutando"));

	}
	CallTimerUpdate();
}
void ACoinGM::CallTimerUpdate()
{
	if (World != nullptr)
	{
		//Obtenemos el modo de juego actual.
		AGameModeBase* GameMod = UGameplayStatics::GetGameMode(World);
		if (GameMod != nullptr)
		{
			//Encontramos el nombre de la funcion a la que queremos llamar y la guardamos en la variable BPFunctionName.
			UFunction* BPFunctionName =	GameMod->FindFunction(FName("TimerUpdate"));
			
			if (BPFunctionName)
			{
				//Procesamos el evento BPFunctionName es decir ProcessEvent activa o ejecuta esta funcion.	
				GameMod->ProcessEvent(BPFunctionName, nullptr);
			
			}
			
		}
		
	}
	//GEngine->AddOnScreenDebugMessage(6, 0.5f, FColor::White, TEXT("FUNCTION CALL"));
}
void ACoinGM::FadeOutSound(float FadeOutValue)
{
	if (MusicAudioComponent)
	{
		MusicAudioComponent->FadeOut(FadeOutValue, 0.0f);
	}

	
}
void ACoinGM::GetAllCoinsInWorld(TSubclassOf<AActor> ActorClass)
{
	TArray<AActor*> FoundCoins;

	World = GetWorld();
	if (World)
	{
		UGameplayStatics::GetAllActorsOfClass(World, ActorClass, FoundCoins);
		CoinsFound = FoundCoins.Num();
		
	}
}
void ACoinGM::DisablePlayerInput(APawn* Player)
{
	if (Player)
	{
		APlayerController* PlayerController = Cast<APlayerController>(Player->GetController());
		if (PlayerController)
		{
			Player->DisableInput(PlayerController);
		}
	}
}