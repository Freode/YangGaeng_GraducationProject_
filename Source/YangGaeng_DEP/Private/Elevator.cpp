// Fill out your copyright notice in the Description page of Project Settings.


#include "Elevator.h"

AElevator::AElevator()
{
	DoorTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("DOORTIMELINE"));
	SM_Door_Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMDOORLEFT"));
	SM_Door_Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMDOORRIGHT"));
	Direct = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DIRECT"));

	static ConstructorHelpers::FObjectFinder<UCurveFloat> CURVE(TEXT("/Game/YangGaeng/Data/Curve_Line_2to1.Curve_Line_2to1"));
	if (CURVE.Succeeded())
	{
		MyCurve = CURVE.Object;
	}
}

void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}

void AElevator::HandleProgress(float value)
{
	SM_Door_Right->AddRelativeLocation(FVector(-4.5f * value, 0.0f, 0.0f));
	SM_Door_Left->AddRelativeLocation(FVector(4.5f * value, 0.0f, 0.0f));
}

void AElevator::HandleTimelineFinished()
{

}

void AElevator::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	if (bCanOperate)
	{
		bCanOperate = false;
		Super::InteractEvent_Implementation(Character, bIsUI_Expression);

		DoorTimeline->PlayFromStart();
		CapsuleMoveComponent();
	}
}

void AElevator::CapsuleMoveComponent()
{
	TArray<AActor*> OverlappingActors;
	Box->GetOverlappingActors(OverlappingActors, APlayerLevelCharacter::StaticClass());

	if (OverlappingActors.Num() > 0)
	{
		APlayerLevelCharacter* PC = Cast<APlayerLevelCharacter>(OverlappingActors[0]);

		FVector NewLocation = Direct->GetComponentLocation();
		NewLocation.Z = -500.0f;
		FRotator NewRotation = FRotator::ZeroRotator;

		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("CapsuleMoveComponent"));

		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		LatentInfo.ExecutionFunction = "OnCapsuleMoveComponentComplete";
		LatentInfo.Linkage = 0;
		LatentInfo.UUID = __COUNTER__;

		UKismetSystemLibrary::MoveComponentTo(PC->GetRootComponent(), NewLocation, NewRotation, false, false, 2.0f, false, EMoveComponentAction::Type::Move, LatentInfo);
	}
}

void AElevator::OnCapsuleMoveComponentComplete()
{
	EndEvent();
}

void AElevator::BeginPlay()
{
	Super::BeginPlay();

	if (MyCurve)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));
		DoorTimeline->AddInterpFloat(MyCurve, ProgressFunction);

		FOnTimelineEvent OnCompleteFunction;
		OnCompleteFunction.BindUFunction(this, FName("HandleTimelineFinished"));
		DoorTimeline->SetTimelineFinishedFunc(OnCompleteFunction);

		DoorTimeline->SetLooping(false);
	}
}
