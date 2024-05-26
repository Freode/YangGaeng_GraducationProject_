// Fill out your copyright notice in the Description page of Project Settings.


#include "Stair.h"
#include "TimerManager.h"

AStair::AStair()
{
	Stairs = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("STAIRS"));
	Direction = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DIRECTION"));
}

void AStair::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	if (bCanOperate)
	{
		bCanOperate = false;
		Super::InteractEvent_Implementation(Character, bIsUI_Expression);

		TArray<AActor*> OverlappingActors;
		Box->GetOverlappingActors(OverlappingActors, APlayerLevelCharacter::StaticClass());

		if (OverlappingActors.Num() > 0)
		{
			APlayerLevelCharacter* PC = Cast<APlayerLevelCharacter>(OverlappingActors[0]);
			PC->GetCharacterMovement()->AddForce(Direction->GetRelativeLocation());

			UWorld* World = GetWorld();
			if (World == nullptr) { return; }

			World->GetTimerManager().SetTimer(TimerHandle, this, &AStair::OnDelayComplete, 5.0f, false);
		}
	}
}

void AStair::OnDelayComplete()
{
	EndEvent();
}
