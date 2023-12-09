// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "ProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class BAIKALBATTL_API AProjectileWeapon : public ABaseWeapon
{
	GENERATED_BODY()

public:
	virtual void Fire() override;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	TSubclassOf<AActor> ProjectileClass;
};
