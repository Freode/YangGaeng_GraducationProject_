// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "YGPlayerState.h"
#include "GameFramework/PlayerController.h"

void UGamePlay::NativeConstruct()
{
	Super::NativeConstruct();

	TextTime = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Time")));

	Image_Heart_1 = Cast<UImage>(GetWidgetFromName(TEXT("Image_Heart_1")));
	Image_Heart_2 = Cast<UImage>(GetWidgetFromName(TEXT("Image_Heart_2")));
	Image_Heart_3 = Cast<UImage>(GetWidgetFromName(TEXT("Image_Heart_3")));
	Image_Heart_4 = Cast<UImage>(GetWidgetFromName(TEXT("Image_Heart_4")));
	Image_Heart_5 = Cast<UImage>(GetWidgetFromName(TEXT("Image_Heart_5")));

	Text_BeforeHighScore = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_BeforeHighScore")));
	Text_GameScore_Exp = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_GameScore_Exp")));
	Text_GameState = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_GameState")));

	HeartArray.Add(Image_Heart_1);
	HeartArray.Add(Image_Heart_2);
	HeartArray.Add(Image_Heart_3);
	HeartArray.Add(Image_Heart_4);
	HeartArray.Add(Image_Heart_5);

	HeartFullTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/YangGaeng/Resources/UI/T_FlatIcon_Heart_Full.T_FlatIcon_Heart_Full"));
	HeartEmptyTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/YangGaeng/Resources/UI/T_FlatIcon_Heart_Empty.T_FlatIcon_Heart_Empty"));
}

void UGamePlay::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UWorld* World = GetWorld();
	if (World == nullptr) { return; }

	if (bIsTimerOn && UGameplayStatics::IsGamePaused(World) == false)
	{
		Timer -= InDeltaTime;
		int32 Minute = FMath::CeilToInt(Timer) / 60;
		int32 Second = FMath::CeilToInt(Timer) % 60;
		FString F_Minute = FString::Printf(TEXT("%d"), Minute);
		FString F_Second = Second < 10 ? 
			FString::Printf(TEXT("0%d"), Second) : 
			FString::Printf(TEXT("%d"), Second);
		FString Format = FString::Printf(TEXT("%s : %s"), *F_Minute, *F_Second);

		TextTime->SetText(FText::FromString(Format));

		if (Timer <= KINDA_SMALL_NUMBER)
		{
			GameEnd(true);
		}
	}
}

void UGamePlay::SetHealth(int32 NewHealth)
{
	for (int i = 0; i < HeartArray.Num(); i++)
	{
		if (i < NewHealth)
		{
			HeartArray[i]->SetBrushFromTexture(HeartEmptyTexture);
		}
		else
		{
			HeartArray[i]->SetBrushFromTexture(HeartFullTexture);
		}
	}
	if (NewHealth <= 0)
	{
		GameEnd(true);
	}
}

void UGamePlay::GameStart(float StartTimer)
{
	Timer = StartTimer;
	Health = 5;
	bIsTimerOn = true;
}

void UGamePlay::GameEnd(bool bIsOver)
{
	if (bIsOver)
	{
		Text_GameState->SetText(FText::FromString(TEXT("GAME OVER")));
		bIsClear = false;
	}
	else
	{
		Text_GameState->SetText(FText::FromString(TEXT("STAGE CLEAR")));
		bIsClear = true;
	}

	APlayerController* PC = GetOwningPlayer();
	if (PC == nullptr) { return; }

	AYGPlayerState* PS = Cast<AYGPlayerState>(PC->PlayerState);
	if (PS == nullptr) { return; }

	FString BeforeHighScoreFormat = FString::Printf(TEXT("이전 최고 점수 : %d"), PS->GetCurrentStageHighScore());
	Text_BeforeHighScore->SetText(FText::FromString(BeforeHighScoreFormat));

	bIsTimerOn = false;
	PC->SetShowMouseCursor(true);
	PC->SetInputMode(FInputModeUIOnly());
}