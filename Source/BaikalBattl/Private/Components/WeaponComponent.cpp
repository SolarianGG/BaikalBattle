// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponComponent.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UWeaponComponent::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
}

void UWeaponComponent::AlternativeFire()
{
	UE_LOG(LogTemp, Warning, TEXT("Alternative Fire"));
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeWeapons();
}

void UWeaponComponent::InitializeWeapons()
{
	
}

