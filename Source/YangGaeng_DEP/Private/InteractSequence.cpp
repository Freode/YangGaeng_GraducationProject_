// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractSequence.h"
#include "PlayerLevelCharacter.h"
#include "TimerManager.h"

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
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AInteractSequence::DelayComplete, 0.2f, false);
	if (Interacts.Num() > 0)
	{
		Interacts[0]->HighlightEvent();
	}
}

// Called every frame
void AInteractSequence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractSequence::NextInteractEvent()
{
	Sequence++;
	// 시나리오를 완료
	if (Interacts.Num() == Sequence)
	{
		UWorld* World = GetWorld();
		if (!World) { return; }
		APlayerController* PlayerController = World->GetFirstPlayerController();
		
		if (!PlayerController) { return; }
		APlayerLevelCharacter* PlayerCharacter = Cast<APlayerLevelCharacter>(PlayerController->GetPawn());

		// 게임 종료 호출
		if (!PlayerCharacter) { return; }
		PlayerCharacter->WG_GamePlay->GameEnd(true);
	}
	// 시나리오 진행 중
	else
	{
		for (AInteractBase* each : Interacts)
		{
			each->HighlightEvent();
		}
	}
}

void AInteractSequence::DelayComplete()
{
	YANGGAENG_LOG(Warning, TEXT("Delay Complete."));
}