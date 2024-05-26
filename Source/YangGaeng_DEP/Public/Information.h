// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../YangGaeng_DEP.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Engine/DataTable.h"
#include "Information.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EInteract : uint8
{
	FireExtinguisher,
	FireGasValve,
	FireDescendingLifeLine,
	FireExitDoor,
	FireAlarm,
	FireSwitch
};

UCLASS()
class YANGGAENG_DEP_API UInformation : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Information")
	void SetContext(FText Main, FText Context, UTexture2D* Texture);

	UFUNCTION(BlueprintCallable, Category = "Information")
	void FindContext(EInteract Interact, int32 Seq);

	UFUNCTION(BlueprintCallable, Category = "Information")
	void SetUISequence(EInteract Interact);

public:


protected:

	virtual void NativeConstruct() override;

private:
	
	UPROPERTY()
	class UTextBlock* Text_Context;

	UPROPERTY()
	class UTextBlock* Text_Main;

	UPROPERTY()
	class UButton* Btn_Check;

	UPROPERTY()
	class UImage* Image_Info;

	UPROPERTY()
	class UImage* Image_Background;
	
	UPROPERTY(BlueprintReadOnly, Category = "Information", Meta = (AllowPrivateAccess = true))
	TArray<FName> RowNames;

	UPROPERTY(BlueprintReadOnly, Category = "Information", Meta = (AllowPrivateAccess = true))
	TArray<FName> CurrentUI_Rows;

	UPROPERTY(BlueprintReadOnly, Category = "Information", Meta = (AllowPrivateAccess = true))
	int32 Seq;

	UPROPERTY(BlueprintReadOnly, Category = "Information", Meta = (AllowPrivateAccess = true))
	EInteract CurrentInteract;

	class UDataTable* EquipmentExplaination;

};
