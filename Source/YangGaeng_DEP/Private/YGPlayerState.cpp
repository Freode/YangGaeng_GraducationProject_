// Fill out your copyright notice in the Description page of Project Settings.


#include "YGPlayerState.h"
#include "YGGameInstance.h"

AYGPlayerState::AYGPlayerState()
{
	SaveSlotName = TEXT("Player");
}

TArray<FCategoryInfo> AYGPlayerState::GetStageInfoes() const
{
	return StageInfoes;
}

void AYGPlayerState::AllStageInitialization()
{
	auto YGSaveGame = GetMutableDefault<UYGSaveGame>();
	SetStageInfoes(YGSaveGame->StageInfoes);
}

void AYGPlayerState::InitStageInfoes()
{
	// 세이브 게임 객체 가져오기
	auto YGSaveGame = Cast<UYGSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (nullptr == YGSaveGame)
	{
		YGSaveGame = GetMutableDefault<UYGSaveGame>();
	}

	SetStageInfoes(YGSaveGame->StageInfoes);
}

void AYGPlayerState::SetStageInfoes(TArray<FCategoryInfo> _StageInfoes)
{
	StageInfoes = _StageInfoes;
	SavePlayerData();
}

void AYGPlayerState::UpdateStageInfo(bool bIsClear, int32 StageScore)
{
	UYGGameInstance* MyGameInstance = Cast<UYGGameInstance>(GetGameInstance());

	if (MyGameInstance != nullptr)
	{
		int32 CategoryNum = MyGameInstance->CategoryNum;
		int32 StageNum = MyGameInstance->StageNum;
		// YANGGAENG_LOG(Warning, TEXT("Category Num : %d, Stage Num : %d, Score : %d"), CategoryNum, StageNum, StageInfoes[CategoryNum].StageHighScores[StageNum]);
		bool bIsChanged = false;
		if (bIsClear == true)
		{
			StageInfoes[CategoryNum].bIsClearStages[StageNum] = true;
			bIsChanged = true;
		}
		if (StageInfoes[CategoryNum].StageHighScores[StageNum] < StageScore)
		{
			StageInfoes[CategoryNum].StageHighScores[StageNum] = StageScore;
			bIsChanged = true;
		}

		if (bIsChanged)
		{
			SavePlayerData();
		}
	}
}

void AYGPlayerState::SavePlayerData()
{
	UYGSaveGame* NewPlayerData = NewObject<UYGSaveGame>();
	NewPlayerData->StageInfoes = StageInfoes;

	// 게임 슬롯에 저장
	if (!UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		YANGGAENG_LOG(Warning, TEXT("SaveGame Error!"));
	}
}

int32 AYGPlayerState::GetCurrentStageHighScore() const
{
	UYGGameInstance* MyGameInstance = Cast<UYGGameInstance>(GetGameInstance());

	if (MyGameInstance != nullptr)
	{
		return StageInfoes[MyGameInstance->CategoryNum].StageHighScores[MyGameInstance->StageNum];
	}

	return -1;
}