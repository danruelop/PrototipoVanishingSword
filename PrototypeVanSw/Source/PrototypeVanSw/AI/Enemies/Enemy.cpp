// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AEnemy::AEnemy()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Beaten = false;
	Dying = false;

	Dead = false;
	FadeOutOffset = 0;
	FadeOutInitialPosZ = 0;
	FadeOutSpeed = 0;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitialHealth = Health;

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Dead)
	{
		SetActorLocation(GetActorLocation() - (FVector::UpVector * FadeOutSpeed * DeltaTime));
		if (GetActorLocation().Z < (FadeOutInitialPosZ - FadeOutOffset))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Destroyed"));
			Destroy();
		}
	}
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemy::Damage(int32 Damage)
{
	Health -= Damage;
	Beaten = true;
}

void AEnemy::SetFadeOutDestroy(float Offset, float Speed)
{
	Dead = true;
	FadeOutOffset = Offset;
	FadeOutInitialPosZ = GetActorLocation().Z;
	FadeOutSpeed = Speed;
}

void AEnemy::DeactivateCharacterMovementComponent()
{
	UCharacterMovementComponent* CharacterMovementComponent = Cast<UCharacterMovementComponent>(GetComponentsByTag(UCharacterMovementComponent::StaticClass(), "CharacterMovementComponent")[0]);
	if (CharacterMovementComponent)
	{
		CharacterMovementComponent->Deactivate();
	}
}

void AEnemy::SetBeaten(bool _Beaten)
{
	Beaten = _Beaten;
}

void AEnemy::SetDying(bool _Dying)
{
	if (_Dying && (!Dying))
	{
		Beaten = false;
		DeactivateCharacterMovementComponent();
		DisableCollision();
		DyingEnemyDelegate.Broadcast();
	}
	Dying = _Dying;
}

void AEnemy::DisableCollision()
{
	SetActorEnableCollision(false);
}
