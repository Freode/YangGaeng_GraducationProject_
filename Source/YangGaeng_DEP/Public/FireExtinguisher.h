// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "InteractBase.h"
#include "Components/ArrowComponent.h"
#include "FireExtinguisher.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API AFireExtinguisher : public AInteractBase
{
	GENERATED_BODY()
	
public:

	AFireExtinguisher();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void HighlightEvent() override;

	virtual void EndEvent() override;
	
	virtual void InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression) override;

public:

	UPROPERTY(VisibleAnywhere, Category = "FireExtinguisher")
	UStaticMeshComponent* SM_Hose;

	UPROPERTY(VisibleAnywhere, Category = "FireExtinguisher")
	UStaticMeshComponent* SM_Handle;

	UPROPERTY(VisibleAnywhere, Category = "FireExtinguisher")
	UStaticMeshComponent* SM_Body;

	UPROPERTY(VisibleAnywhere, Category = "FireExtinguisher")
	UArrowComponent* Smoke_Arrow;
	
private:

	void SetMode(bool bIsPickup);

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FireExtinguisher", Meta = (AllowPrivateAccess = true))
	int32 Delay;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FireExttinguisher", Meta = (AllowPrivateAccess = true))
	class APlayerLevelCharacter* InteractCharacter;

	float Count = 0.0f;
	float Threshold = 0.1f;
	bool bIsOperate = false;
	bool bIsTickOn = false;
};
