// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "YangGaeng_DEP.h"
#include "GameFramework/SaveGame.h"
#include "YGSaveGame.generated.h"

/**
 * 
 */

USTRUCT()
struct FCategoryInfo
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<bool> bIsClearStages;
	
	UPROPERTY()
	TArray<int32> StageHighScores;

	FCategoryInfo(){}
	FCategoryInfo(int32 Num)
	{
		bIsClearStages.Init(false, Num);
		StageHighScores.Init(0, Num);
	}
};

UCLASS()
class YANGGAENG_DEP_API UYGSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UYGSaveGame();

	// 스테이지 정보 배열
	UPROPERTY()
	TArray<FCategoryInfo> StageInfoes;

private:

	int32 CategoryCount = 5;
	int32 StageCount = 5;
};
