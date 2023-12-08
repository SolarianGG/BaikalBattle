// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RusPlayerController.generated.h"


class UInputMappingContext;
/**
 * 
 */
UCLASS()
class BAIKALBATTL_API ARusPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;
	
	virtual void BeginPlay() override;
};
