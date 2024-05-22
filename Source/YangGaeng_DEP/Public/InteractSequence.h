// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractBase.h"
#include "InteractSequence.generated.h"


UCLASS()
class YANGGAENG_DEP_API AInteractSequence : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractSequence();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Sequence")
	void NextInteractEvent();

private:

	void DelayComplete();

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	int32 Sequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	TArray<AInteractBase*> Interacts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	TArray<AInteractBase*> PrepareActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	int32 UI_ExplanationIdx;

	FTimerHandle TimerHandle;
};
