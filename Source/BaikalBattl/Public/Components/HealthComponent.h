// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChangedDelegate, int);

DECLARE_MULTICAST_DELEGATE(FOnDeathDelegate);

DEFINE_LOG_CATEGORY_STATIC(LogRusHealthComponent, All, All);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BAIKALBATTL_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	FOnHealthChangedDelegate OnHealthChanged;

	FOnDeathDelegate OnDeathDelegate;

	FORCEINLINE float GetHealth() const { return Health; }

	bool IsDead() const;

	bool IsFullHealth() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float MaxHealth = 100.f;

	virtual void BeginPlay() override;

private:
	void SetHealth(float NewHealth);

	float Health = 0.f;

	UFUNCTION()
	void OnTakeAnyDamageHandle(AActor* DamagedActor, float Damage, const class UDamageType* DamageType,
	                           class AController* InstigatedBy, AActor* DamageCauser);
	UFUNCTION()
	void OnTakeRadialDamageHandle(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, FVector Origin, const FHitResult& HitInfo, class AController* InstigatedBy, AActor* DamageCauser);
	UFUNCTION()
	void OnTakePointDamageHandle(AActor* DamagedActor, float Damage, class AController* InstigatedBy, FVector HitLocation, class UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const class UDamageType* DamageType, AActor* DamageCauser);

	void ApplyDamage(float Damage);
};
