// Fill out your copyright notice in the Description page of Project Settings.


#include "YGPlayerState.h"

AYGPlayerState::AYGPlayerState()
{
	SaveSlotName = TEXT("Player");
}

TArray<FCategoryInfo> AYGPlayerState::GetStageInfoes() const
{
	return StageInfoes;
}

void AYGPlayerState::InitStageInfoes()
{
	// 세이브 게임 객체 가져오기
	auto YGSaveGame = Cast<UYGSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (nullptr == YGSaveGame)
	{
		YGSaveGame = GetMutableDefault<UYGSaveGame>();
	}


}

void AYGPlayerState::SetStageInfoes(TArray<FCategoryInfo> _StageInfoes)
{
}
