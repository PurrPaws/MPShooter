// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TDM_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class MPSHOOTER_API ATDM_GameMode : public AGameMode
{
	GENERATED_BODY()

	ATDM_GameMode();
	virtual void BeginPlay() override;
	
	TArray<class APlayerStart*> Team1PlayerStarts = TArray<class APlayerStart*>();
	TArray<class APlayerStart*> Team2PlayerStarts = TArray<class APlayerStart*>();

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;
	virtual void PostActorCreated() override;


public:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AHeroCharacter> PawnToSpawn;
};
