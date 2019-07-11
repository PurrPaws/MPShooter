// Fill out your copyright notice in the Description page of Project Settings.


#include "TDM_GameMode.h"
#include "TDM_GameState.h"
#include "TDM_PlayerState.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"
#include "HeroPlayerController.h"
#include "HeroCharacter.h"

ATDM_GameMode::ATDM_GameMode()
{
	
}

void ATDM_GameMode::PostActorCreated()
{
	Super::PostActorCreated();

	for (TActorIterator<APlayerStart> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->PlayerStartTag == "Team1") { Team1PlayerStarts.Add(*ActorItr); }
		else if (ActorItr->PlayerStartTag == "Team2") { Team2PlayerStarts.Add(*ActorItr); }
		else { UE_LOG(LogTemp, Error, TEXT("An playerstart has been found without a correct Start tag!!")); }
	}
}

void ATDM_GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ATDM_GameMode::PostLogin(APlayerController* NewPlayerRaw)
{
	Super::PostLogin(NewPlayerRaw);

	AHeroPlayerController* NewPlayer = Cast<AHeroPlayerController>(NewPlayerRaw);

	ATDM_GameState* TDMGameState = GetGameState<ATDM_GameState>();
	ATDM_PlayerState* NewPlayer_PlayerState = NewPlayer->GetPlayerState<ATDM_PlayerState>();

	int Team = TDMGameState->GetSmallestTeam(); //TODO: balance function!

	TDMGameState->ServerRPCAddToTeam(NewPlayer, Team);

	int IndexOfPlayer = TDMGameState->GetIndexOfPlayer(NewPlayer, Team);

	APlayerStart* Spawnpoint = Team == 1 ? 
		Team1PlayerStarts[IndexOfPlayer] :
		Team2PlayerStarts[IndexOfPlayer];
	
	AHeroCharacter* SpawnedActor = GetWorld()->SpawnActor<AHeroCharacter>(PawnToSpawn, Spawnpoint->GetActorTransform());
	NewPlayer->Possess(SpawnedActor);	
	NewPlayer->CreateHUD();
}

void ATDM_GameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}
