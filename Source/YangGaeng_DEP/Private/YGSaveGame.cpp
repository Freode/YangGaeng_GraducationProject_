// Fill out your copyright notice in the Description page of Project Settings.


#include "YGSaveGame.h"

// 생성자
UYGSaveGame::UYGSaveGame()
{
	// 할당 및 초기화
	StageInfoes.Init(FCategoryInfo(StageCount), CategoryCount);
}