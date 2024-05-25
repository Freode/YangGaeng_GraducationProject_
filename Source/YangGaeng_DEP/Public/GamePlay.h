// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "GamePlay.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API UGamePlay : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void GameStart(float StartTimer);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void GameEnd(bool bIsOver);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void SetHealth(int32 NewHealth);

protected:

	virtual void NativeConstruct() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game", Meta = (AllowPrivateAccess = true))
	float Timer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game", Meta = (AllowPrivateAccess = true))
	bool bIsTimerOn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game", Meta = (AllowPrivateAccess = true))
	int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game", Meta = (AllowPrivateAccess = true))
	TArray<UImage*> HeartArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game", Meta = (AllowPrivateAccess = true))
	float GameScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game", Meta = (AllowPrivateAccess = true))
	bool bIsClear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game", Meta = (AllowPrivateAccess = true))
	float PrintGameScoreTime;

	UPROPERTY()
	class UTextBlock* TextTime;

	UPROPERTY()
	class UImage* Image_Heart_1;

	UPROPERTY()
	class UImage* Image_Heart_2;

	UPROPERTY()
	class UImage* Image_Heart_3;

	UPROPERTY()
	class UImage* Image_Heart_4;

	UPROPERTY()
	class UImage* Image_Heart_5;

	UPROPERTY()
	class UTextBlock* Text_BeforeHighScore;

	UPROPERTY()
	class UTextBlock* Text_GameScore_Exp;

	UPROPERTY()
	class UTextBlock* Text_GameState;

	class UTexture2D* HeartFullTexture;
	class UTexture2D* HeartEmptyTexture;

};
