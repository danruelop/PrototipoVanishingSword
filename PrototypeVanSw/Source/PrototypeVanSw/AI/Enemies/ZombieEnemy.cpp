// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../FollowPlayerAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"


// Called when the game starts or when spawned
void AZombieEnemy::BeginPlay()
{
	Super::BeginPlay();

	TimeSinceLastAttack = AttackRate;
	TimeStunned = 0;
}

// Called every frame
void AZombieEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health <= 0)
	{
		SetDying(true);
	}

	if (TimeStunned >= 0)
	{
		SetCharacterMovementComponentSpeed(0);
		TimeStunned -= DeltaTime;
	}
	else
	{
		TimeSinceLastAttack += DeltaTime;
		if (TimeAbleToAttack() && DistanceAbleToAttack())
		{
			ResetTimeSinceLastAttack();
			if ((Health >= (InitialHealth / 2)) && (FMath::RandRange(0, 100) <= ChargedAttackProbability))
			{
				AttackingCharged = true;
			}
			else
			{
				Attacking = true;
			}
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
		AttackingCharged = ((Health > 0) && (AttackingCharged));
		bool Active = (!DistanceAbleToAttack() && (!Beaten) && (!Attacking) && (!AttackingCharged) && (!Dying));
		SetAIActive(Active);
		Speed = (Active ? MaxSpeed : 0);
		SetCharacterMovementComponentSpeed(Speed);
	}

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

void AZombieEnemy::SetAttackingCharged(bool _AttackingCharged)
{
	AttackingCharged = _AttackingCharged;
}

bool AZombieEnemy::DistanceAbleToAttack()
{
	if (Target)
	{
		return (FVector::Dist(GetActorLocation(), Target->GetActorLocation()) < DistanceToStartAttack);
	}
	return false;
}

bool AZombieEnemy::TimeAbleToAttack()
{
	return (TimeSinceLastAttack > AttackRate);
}

void AZombieEnemy::ResetTimeSinceLastAttack()
{
	TimeSinceLastAttack = 0;
}

void AZombieEnemy::Stun()
{
	TimeStunned = StunTime;
}
