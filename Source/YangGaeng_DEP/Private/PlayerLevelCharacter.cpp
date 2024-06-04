// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerLevelCharacter.h"

// Sets default values
APlayerLevelCharacter::APlayerLevelCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerLevelCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerLevelCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerLevelCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// 움직임 함수 바인딩
	PlayerInputComponent->BindAxis(TEXT("Movement"), this, &APlayerLevelCharacter::Movement);
	// 환경 설정 출력 바인딩
	PlayerInputComponent->BindAction(TEXT("ConfigurationPrint"), EInputEvent::IE_Pressed, this, &APlayerLevelCharacter::ConfigurationPrint);
	// 앉기 함수 바인딩
	PlayerInputComponent->BindAction(TEXT("Sit"), EInputEvent::IE_Pressed, this, &APlayerLevelCharacter::SitDown);
	PlayerInputComponent->BindAction(TEXT("Sit"), EInputEvent::IE_Released, this, &APlayerLevelCharacter::SitUp);
	// 소화약제 분사 함수 바인딩
	PlayerInputComponent->BindAction(TEXT("FireExtinguisher"), EInputEvent::IE_Pressed, this, &APlayerLevelCharacter::FireExtinguisherOn);
	PlayerInputComponent->BindAction(TEXT("FireExtinguisher"), EInputEvent::IE_Released, this, &APlayerLevelCharacter::FireExtinguisherOff);

}

void APlayerLevelCharacter::ApplyDamage(AActor* InteractObject)
{

}

void APlayerLevelCharacter::Movement(float NewAxisValue)
{
}

void APlayerLevelCharacter::InteractOfE()
{
}

void APlayerLevelCharacter::ConfigurationPrint()
{
}

void APlayerLevelCharacter::SitDown()
{
}

void APlayerLevelCharacter::SitUp()
{
}

void APlayerLevelCharacter::FireExtinguisherOn()
{
}

void APlayerLevelCharacter::FireExtinguisherOff()
{
}
