// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "InteractBase.h"
#include "Components/TimelineComponent.h"
#include "GasValve.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API AGasValve : public AInteractBase
{
	GENERATED_BODY()
	
public:
	AGasValve();

public:

	virtual void InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression) override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void HandleProgress(float value);

	UFUNCTION()
	void HandleTimelineFinished();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	UTimelineComponent* ValveRockTimeline;

	UPROPERTY()
	UCurveFloat* MyCurve;
	
};
