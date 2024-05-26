// Fill out your copyright notice in the Description page of Project Settings.


#include "Information.h"
#include "YGGameInstance.h"
#include "Components/TextBlock.h"

void UInformation::NativeConstruct()
{
	Super::NativeConstruct();
	Text_Main = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Main")));
	Text_Context = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Context")));
	Image_Info = Cast<UImage>(GetWidgetFromName(TEXT("Image_Info")));

	EquipmentExplaination = LoadObject<UDataTable>(nullptr, TEXT("/Game/YangGaeng/Data/DT_Equipment_Explaination.DT_Equipment_Explaination"));
}

void UInformation::SetContext(FText Main, FText Context, UTexture2D* Texture)
{
	Text_Main->SetText(Main);
	Text_Context->SetText(Context);
	if (Texture == nullptr)
	{
		Image_Info->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		Image_Info->SetVisibility(ESlateVisibility::Visible);
		Image_Info->SetBrushFromTexture(Texture);
	}
}

void UInformation::FindContext(EInteract Interact, int32 Seqence)
{
	const UEnum* EnumPtr = StaticEnum<EInteract>();
	if (EnumPtr == nullptr) { return; }

	FString OnlyRowName = EnumPtr->GetNameByValue((int32)CurrentInteract).ToString();
	FString RowString = FString::Printf(TEXT("%s_%d"), *OnlyRowName, Seqence);


	FInteractContext* InteractContext = EquipmentExplaination->FindRow<FInteractContext>(*RowString, TEXT(""));

	SetContext(InteractContext->Title, InteractContext->Context, InteractContext->Image);
}

void UInformation::SetUISequence(EInteract Interact)
{
	CurrentInteract = Interact;
	CurrentUI_Rows.Empty();

	for (FName& Each : RowNames)
	{
		FString StringEach = Each.ToString();
		FString Left = "", Right = "";
		StringEach.Split(TEXT("_"), &Left, &Right);

		// Enum to String
		const UEnum* EnumPtr = StaticEnum<EInteract>();
		if (EnumPtr == nullptr) { return; }

		// 같을 때
		if (Left.Equals(EnumPtr->GetNameByValue((int32)CurrentInteract).ToString()))
		{
			CurrentUI_Rows.Add(Each);
		}
	}

	FindContext(CurrentInteract, 1);
}