// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class BAIKALBATTL_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();

	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh() const { return WeaponMesh; }
	
	virtual void Fire();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Animation")
	UAnimMontage* FireAnimMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Weapon")
	float TraceMaxDistance = 1500.0f;
	
	virtual void BeginPlay() override;

	virtual void MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);
	
	virtual FVector GetMuzzleWorldLocation() const;

	virtual FVector GetMuzzleWorldDirection() const;

	virtual bool GetPlayerViewpoint(FVector& ViewLocation, FRotator& ViewRotation) const;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;
	

	

};
