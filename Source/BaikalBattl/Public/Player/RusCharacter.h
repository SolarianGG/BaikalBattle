// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RusCharacter.generated.h"

class UWeaponComponent;
class UCameraComponent;

class UInputAction;
struct FInputActionValue;

UCLASS()
class BAIKALBATTL_API ARusCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARusCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(VisibleAnywhere, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UWeaponComponent* WeaponComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* MouseLookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* FireAction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* AlternativeFireAction;

	
	virtual void BeginPlay() override;

private:
	void Move(const FInputActionValue& Value);
	
	void Look(const FInputActionValue& Value);
};
