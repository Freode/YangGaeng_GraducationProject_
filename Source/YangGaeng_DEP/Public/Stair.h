// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "InteractBase.h"
#include "Stair.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API AStair : public AInteractBase
{
	GENERATED_BODY()
	
public:

	AStair();

public:

	UPROPERTY(VisibleAnywhere, Category = "Stair")
	UStaticMeshComponent* Stairs;

	UPROPERTY(VisibleAnywhere, Category = "Stair")
	UStaticMeshComponent* Direction;

public:
	
	virtual void InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression) override;

	void OnDelayComplete();

private:

	FTimerHandle TimerHandle;
	
};
