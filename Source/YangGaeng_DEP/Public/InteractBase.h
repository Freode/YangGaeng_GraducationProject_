// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "GameFramework/Actor.h"
#include "InteractSequence.h"
#include "PlayerLevelCharacter.h"
#include "InteractBase.generated.h"


UENUM(BlueprintType)
enum class EInteractKind : uint8
{
	FIRE_EXTINGUISHER,
	FIRE_GASVALVE,
	FIRE_DESCENDINGLIFELINE,
	FIRE_EXITDOOR,
	FIRE_ALARM,
	FIRE_SWITCH
};

UCLASS()
class YANGGAENG_DEP_API AInteractBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Interact")
	void InteractEvent(APlayerLevelCharacter* Character, bool bIsUI_Expression);
	virtual void InteractEvent_Implementation(APlayerLevelCharacter* Character, bool bIsUI_Expression);

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void HighlightEvent();

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void EndEvent();

	UFUNCTION(BlueprintCallable, Category = "Interact")
	void SetHighlight(bool bIsHighlight);

public:

	UPROPERTY(VisibleAnywhere, Category = "Interact")
	USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, Category = "Interact")
	UBoxComponent* Box;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact", meta = (AllowPrivateAccess = true))
	TArray<UStaticMeshComponent*> HighlightMeshes; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = true))
	bool bCanOperate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interact", meta = (AllowPrivateAccess = true))
	EInteractKind InteractKind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact", meta = (AllowPrivateAccess = true))
	AInteractSequence* InteractSequence;
};
