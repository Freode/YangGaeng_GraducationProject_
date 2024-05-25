// Fill out your copyright notice in the Description page of Project Settings.


#include "FireAlarm.h"

AFireAlarm::AFireAlarm()
{
	SM_FireAlarm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMFIREALARM"));
	AlarmAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("ALARMAUDIO"));
}

void AFireAlarm::BeginPlay()
{
	Super::BeginPlay();

	AlarmAudio->Stop();
}

void AFireAlarm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
