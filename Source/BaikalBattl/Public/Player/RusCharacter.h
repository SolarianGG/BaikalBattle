// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RusCharacter.generated.h"

class UWeaponComponent;
class UCameraComponent;
class UHealthComponent;
class UInputAction;
struct FInputActionValue;
class UAnimMontage;

UCLASS()
class BAIKALBATTL_API ARusCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARusCharacter();

	FORCEINLINE USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(VisibleAnywhere, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UHealthComponent* HealthComponent;
	
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* TestAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Animation")
	UAnimMontage* FireAnimMontage;
	
	virtual void BeginPlay() override;

private:
	void Move(const FInputActionValue& Value);
	
	void Look(const FInputActionValue& Value);

	void TestFeature(const FInputActionValue& Value);

	void Fire(const FInputActionValue& Value);

	void AlternativeFire(const FInputActionValue& Value);

	void OnDeath();
};
