// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TDM_GameState.generated.h"

/**
 * 
 */
UCLASS()
class MPSHOOTER_API ATDM_GameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated, VisibleAnywhere, Category = Team)
		TArray<class AHeroPlayerController*> Team1Players = TArray<class AHeroPlayerController*>();
	UPROPERTY(Replicated, VisibleAnywhere, Category = Team)
		TArray<class AHeroPlayerController*> Team2Players = TArray<class AHeroPlayerController*>();
	UPROPERTY(Replicated, VisibleAnywhere, Category = Team)
		int ScoreTeam1 = 0;
	UPROPERTY(Replicated, VisibleAnywhere, Category = Team)
		int ScoreTeam2 = 0;

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerRPCAddToTeam(class AHeroPlayerController* Player, int Team);

	int GetIndexOfPlayer(AHeroPlayerController* Player, const int Team);
	int GetSmallestTeam();
};
