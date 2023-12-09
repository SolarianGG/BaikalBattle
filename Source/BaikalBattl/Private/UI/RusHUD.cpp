// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RusHUD.h"

#include "Blueprint/UserWidget.h"

void ARusHUD::BeginPlay()
{
	Super::BeginPlay();

	if (RusUIWidgetClass)
	{
		const auto RusUIPlayerWidget = CreateWidget<UUserWidget>(GetWorld(), RusUIWidgetClass);
		if (RusUIPlayerWidget)
		{
			RusUIPlayerWidget->AddToViewport();
		}
	}
}
