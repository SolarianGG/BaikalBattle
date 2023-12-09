// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/WeaponComponent.h"

#include "BaseWeapon.h"
#include "RusCharacter.h"
#include "Engine/SkeletalMeshSocket.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UWeaponComponent::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));

	if (CurrentWeapon)
	{
		CurrentWeapon->Fire();
	}
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
	if (!GetWorld()) return;

	auto Weapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);

	if (!Weapon) return;
	
	const auto RusCharacter = Cast<ARusCharacter>(GetOwner());

	if (!RusCharacter) return;

	const auto WeaponSocket = RusCharacter->GetMesh1P()->GetSocketByName(WeaponEquipSocketName);
	
	if (WeaponSocket)
	{
		WeaponSocket->AttachActor(Weapon, RusCharacter->GetMesh1P());
	}

	Weapon->SetOwner(RusCharacter);

	CurrentWeapon = Weapon;
	
}

