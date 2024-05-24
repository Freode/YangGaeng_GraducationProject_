// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerLevelCharacter.h"

// Sets default values
APlayerLevelCharacter::APlayerLevelCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerLevelCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerLevelCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerLevelCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerLevelCharacter::ApplyDamage(AActor* InteractObject)
{

}

