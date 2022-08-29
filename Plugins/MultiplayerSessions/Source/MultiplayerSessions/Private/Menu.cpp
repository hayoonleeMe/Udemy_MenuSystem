// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"

void UMenu::MenuSetup()
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;	// 위젯을 클릭 시 포커스 되도록 한다.

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController)
		{
			FInputModeUIOnly InputModeData;	// 위젯이 생성되고 메뉴 셋업이 끝나면 InputMode를 세팅한다. UIOnly이므로 다른 Pawn들 말고 UI에만 입력을 적용한다.
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);	// 마우스 락을 사용하지 못하게 한다. 따라서 마우스 커서가 게임 화면 밖으로 나갈 수 있도록 한다. 
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);	// 마우스 커서를 보이게 한다.
		}
	}
}