// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "GameFramework/PlayerState.h"
#include "YGSaveGame.h"
#include "YGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API AYGPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:

	AYGPlayerState();

	// 스테이지에 입력된 정보 가져오기
	TArray<FCategoryInfo> GetStageInfoes() const;

	// 세이브 데이터로부터 스테이지 정보 초기화
	void InitStageInfoes();

	// 게임 저장 슬롯 이름
	FString SaveSlotName;

protected:
	UPROPERTY(Transient)
	TArray<FCategoryInfo> StageInfoes;
	

private:

	void SetStageInfoes(TArray<FCategoryInfo> StageInfoes);
};
