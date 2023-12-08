// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/RusGameModeBase.h"

#include "Player/RusCharacter.h"
#include "Player/RusPlayerController.h"

ARusGameModeBase::ARusGameModeBase()
{
	DefaultPawnClass = ARusCharacter::StaticClass();
	PlayerControllerClass = ARusPlayerController::StaticClass();
}
