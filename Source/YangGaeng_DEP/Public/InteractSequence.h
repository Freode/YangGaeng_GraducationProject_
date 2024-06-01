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

	// 현재 순서
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	int32 Sequence;

	// 상호작용 순서 정하기
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	TArray<AInteractBase*> Interacts;

	// 스테이지 진입 시, 바로 준비해야하는 상호작용
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	TArray<AInteractBase*> PrepareActors;

	// UI 출력할 상호작용 도구 번호
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence", Meta = (AllowPrivateAccess = true))
	int32 UI_ExplanationIdx;

	// 타이머 핸들러
	FTimerHandle TimerHandle;
};
