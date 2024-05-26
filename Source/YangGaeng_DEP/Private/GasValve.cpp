// Fill out your copyright notice in the Description page of Project Settings.


#include "GasValve.h"

AGasValve::AGasValve()
{
	ValveRockTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("VALVEROCKTIMELINE"));

	static ConstructorHelpers::FObjectFinder<UCurveFloat> CURVE(TEXT("/Game/YangGaeng/Data/Curve_LinearSecond.Curve_LinearSecond"));
	if (CURVE.Succeeded())
	{
		MyCurve = CURVE.Object;
	}
}

void AGasValve::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	if (bCanOperate)
	{
		Super::InteractEvent_Implementation(Character, bIsUI_Expression);
		bCanOperate = false;
		ValveRockTimeline->PlayFromStart();
	}

}

void AGasValve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ValveRockTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}

void AGasValve::HandleProgress(float value)
{
	SetActorRotation(FRotator(0.0f, 90.0f, value * 90.0f));
}

void AGasValve::HandleTimelineFinished()
{
	EndEvent();
}

void AGasValve::BeginPlay()
{
	Super::BeginPlay();

	if (MyCurve)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));
		ValveRockTimeline->AddInterpFloat(MyCurve, ProgressFunction);

		FOnTimelineEvent TimelineFinishedFunction;
		TimelineFinishedFunction.BindUFunction(this, FName("HandleTimelineFinished"));;
		ValveRockTimeline->SetTimelineFinishedFunc(TimelineFinishedFunction);

		ValveRockTimeline->SetLooping(false);
	}
}
