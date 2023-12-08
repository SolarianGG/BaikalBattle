// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


class ABaseWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BAIKALBATTL_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	void Fire();

	void AlternativeFire();
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapons")
	TSubclassOf<ABaseWeapon> Weapon;
	
	virtual void BeginPlay() override;

	void InitializeWeapons();

private:
	UPROPERTY()
	ABaseWeapon* CurrentWeapon;
};
