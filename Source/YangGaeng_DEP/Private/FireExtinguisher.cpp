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
	
	if (bIsTickOn)
	{
		
		Count += DeltaTime;
		if (Count > Threshold)
		{
			bIsOperate = true;
			Count = 0.0f;
		}
	}

	if (bIsOperate)
	{
		bIsOperate = false;
		
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

	if (bCanOperate)
	{
		bCanOperate = false;
		InteractCharacter = Character;

		UPlayLevelAnimInstance* Anim = Cast<UPlayLevelAnimInstance>
			(InteractCharacter->GetMesh()->GetAnimInstance());
		if (Anim == nullptr) { return; }

		Anim->SetHasFireExtinguisher(true);
		AttachToComponent(InteractCharacter->GetMesh(), 
			FAttachmentTransformRules::SnapToTargetNotIncludingScale, 
			FName(TEXT("FireExtinguisher_Socket")));
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