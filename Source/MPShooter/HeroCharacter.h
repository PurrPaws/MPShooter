// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HeroCharacter.generated.h"

UCLASS()
class MPSHOOTER_API AHeroCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	AHeroCharacter();

	// Pawn Mesh (First person view) Hands.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_CharacterMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun;

	UPROPERTY(VisibleDefaultsOnly, Category = Camera)
		class UCameraComponent* FP_Camera;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Rate);
	void MoveRight(float Rate);
	void LookUp(float Amount);
	void LookRight(float Amount);
	//TODO: Add projectile class to spawn.
};
