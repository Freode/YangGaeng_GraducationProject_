// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "Engine/GameInstance.h"
#include "YGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API UYGGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category = "Stage")
	int32 CategoryNum = -1;

	UPROPERTY(BlueprintReadWrite, Category = "Stage")
	int32 StageNum = -1;

	// 스테이지와 카테고리 번호 설정
	UFUNCTION(BlueprintCallable, Category = "Stage")
	void SetCategoryStageNum(const int32 _CategoryNum, const int32 _StageNum);
};
