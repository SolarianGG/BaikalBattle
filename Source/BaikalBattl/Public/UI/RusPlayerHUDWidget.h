// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RusPlayerHUDWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class BAIKALBATTL_API URusPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* HealthAmountTextBlock;
	
	virtual void NativeOnInitialized() override;

private:
	void OnHealthChanged(int32 Health);
};
