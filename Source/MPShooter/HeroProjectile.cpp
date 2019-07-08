// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AHeroProjectile::AHeroProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("BulletMesh"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComponent"));
	ProjectileMovement->InitialSpeed = 12000.f;
	ProjectileMovement->bAutoActivate = true;
}

// Called when the game starts or when spawned
void AHeroProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeroProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

