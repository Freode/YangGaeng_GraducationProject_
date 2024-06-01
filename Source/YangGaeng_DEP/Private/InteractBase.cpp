// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractBase.h"
#include "InteractSequence.h"

// Sets default values
AInteractBase::AInteractBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("ROOTSCENE"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));

	RootComponent = RootScene;
	Box->SetupAttachment(RootScene);

}

// Called when the game starts or when spawned
void AInteractBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractBase::InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression)
{
	if (bIsUI_Expression)
	{

	}
}

void AInteractBase::HighlightEvent()
{
	// 하이라이팅 기능 및 Collision 활성화
	SetHighlight(true);
	Box->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	bCanOperate = true;
}

void AInteractBase::EndEvent()
{
	// 하이라이팅 효과 종료
	SetHighlight(false);
	Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	// 다음 상호작용 도구 준비
	AInteractSequence* InterSeq = Cast<AInteractSequence>(InteractSequence);
	if (InterSeq)
	{
		InterSeq->NextInteractEvent();
	}
}

void AInteractBase::SetHighlight(bool bIsHighlight)
{
	// 하이라이팅을 위해 등록된 Mesh 컴포넌트 모두 반복
	for (UStaticMeshComponent*& each : HighlightMeshes)
	{
		UMeshComponent* MeshComponent = Cast<UMeshComponent>(each);
		for (int32 i = 0; i < MeshComponent->GetNumMaterials(); ++i)
		{
			// 하이라이팅 활성화
			UMaterialInstanceDynamic* Material = MeshComponent->CreateAndSetMaterialInstanceDynamic(i);
			if (Material)
			{
				Material->SetScalarParameterValue(TEXT("Highlight"), 1.0f);
			}
		}
	}
}

