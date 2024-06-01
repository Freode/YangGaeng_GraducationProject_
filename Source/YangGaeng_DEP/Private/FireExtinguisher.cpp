// Fill out your copyright notice in the Description page of Project Settings.


#include "FireExtinguisher.h"
#include "Engine/World.h"
#include "ExtinguisherSmoke.h"
#include "PlayLevelAnimInstance.h"

AFireExtinguisher::AFireExtinguisher()
{
	SM_Hose = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMHOSE"));
	SM_Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMBODY"));
	SM_Handle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SMHANDLE"));
	Smoke_Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("SMOKEARROW"));

	SM_Hose->SetupAttachment(RootComponent);
	SM_Body->SetupAttachment(RootComponent);
	SM_Handle->SetupAttachment(RootComponent);
	Smoke_Arrow->SetupAttachment(RootComponent);
	
}

void AFireExtinguisher::BeginPlay()
{
	Super::BeginPlay();
}

void AFireExtinguisher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 시간 측정 
	if (bIsTickOn)
	{
		Count += DeltaTime;
		if (Count > Threshold)
		{
			// 소화약제 분사 파티클 생성 활성화
			bIsOperate = true;
			Count = 0.0f;
		}
	}
	// 단 한 번만 작동
	if (bIsOperate)
	{
		bIsOperate = false;
		// 소화약제 파티클 생성
		UWorld* World = GetWorld();
		if (World)
		{
			World->SpawnActor<AExtinguisherSmoke>(
				AExtinguisherSmoke::StaticClass(), 
				Smoke_Arrow->GetComponentLocation(), 
				Smoke_Arrow->GetComponentRotation());
		}

	}
}

void AFireExtinguisher::HighlightEvent()
{
	Super::HighlightEvent();
}

void AFireExtinguisher::EndEvent()
{
	Super::EndEvent();
}

void AFireExtinguisher::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	Super::InteractEvent_Implementation(Character, bIsUI_Expression);
	// 상호작용할 수 있을 때
	if (bCanOperate)
	{
		bCanOperate = false;
		InteractCharacter = Character;

		// 애니메이션 클래스 가져오기
		UPlayLevelAnimInstance* Anim = Cast<UPlayLevelAnimInstance>
			(InteractCharacter->GetMesh()->GetAnimInstance());
		if (Anim == nullptr) { return; }

		// 소화기 애니메이션 활성화
		Anim->SetHasFireExtinguisher(true);

		// 소화기를 캐릭터의 지정한 위치에 붙히기
		AttachToComponent(InteractCharacter->GetMesh(), 
			FAttachmentTransformRules::SnapToTargetNotIncludingScale, 
			FName(TEXT("FireExtinguisher_Socket")));

		// 소화기 모드 활성화
		SetMode(true);
	}
}

void AFireExtinguisher::SetMode(bool bIsPickup)
{
	if (bIsPickup)
	{
		SetHighlight(false);
		SM_Hose->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 23.4f), FRotator(-90.0f, 0.0f, 0.0f));
	}
	else
	{
		SM_Handle->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		SM_Hose->SetRelativeLocationAndRotation(FVector(0.0f, 3.0f, 23.4f), FRotator(0.0f, 0.0f, 0.0f));
	}
}