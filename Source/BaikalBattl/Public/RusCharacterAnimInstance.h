// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RusCharacterAnimInstance.generated.h"

class ABaseWeapon;
class ARusCharacter;
/**
 * 
 */
UCLASS()
class BAIKALBATTL_API URusCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly, Category="Character")
	ARusCharacter* RusCharacter;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsAccelerating;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FTransform LeftHandTransform;

	UPROPERTY()
	ABaseWeapon* Weapon;
};
