// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TDM_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MPSHOOTER_API ATDM_PlayerState : public APlayerState
{
	GENERATED_BODY()

	int Team;
	int Kills = 0;
	float DamageDone = 0.f;
	int Deaths = 0;

public:
	//Setters
	void SetTeam(int TeamToSet) { Team = TeamToSet; }
};
