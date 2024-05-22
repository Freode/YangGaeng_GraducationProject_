// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractSequence.h"

// Sets default values
AInteractSequence::AInteractSequence()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractSequence::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractSequence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractSequence::NextInteractEvent()
{

}