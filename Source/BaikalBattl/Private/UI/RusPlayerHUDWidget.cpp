// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/RusPlayerHUDWidget.h"

#include "HealthComponent.h"
#include "RusCharacter.h"
#include "Components/TextBlock.h"

void URusPlayerHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (HealthAmountTextBlock)
	{
		const auto RusHealthComponent = Cast<ARusCharacter>(GetOwningPlayerPawn())->FindComponentByClass<UHealthComponent>();
		if (RusHealthComponent)
		{
			RusHealthComponent->OnHealthChanged.AddUObject(this, &ThisClass::OnHealthChanged);
		}
	}
}

void URusPlayerHUDWidget::OnHealthChanged(int32 Health)
{
	if (HealthAmountTextBlock)
	{
		HealthAmountTextBlock->SetText(FText::FromString(FString::FromInt(Health)));
	}
}
