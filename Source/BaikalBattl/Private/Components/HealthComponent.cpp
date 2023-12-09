// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Actor.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	
}

bool UHealthComponent::IsDead() const
{
	return Health <= 0.0f;
}

bool UHealthComponent::IsFullHealth() const
{
	return FMath::IsNearlyEqual(Health, MaxHealth);
}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	
	SetHealth(MaxHealth);

	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &ThisClass::OnTakeAnyDamageHandle);
		Owner->OnTakeRadialDamage.AddDynamic(this, &ThisClass::OnTakeRadialDamageHandle);
		Owner->OnTakePointDamage.AddDynamic(this, &ThisClass::OnTakePointDamageHandle);
	}
}

void UHealthComponent::SetHealth(float NewHealth)
{
	Health = NewHealth;

	OnHealthChanged.Broadcast(Health);
}

void UHealthComponent::OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogRusHealthComponent, Display, TEXT("On any damage: %f"), Damage);
}

void UHealthComponent::OnTakeRadialDamageHandle(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	FVector Origin, const FHitResult& HitInfo, AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogRusHealthComponent, Display, TEXT("On radial damage: %f"), Damage);
	ApplyDamage(Damage);
}

void UHealthComponent::OnTakePointDamageHandle(AActor* DamagedActor, float Damage, AController* InstigatedBy,
	FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
	const UDamageType* DamageType, AActor* DamageCauser)
{
	UE_LOG(LogRusHealthComponent, Display, TEXT("On point damage: %f"), Damage);
	ApplyDamage(Damage);
}

void UHealthComponent::ApplyDamage(float Damage)
{
	if (Damage <= 0.0f || IsDead() || !GetWorld())
	{
		return;
	}

	SetHealth(Health-Damage);
	if (IsDead())
	{
		OnDeathDelegate.Broadcast();
	}
}
