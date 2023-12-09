// Fill out your copyright notice in the Description page of Project Settings.


#include "RusCharacterAnimInstance.h"

#include "BaseWeapon.h"
#include "RusCharacter.h"
#include "WeaponComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void URusCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	RusCharacter = Cast<ARusCharacter>(GetOwningActor());
}

void URusCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!RusCharacter)
	{
		 RusCharacter = Cast<ARusCharacter>(GetOwningActor());
	}
	if (RusCharacter)
	{
		Speed = RusCharacter->GetVelocity().Length();
		if (const auto CharacterMovementComponent = RusCharacter->GetCharacterMovement())
		{
			bIsInAir = CharacterMovementComponent->IsFalling();
			bIsAccelerating = CharacterMovementComponent->GetCurrentAcceleration().Length() > 0.0f;
		}

		if (const auto WeaponComponent = RusCharacter->GetComponentByClass<UWeaponComponent>())
		{
			Weapon = WeaponComponent->GetCurrentWeapon();
		}

		if (Weapon && Weapon->GetWeaponMesh() && RusCharacter->GetMesh1P())
		{
			LeftHandTransform = Weapon->GetWeaponMesh()->GetSocketTransform("LeftHandSocket", RTS_World);
			FVector OutPosition;
			FRotator OutRotation;

			RusCharacter->GetMesh1P()->TransformToBoneSpace(FName("hand_r"), LeftHandTransform.GetLocation(), FRotator::ZeroRotator, OutPosition, OutRotation);
			LeftHandTransform.SetLocation(OutPosition);
			LeftHandTransform.SetRotation(FQuat(OutRotation));
		}
	}

	
}
