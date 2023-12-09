// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Projectile.h"

#include "RusCharacter.h"
#include "Components/BoxComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>("CollisionComponent");
	CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->SetCollisionResponseToAllChannels(ECR_Block);
	SetRootComponent(CollisionComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");

	MeshComponent->SetupAttachment(CollisionComponent);
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->InitialSpeed = 15000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->ProjectileGravityScale = 8.f;

}
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	if (CollisionComponent)
	{
		CollisionComponent->IgnoreActorWhenMoving(GetOwner(), true);
		CollisionComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnProjectileHit);
		SetLifeSpan(NumberOfSecondsOnFly);
	}
	

	
}

void AProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (!GetWorld()) { return; }

	DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 32.0f, 16, FColor::Red, false, 5.0f);
	
	ProjectileMovementComponent->StopMovementImmediately();

	AActor* EnemyActor = Hit.GetActor();

	if (EnemyActor)
	{
		FPointDamageEvent PointDamageEvent;
		PointDamageEvent.HitInfo = Hit;
		const auto Controller = Cast<APawn>(GetOwner())->GetController();
		EnemyActor->TakeDamage(BulletDamage, PointDamageEvent, Controller, this);
	}

	Destroy();
}


