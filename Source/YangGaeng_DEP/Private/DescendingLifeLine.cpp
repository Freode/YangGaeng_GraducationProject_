// Fill out your copyright notice in the Description page of Project Settings.


#include "DescendingLifeLine.h"

ADescendingLifeLine::ADescendingLifeLine()
{
	LifeLineTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("LIFELINETIMELINE"));
	RopeTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("ROPETIMELINE"));

	static ConstructorHelpers::FObjectFinder<UCurveFloat> CURVE(TEXT("/Game/YangGaeng/Data/Curve_LinearSecond.Curve_LinearSecond"));
	if (CURVE.Succeeded())
	{
		MyCurve = CURVE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UCurveFloat> ROPECURVE(TEXT("/Game/YangGaeng/Data/Curve_Line_20to5.Curve_Line_20to5"));
	if (ROPECURVE.Succeeded())
	{
		RopeCurve = ROPECURVE.Object;
	}
}

void ADescendingLifeLine::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	if (bCanOperate)
	{
		Super::InteractEvent_Implementation(Character, bIsUI_Expression);
		bCanOperate = false;
		LifeLineTimeline->PlayFromStart();
		RopeMoveComponent();
		RopeTimeline->PlayFromStart();
		CapsuleMoveComponent();
	}
}

void ADescendingLifeLine::Tick(float DeltaTime)
{
	RopeTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
	LifeLineTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}

void ADescendingLifeLine::HandleProgress(float value)
{
	SetActorRotation(FRotator(0.0f, 0.0f, -90.0f * value));
}

void ADescendingLifeLine::HandleTimelineFinished()
{
}

void ADescendingLifeLine::ScaleHandleProgress(float value)
{
	SM_Rope->SetRelativeScale3D(FVector(0.1f, 0.1f, value));
}

void ADescendingLifeLine::ScaleHandleTimelineFinished()
{
}

void ADescendingLifeLine::CapsuleMoveComponent()
{
	// 완강기에 있는 캐릭터 가져오기
	TArray<AActor*> OverlappingActors;
	Box->GetOverlappingActors(OverlappingActors, APlayerLevelCharacter::StaticClass());

	if (OverlappingActors.Num() > 0)
	{
		APlayerLevelCharacter* PC = Cast<APlayerLevelCharacter>(OverlappingActors[0]);
		PC->GetCapsuleComponent()->GetComponentLocation();
		// 목표 위치 설정
		FVector NewLocation = PC->GetCapsuleComponent()->GetComponentLocation();
		NewLocation.Z = SM_Rope->GetComponentLocation().Z;
		FRotator NewRotation = FRotator::ZeroRotator;
		// 타임라인 델리게이트에 함수 바인딩
		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("CapsuleMoveComponent"));
		// Move Component 실행 준비
		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		LatentInfo.ExecutionFunction = "OnCapsuleMoveComponentComplete";
		LatentInfo.Linkage = 0;
		LatentInfo.UUID = __COUNTER__;
		// 캐릭터를 완강기 줄을 따라 최하단으로 이동하도록 구현
		UKismetSystemLibrary::MoveComponentTo(PC->GetCapsuleComponent(), NewLocation, NewRotation, false, false, 5.0f, false, EMoveComponentAction::Type::Move, LatentInfo);
	}
}

void ADescendingLifeLine::OnCapsuleMoveComponentComplete()
{

}

void ADescendingLifeLine::RopeMoveComponent()
{
	FVector NewLocation = SM_Rope->GetComponentLocation();
	NewLocation.Z = -500.0f;
	FRotator NewRotation = FRotator::ZeroRotator;

	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("RopeMoveComponent"));

	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
	LatentInfo.ExecutionFunction = "OnRopeMoveComponentComplete";
	LatentInfo.Linkage = 0;
	LatentInfo.UUID = __COUNTER__;

	UKismetSystemLibrary::MoveComponentTo(SM_Rope, NewLocation, NewRotation, false, false, 2.0f, false, EMoveComponentAction::Type::Move, LatentInfo);
}

void ADescendingLifeLine::OnRopeMoveComponentComplete()
{
	EndEvent();
}

void ADescendingLifeLine::BeginPlay()
{
	Super::BeginPlay();

	if (MyCurve)
	{
		FOnTimelineFloat LifeLineProgressFunction;
		LifeLineProgressFunction.BindUFunction(this, FName("HandleProgress"));
		LifeLineTimeline->AddInterpFloat(MyCurve, LifeLineProgressFunction);

		FOnTimelineEvent LifeLineCompleteFunction;
		LifeLineCompleteFunction.BindUFunction(this, FName("HandleTimelineFinished"));
		LifeLineTimeline->SetTimelineFinishedFunc(LifeLineCompleteFunction);

		LifeLineTimeline->SetLooping(false);
	}

	if (RopeCurve)
	{
		FOnTimelineFloat RopeProgressFunction;
		RopeProgressFunction.BindUFunction(this, FName("ScaleHandleProgress"));
		RopeTimeline->AddInterpFloat(RopeCurve, RopeProgressFunction);

		FOnTimelineEvent RopeCompleteFunction;
		RopeCompleteFunction.BindUFunction(this, FName("ScaleHandleTimelineFinished"));
		RopeTimeline->SetTimelineFinishedFunc(RopeCompleteFunction);

		RopeTimeline->SetLooping(false);
	}
}
