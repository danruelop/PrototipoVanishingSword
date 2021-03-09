// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Components/ProximityAttackComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../FollowPlayerAIController.h"


// Called when the game starts or when spawned
void AZombieEnemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AZombieEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health <= 0)
	{
		SetDying(true);
	}

	UProximityAttackComponent* ProximityAttackComponent = Cast<UProximityAttackComponent>(GetComponentsByTag(UProximityAttackComponent::StaticClass(), "ProximityAttackComponent")[0]);
	if (ProximityAttackComponent)
	{
		Attacking = ((Health > 0) && (ProximityAttackComponent->Attacking));
		bool Active = (!ProximityAttackComponent->DistanceAbleToAttack()) && (!Beaten) && (!Attacking) && (!Dying);
		SetAIActive(Active);
		Speed = (Active ? MaxSpeed : 0);
		SetCharacterMovementComponentSpeed(Speed);
	}

	SetBeaten(Beaten);
}

void AZombieEnemy::Hit()
{
	UProximityAttackComponent* ProximityAttackComponent = Cast<UProximityAttackComponent>(GetComponentsByTag(UProximityAttackComponent::StaticClass(), "ProximityAttackComponent")[0]);
	if (ProximityAttackComponent)
	{
		ProximityAttackComponent->Hit();
	}
}

void AZombieEnemy::SetAIActive(bool Active)
{
	AFollowPlayerAIController* FollowPlayerAIController = Cast<AFollowPlayerAIController>(GetController());
	if (FollowPlayerAIController)
	{
		FollowPlayerAIController->SetActive(Active);
	}
}

void AZombieEnemy::SetCharacterMovementComponentSpeed(float _Speed)
{
	UCharacterMovementComponent* CharacterMovementComponent = Cast<UCharacterMovementComponent>(GetComponentsByTag(UCharacterMovementComponent::StaticClass(), "CharacterMovementComponent")[0]);
	if (CharacterMovementComponent)
	{
		CharacterMovementComponent->MaxWalkSpeed = _Speed;
	}
}

void AZombieEnemy::SetBeaten(bool _Beaten)
{
	Beaten = (_Beaten && (!Attacking));
}

void AZombieEnemy::SetAttacking(bool _Attacking)
{
	UProximityAttackComponent* ProximityAttackComponent = Cast<UProximityAttackComponent>(GetComponentsByTag(UProximityAttackComponent::StaticClass(), "ProximityAttackComponent")[0]);
	if (ProximityAttackComponent)
	{
		ProximityAttackComponent->Attacking = _Attacking;
	}
}
