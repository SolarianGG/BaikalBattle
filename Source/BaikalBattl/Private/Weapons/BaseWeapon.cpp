// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BaseWeapon.h"

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

