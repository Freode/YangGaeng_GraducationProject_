// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractBase.h"

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
	SetHighlight(true);
	Box->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	bCanOperate = true;
}

void AInteractBase::EndEvent()
{
	SetHighlight(false);
	Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	if (InteractSequence)
	{
		InteractSequence->NextInteractEvent();
	}
}

void AInteractBase::SetHighlight(bool bIsHighlight)
{
	for (UStaticMeshComponent*& each : HighlightMeshes)
	{
		UMeshComponent* MeshComponent = Cast<UMeshComponent>(each);
		for (int32 i = 0; i < MeshComponent->GetNumMaterials(); ++i)
		{
			UMaterialInstanceDynamic* Material = MeshComponent->CreateAndSetMaterialInstanceDynamic(i);
			if (Material)
			{
				Material->SetScalarParameterValue(TEXT("Highlight"), 1.0f);
			}
		}
	}
}

