// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Fire.generated.h"

UCLASS()
class YANGGAENG_DEP_API AFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnSmokeBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnHitBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleProgress(float value);

	UFUNCTION()
	void HandleTimelineFinished();

public:

	UPROPERTY(VisibleAnywhere, Category = "Fire")
	UBoxComponent* SmokeBox;

	UPROPERTY(VisibleAnywhere, Category = "Fire")
	USphereComponent* HitBox;

	UPROPERTY(VisibleAnywhere, Category = "Fire")
	USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere, Category = "Fire")
	UParticleSystemComponent* fx;
	
	UPROPERTY(VisibleAnywhere, Category = "Fire")
	UParticleSystemComponent* P_Smoke;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire", Meta = (AllowPrivateAccess = true))
	int32 LifeCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire", Meta = (AllowPrivateAccess = true))
	bool bSmokeMode;

	UPROPERTY()
	UTimelineComponent* DamageTimeline;

	UPROPERTY()
	UCurveFloat* MyCurve;

	AActor* PlayerActor;
	UPrimitiveComponent* PlayerComp;
	bool bCanApplyDamage = true;
};
