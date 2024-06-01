// Fill out your copyright notice in the Description page of Project Settings.


#include "Information.h"
#include "YGGameInstance.h"
#include "Components/TextBlock.h"
#include "Components/AudioComponent.h"

void UInformation::NativeConstruct()
{
	Super::NativeConstruct();
	Text_Main = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Main")));
	Text_Context = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Context")));
	Image_Info = Cast<UImage>(GetWidgetFromName(TEXT("Image_Info")));

	EquipmentExplaination = LoadObject<UDataTable>(nullptr, TEXT("/Game/YangGaeng/Data/DT_Equipment_Explaination.DT_Equipment_Explaination"));
}

void UInformation::SetContext(FText Main, FText Context, UTexture2D* Texture, USoundBase* SoundWav)
{
	// 텍스트 문구 설정
	Text_Main->SetText(Main);
	Text_Context->SetText(Context);
	// 이미지 설정
	if (Texture == nullptr)
	{
		// 없으면, 숨기기
		Image_Info->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		Image_Info->SetVisibility(ESlateVisibility::Visible);
		Image_Info->SetBrushFromTexture(Texture);
	}
	// 사운드가 존재하면, 새롭게 설정한 뒤, 재생
	if (SoundWav != nullptr)
	{
		Audio->SetSound(SoundWav);
		Audio->Play();
	}
}

void UInformation::FindContext(EInteract Interact, int32 Seqence)
{
	const UEnum* EnumPtr = StaticEnum<EInteract>();
	if (EnumPtr == nullptr) { return; }

	// 현재, 상호작용하는 도구의 열거형 이름을 문자열로 변환
	FString OnlyRowName = EnumPtr->GetNameByValue((int32)CurrentInteract).ToString();
	// 행 이름 형식으로 변환
	FString RowString = FString::Printf(TEXT("%s_%d"), *OnlyRowName, Seqence);

	// 행 이름에 따라서 데이터 테이블에서 행 정보를 가져오기
	FInteractContext* InteractContext = EquipmentExplaination->FindRow<FInteractContext>(*RowString, TEXT(""));
	// 가져온 정보로 설정
	SetContext(InteractContext->Title, InteractContext->Context, InteractContext->Image, InteractContext->SoundWav);
}

void UInformation::SetUISequence(EInteract Interact)
{
	CurrentInteract = Interact;
	CurrentUI_Rows.Empty();
	// 현재 상호작용하는 도구의 이름을 가진 행을 모두 가져와서 배열(순서)에 넣는 과정
	for (FName& Each : RowNames)
	{
		FString StringEach = Each.ToString();
		FString Left = "", Right = "";
		StringEach.Split(TEXT("_"), &Left, &Right);

		// 열거형을 문자열로 변환
		const UEnum* EnumPtr = StaticEnum<EInteract>();
		if (EnumPtr == nullptr) { return; }

		// 행 이름의 도구 종류와 현재 도구 이름이 같을 때
		if (Left.Equals(EnumPtr->GetNameByValue((int32)CurrentInteract).ToString()))
		{
			// 순서에 추가
			CurrentUI_Rows.Add(Each);
		}
	}
	// 처음부터 시작
	FindContext(CurrentInteract, 1);
}