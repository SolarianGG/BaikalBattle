// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RusHUD.generated.h"

class UUserWidget;

UCLASS()
class BAIKALBATTL_API ARusHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<UUserWidget> RusUIWidgetClass;

	virtual void BeginPlay() override;
};
