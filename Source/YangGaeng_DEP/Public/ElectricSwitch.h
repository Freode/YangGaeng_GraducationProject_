// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "InteractBase.h"
#include "Components/TimelineComponent.h"
#include "ElectricSwitch.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API AElectricSwitch : public AInteractBase
{
	GENERATED_BODY()
	
public:

	AElectricSwitch();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression) override;

	UFUNCTION()
	void HandleProgress(float Value);

	UFUNCTION()
	void HandleTimelineFinished();

public:

	UPROPERTY(VisibleAnywhere, Category = "ElectricSwitch")
	UStaticMeshComponent* Switch_Body;

	UPROPERTY(VisibleAnywhere, Category = "ElectricSwitch")
	UStaticMeshComponent* Switch_Root;

private:

	UPROPERTY()
	UTimelineComponent* SwitchTimelines;

	UPROPERTY()
	UCurveFloat* MyCurve;


	
};
