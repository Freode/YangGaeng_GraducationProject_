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
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	TArray<FCategoryInfo> GetStageInfoes() const;

	// 전체 초기화
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void AllStageInitialization();

	// 세이브 데이터로부터 스테이지 정보 초기화
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void InitStageInfoes();

	// 플레이어 데이터 저장
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SavePlayerData();

	// 게임 저장 슬롯 이름
	FString SaveSlotName = TEXT("Player");

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SetStageInfoes(TArray<FCategoryInfo> StageInfoes);

	// 현재 스테이지 정보 업데이트
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void UpdateStageInfo(bool bIsClear, int32 StageScore);

	// 현재 스테이지 최고 점수 가져오기
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	int32 GetCurrentStageHighScore() const;

protected:
	UPROPERTY(Transient)
	TArray<FCategoryInfo> StageInfoes;
	

private:

};
