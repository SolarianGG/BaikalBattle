// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/BaseWeapon.h"

#include "GameFramework/Character.h"

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
}

void ABaseWeapon::Fire()
{
	if (FireAnimMontage)
	{
		WeaponMesh->PlayAnimation(FireAnimMontage, false);	
	}
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseWeapon::MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd)
{
	if (!GetWorld())
	{
		return;
	}
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	CollisionParams.bReturnPhysicalMaterial = true;

	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, CollisionParams);
}

FVector ABaseWeapon::GetMuzzleWorldLocation() const
{
	return WeaponMesh->GetSocketLocation(MuzzleSocketName);
}

FVector ABaseWeapon::GetMuzzleWorldDirection() const
{
	return WeaponMesh->GetSocketTransform(MuzzleSocketName).GetRotation().GetForwardVector();
}

bool ABaseWeapon::GetPlayerViewpoint(FVector& ViewLocation, FRotator& ViewRotation) const
{
	const auto RusCharacter = Cast<ACharacter>(GetOwner());
	if (!RusCharacter) return false;

	if (RusCharacter->IsPlayerControlled())
	{
		const auto Controller = RusCharacter->GetController<APlayerController>();

		if (!Controller)
		{
			return false;
		}

		Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
	}
	else
	{
		ViewLocation = GetMuzzleWorldLocation();
		ViewRotation = WeaponMesh->GetSocketRotation(MuzzleSocketName);
	}
    
	return true;
}

bool ABaseWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewLocation;
	FRotator ViewRotation;
	if (!GetPlayerViewpoint(ViewLocation, ViewRotation))
	{
		return false;
	}
	TraceStart = ViewLocation;
	const FVector ShootDirection = ViewRotation.Vector();
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	return true;
}

