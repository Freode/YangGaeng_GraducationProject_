// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GamePlay.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API UGamePlay : public UUserWidget
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, Category = "Game")
	void GameStart(float Timer);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void GameEnd(bool bIsOver);
};
