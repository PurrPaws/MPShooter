// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HeroPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MPSHOOTER_API AHeroPlayerController : public APlayerController
{
	GENERATED_BODY()
		
	float Sensitivity = 1.f;

protected:
	AHeroPlayerController();
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadOnly)
		class AHeroCharacter* ControlledCharacter;

	class APlayerStart* SpawnPoint = nullptr;

	UFUNCTION(BlueprintCallable, Category=Requests)
		void RequestMoveRight(float Rate);
	UFUNCTION(BlueprintCallable, Category = Requests)
		void RequestMoveForward(float Rate);
	UFUNCTION(BlueprintCallable, Category = Requests)
		void RequestJump();
	UFUNCTION(BlueprintCallable, Category = Requests)
		void RequestLookRight(float Rate);
	UFUNCTION(BlueprintCallable, Category = Requests)
		void RequestLookUp(float Rate);
	UFUNCTION(BlueprintCallable, Category = Requests)
		void RequestPrimaryFire();
	UFUNCTION(BlueprintCallable, Category = Requests)
		void RequestSecondaryFire();
	UFUNCTION(BlueprintCallable, Category = Requests)
		void RequestTakeDamage(float Amount);

	UFUNCTION(BlueprintImplementableEvent, Category = HUD)
		void CreateHUD();
	UFUNCTION(BlueprintImplementableEvent, Category = HUD)
		void DestroyHUD();

};
