// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Components/ProximityAttackComponent.h"
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
		ProximityAttackComponent->HitPlayer();
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
/*
void HitPlayer()
{
	if (DistanceInRange())
	{
		AMainCharacter* MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
		if (MainCharacter)
		{
			MainCharacter->Damage(Damage);
		}
	}
}
*/
