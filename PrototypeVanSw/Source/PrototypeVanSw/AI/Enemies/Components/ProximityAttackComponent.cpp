// Fill out your copyright notice in the Description page of Project Settings.


#include "ProximityAttackComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PrototypeVanSw/AI/Enemies/ZombieEnemy.h"
//#include "../../Characters/MainCharacter.h"


// Sets default values for this component's properties
UProximityAttackComponent::UProximityAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ResetTimeSinceLastAttack();
	Attacking = false;
}


// Called when the game starts
void UProximityAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UProximityAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TimeSinceLastAttack += DeltaTime;
	if (TimeAbleToAttack() && DistanceAbleToAttack())
	{
		ResetTimeSinceLastAttack();
		Attacking = true;
	}
}

bool UProximityAttackComponent::DistanceAbleToAttack()
{
	AZombieEnemy* Enemy = Cast<AZombieEnemy>(GetOwner());
	return (Enemy && (FVector::Dist(GetOwner()->GetActorLocation(), Enemy->Target->GetActorLocation()) < AttackDistance));
}

bool UProximityAttackComponent::DistanceInRange()
{
	AZombieEnemy* Enemy = Cast<AZombieEnemy>(GetOwner());
	return (Enemy && (FVector::Dist(GetOwner()->GetActorLocation(), Enemy->Target->GetActorLocation()) < AttackRange));
}

bool UProximityAttackComponent::TimeAbleToAttack()
{
	return (TimeSinceLastAttack > AttackRate);
}

void UProximityAttackComponent::ResetTimeSinceLastAttack()
{
	TimeSinceLastAttack = 0;
}
