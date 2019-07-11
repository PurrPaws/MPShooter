// Fill out your copyright notice in the Description page of Project Settings.


#include "TDM_GameState.h"
#include "TDM_PlayerState.h"
#include "HeroPlayerController.h"
#include "UnrealNetwork.h"

bool ATDM_GameState::ServerRPCAddToTeam_Validate(AHeroPlayerController* Player, int Team) { return true; }

void ATDM_GameState::ServerRPCAddToTeam_Implementation(AHeroPlayerController* Player, int Team)
{
	if (Team != 1 && Team != 2) { return; }

	Player->GetPlayerState<ATDM_PlayerState>()->SetTeam(Team);

	switch (Team)
	{
	case 1:
		Team1Players.Add(Player);
		break;
	case 2: 
		Team2Players.Add(Player);
		break;
	default:
		return;
	}
}

int ATDM_GameState::GetIndexOfPlayer(AHeroPlayerController* Player, const int Team)
{
	if (Team != 1 && Team != 2) { UE_LOG(LogTemp, Warning, TEXT("TEAM error in 'GetIndexOfPlayer'")); return -1; } //TODO: Add proper protection -1 in array will cause crash!

	switch (Team)
	{
	case 1:
		return Team1Players.Find(Player);
	case 2:
		return Team2Players.Find(Player);
	default:
		UE_LOG(LogTemp, Error, TEXT("Error in 'ATDM_GameState::GetIndexOfPlayer' Default Case called!"));
		return -1;
	}
}

int ATDM_GameState::GetSmallestTeam()
{
	if (Team1Players.Num() <= Team2Players.Num()) { return 1; }
	else { return 2; }
}

void ATDM_GameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATDM_GameState, Team1Players);
	DOREPLIFETIME(ATDM_GameState, Team2Players);
}