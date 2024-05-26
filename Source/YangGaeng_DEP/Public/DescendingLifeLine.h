// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "InteractBase.h"
#include "Components/TimelineComponent.h"
#include "DescendingLifeLine.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API ADescendingLifeLine : public AInteractBase
{
	GENERATED_BODY()
	
public:

	ADescendingLifeLine();

public:

	virtual void InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression) override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void HandleProgress(float value);

	UFUNCTION()
	void HandleTimelineFinished();

	UFUNCTION()
	void ScaleHandleProgress(float value);

	UFUNCTION()
	void ScaleHandleTimelineFinished();

	UFUNCTION()
	void CapsuleMoveComponent();

	UFUNCTION()
	void OnCapsuleMoveComponentComplete();

	UFUNCTION()
	void RopeMoveComponent();

	UFUNCTION()
	void OnRopeMoveComponentComplete();

public:

	UPROPERTY(VisibleAnywhere, Category = "LifeLine")
	UStaticMeshComponent* SM_Rope;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	UTimelineComponent* LifeLineTimeline;

	UPROPERTY()
	UTimelineComponent* RopeTimeline;

	UPROPERTY()
	UCurveFloat* MyCurve;

	UPROPERTY()
	UCurveFloat* RopeCurve;

	FTimerHandle CapsuleTimerHandle;
	FTimerHandle RopeTimerHandle;
	
};
