// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RusPlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"


void ARusPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
	}
}
