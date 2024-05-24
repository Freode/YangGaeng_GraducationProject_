// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"
#include "DamageInterface.h"

// Sets default values
AFire::AFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DamageTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("DAMAGETIMELINE"));

	static ConstructorHelpers::FObjectFinder<UCurveFloat> CURVE(TEXT("/Game/YangGaeng/Data/Curve_LinearSecond.Curve_LinearSecond"));
	if (CURVE.Succeeded())
	{
		MyCurve = CURVE.Object;
	}

	bCanApplyDamage = true;

}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();

	// Overlapping 함수 바인딩
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AFire::OnSphereBoxOverlapBegin);
	HitBox->OnComponentBeginOverlap.AddDynamic(this, &AFire::OnHitBoxOverlapBegin);
	SmokeBox->OnComponentBeginOverlap.AddDynamic(this, &AFire::OnSmokeBoxOverlapBegin);

	// 타임라인 설정
	if (MyCurve)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleProgress"));
		DamageTimeline->AddInterpFloat(MyCurve, ProgressFunction);

		FOnTimelineEvent TimelineFinishedFunction;
		TimelineFinishedFunction.BindUFunction(this, FName("HandleTimelineFinished"));
		DamageTimeline->SetTimelineFinishedFunc(TimelineFinishedFunction);

		DamageTimeline->SetLooping(false);
	}
	
}

// Called every frame
void AFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DamageTimeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
}

void AFire::OnSmokeBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

// 화상 데미지
void AFire::OnHitBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->Implements<UDamageInterface>())
	{
		PlayerActor = OtherActor;
		PlayerComp = OtherComp;
		DamageTimeline->PlayFromStart();
	}
}

void AFire::OnSphereBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

// 화상 데미지 1초에 1번씩만 전달
void AFire::HandleProgress(float Value)
{
	if (bCanApplyDamage)
	{
		bCanApplyDamage = false;
		IDamageInterface* DamageInterface = Cast<IDamageInterface>(PlayerActor);
		if (DamageInterface)
		{
			DamageInterface->ApplyDamage(this);
		}
	}
}

// 화상 데미지 쿨타임 초기화
void AFire::HandleTimelineFinished()
{
	bCanApplyDamage = true;
	if (HitBox->IsOverlappingComponent(PlayerComp))
	{
		DamageTimeline->PlayFromStart();
	}
}