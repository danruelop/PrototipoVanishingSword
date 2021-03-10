// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../FollowPlayerAIController.h"
#include "Kismet/GameplayStatics.h"


// Called when the game starts or when spawned
void AZombieEnemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AZombieEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceLastAttack += DeltaTime;
	if (TimeAbleToAttack() && DistanceAbleToAttack())
	{
		ResetTimeSinceLastAttack();
		Attacking = true;
	}

	if (Health <= 0)
	{
		SetDying(true);
	}


	APawn* P0 = UGameplayStatics::GetPlayerPawn(this, 0);
	if (P0)
	{
		Target = P0;
		APawn* P1 = UGameplayStatics::GetPlayerPawn(this, 1);
		if (P1 && (FVector::Dist(GetActorLocation(), P0->GetActorLocation()) > FVector::Dist(GetActorLocation(), P1->GetActorLocation())))
		{
			Target = P1;
		}
	}

	Attacking = ((Health > 0) && (Attacking));
	bool Active = (!DistanceAbleToAttack()) && (!Beaten) && (!Attacking) && (!Dying);
	SetAIActive(Active);
	Speed = (Active ? MaxSpeed : 0);
	SetCharacterMovementComponentSpeed(Speed);

	SetBeaten(Beaten);
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

	GetCharacterMovement()->MaxWalkSpeed = _Speed;
}

void AZombieEnemy::SetBeaten(bool _Beaten)
{
	Beaten = (_Beaten && (!Attacking));
}

void AZombieEnemy::SetAttacking(bool _Attacking)
{
	Attacking = _Attacking;
}

bool AZombieEnemy::DistanceAbleToAttack()
{
	return (FVector::Dist(GetActorLocation(), Target->GetActorLocation()) < AttackDistance);
}

bool AZombieEnemy::DistanceInRange()
{
	return (FVector::Dist(GetActorLocation(), Target->GetActorLocation()) < AttackRange);
}

bool AZombieEnemy::TimeAbleToAttack()
{
	return (TimeSinceLastAttack > AttackRate);
}

void AZombieEnemy::ResetTimeSinceLastAttack()
{
	TimeSinceLastAttack = 0;
}
