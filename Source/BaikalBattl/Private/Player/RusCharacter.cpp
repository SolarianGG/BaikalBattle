// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RusCharacter.h"
#include "EnhancedInputComponent.h"
#include "HealthComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/WeaponComponent.h"
#include "GameFramework/DamageType.h"
#include "Engine/DamageEvents.h"



ARusCharacter::ARusCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent");
}

void ARusCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARusCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ARusCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerPitchInput(-LookAxisVector.Y);
		AddControllerYawInput(LookAxisVector.X);
	}
}

void ARusCharacter::TestFeature(const FInputActionValue& Value)
{
	TakeDamage(5.0f, FPointDamageEvent{}, GetController(), this);
}

void ARusCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (const auto EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
		EnhancedInput->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::Jump);
		EnhancedInput->BindAction(FireAction, ETriggerEvent::Started, WeaponComponent, &UWeaponComponent::Fire);
		EnhancedInput->BindAction(AlternativeFireAction, ETriggerEvent::Started, WeaponComponent, &UWeaponComponent::AlternativeFire);
		EnhancedInput->BindAction(TestAction, ETriggerEvent::Started, this, &ThisClass::TestFeature);
	}
}

