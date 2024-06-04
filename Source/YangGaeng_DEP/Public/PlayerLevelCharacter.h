// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "GameFramework/Character.h"
#include "GamePlay.h"
#include "DamageInterface.h"
#include "PlayerLevelCharacter.generated.h"

UCLASS()
class YANGGAENG_DEP_API APlayerLevelCharacter : public ACharacter, public IDamageInterface 
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerLevelCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void ApplyDamage(AActor* InteractObject) override;

	UPROPERTY(VisibleAnywhere, Category = "UI")
	UGamePlay* WG_GamePlay;

private:

	void Movement(float NewAxisValue);
	void InteractOfE();
	void ConfigurationPrint();
	void SitDown();
	void SitUp();
	void FireExtinguisherOn();
	void FireExtinguisherOff();

};