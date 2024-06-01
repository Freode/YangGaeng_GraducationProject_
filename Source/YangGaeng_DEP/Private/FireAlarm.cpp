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

void AFireAlarm::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	// 현재 시나리오일 때
	if (bCanOperate)
	{
		Super::InteractEvent_Implementation(Character, bIsUI_Expression);
		bCanOperate = false;

		EndEvent();
		// 화재 경보음 활성화
		AlarmAudio->Play();
	}
}
