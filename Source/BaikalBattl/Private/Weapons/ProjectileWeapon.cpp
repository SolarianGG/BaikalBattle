// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/ProjectileWeapon.h"

#include "Projectile.h"

void AProjectileWeapon::Fire()
{
	Super::Fire();

	if (!GetWorld())
	{
		return;
	}
    
	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd)) return;

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);
	
	const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;

	const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();
	
	const FTransform SpawnTransform(Direction.Rotation(), GetMuzzleWorldLocation());
	AProjectile* Projectile = GetWorld()->SpawnActorDeferred<AProjectile>(ProjectileClass, SpawnTransform);
	if (Projectile)
	{
		Projectile->SetInstigator(Cast<APawn>(GetOwner()));
		Projectile->SetOwner(GetOwner());
		Projectile->FinishSpawning(SpawnTransform);
	}
}
