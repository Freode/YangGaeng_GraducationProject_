// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "InteractBase.h"
#include "Components/TimelineComponent.h"
#include "Elevator.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API AElevator : public AInteractBase
{
	GENERATED_BODY()
	
public:

	AElevator();

public:

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void HandleProgress(float value);

	UFUNCTION()
	void HandleTimelineFinished();

	virtual void InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression) override;

	UFUNCTION()
	void CapsuleMoveComponent();

	UFUNCTION()
	void OnCapsuleMoveComponentComplete();

public:

	UPROPERTY(VisibleAnywhere, Category = "Elevator")
	UStaticMeshComponent* SM_Door_Left;

	UPROPERTY(VisibleAnywhere, Category = "Elevator")
	UStaticMeshComponent* SM_Door_Right;

	UPROPERTY(VisibleAnywhere, Category = "Elevator")
	UStaticMeshComponent* Direct;

protected:

	virtual void BeginPlay() override;
	
private:

	UPROPERTY()
	UTimelineComponent* DoorTimeline;

	UPROPERTY()
	UCurveFloat* MyCurve;
};
