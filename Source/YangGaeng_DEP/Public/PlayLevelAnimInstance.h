// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayLevelAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class YANGGAENG_DEP_API UPlayLevelAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Anim")
	bool GetHasFireExtinguisher() const { return bHasFireExtinguisher; }

	UFUNCTION(BlueprintCallable, Category = "Anim")
	void SetHasFireExtinguisher(bool NewValue){ bHasFireExtinguisher = NewValue; }

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim", Meta = (AllowPrivateAccess = true))
	bool bHasFireExtinguisher;
	
};
