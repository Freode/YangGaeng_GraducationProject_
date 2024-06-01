// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricSwitch.h"

AElectricSwitch::AElectricSwitch()
{
	SwitchTimelines = CreateDefaultSubobject<UTimelineComponent>(TEXT("SWITCHTIMELINE"));

	static ConstructorHelpers::FObjectFinder<UCurveFloat> CURVE(TEXT("/Game/YangGaeng/Data/Curve_LinearSecond.Curve_LinearSecond"));
	if (CURVE.Succeeded())
	{
		MyCurve = CURVE.Object;
	}
}

void AElectricSwitch::BeginPlay()
{
	Super::BeginPlay();

	if (MyCurve)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));
		SwitchTimelines->AddInterpFloat(MyCurve, ProgressFunction);

		FOnTimelineEvent TimelineFinishedFunction;
		TimelineFinishedFunction.BindUFunction(this, FName("HandleTimelineFinished"));
		SwitchTimelines->SetTimelineFinishedFunc(TimelineFinishedFunction);

		SwitchTimelines->SetLooping(false);
	}
}

void AElectricSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SwitchTimelines->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}

// 상호작용 함수
void AElectricSwitch::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	// 현재 시나리오 상태일 때
	if (bCanOperate)
	{
		bCanOperate = false;
		InteractEvent_Implementation(Character, bIsUI_Expression);
		// 스위치 작동
		SwitchTimelines->PlayFromStart();
	}
}

// 타임라인 작동 함수
void AElectricSwitch::HandleProgress(float Value)
{
	SetActorRotation(FRotator(Value * 120.0f, 0.0f, 90.0f));
}

// 타임라인 종료 함수
void AElectricSwitch::HandleTimelineFinished()
{
	EndEvent();
}
