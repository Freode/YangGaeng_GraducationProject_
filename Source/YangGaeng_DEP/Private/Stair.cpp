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
		// 현재 계단에 있는 캐릭터 객체 가져오기
		TArray<AActor*> OverlappingActors;
		Box->GetOverlappingActors(OverlappingActors, APlayerLevelCharacter::StaticClass());

		if (OverlappingActors.Num() > 0)
		{
			// 캐릭터가 계단을 따라 자동 이동
			APlayerLevelCharacter* PC = Cast<APlayerLevelCharacter>(OverlappingActors[0]);
			PC->GetCharacterMovement()->AddForce(Direction->GetRelativeLocation());

			UWorld* World = GetWorld();
			if (World == nullptr) { return; }
			// 5초 후, 스테이지 성공 출력 띄우기
			World->GetTimerManager().SetTimer(TimerHandle, this, &AStair::OnDelayComplete, 5.0f, false);
		}
	}
}

void AStair::OnDelayComplete()
{
	EndEvent();
}
