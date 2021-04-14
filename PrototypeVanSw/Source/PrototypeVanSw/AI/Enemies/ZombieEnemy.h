// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "ZombieEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPEVANSW_API AZombieEnemy : public AEnemy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxSpeed;

	UPROPERTY(BlueprintReadOnly)
		bool Attacking;

	UPROPERTY(BlueprintReadOnly)
		bool AttackingCharged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int ChargedAttackProbability;
	
	UPROPERTY(BlueprintReadOnly)
		AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DistanceToStartAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackChargedRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float StunTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TimeStunned;

protected:
	float TimeSinceLastAttack;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetBeaten(bool _Beaten) override;

	UFUNCTION(BlueprintCallable)
		void SetAttacking(bool _Attacking);

	UFUNCTION(BlueprintCallable)
		void SetAttackingCharged(bool _AttackingCharged);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void HitPlayer();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void HitArea();

	UFUNCTION(BlueprintCallable)
		bool DistanceAbleToAttack();

	UFUNCTION(BlueprintCallable)
		bool TimeAbleToAttack();

	UFUNCTION(BlueprintCallable)
		void Stun();

protected:
	void SetAIActive(bool Active);

	void SetCharacterMovementComponentSpeed(float Speed);

	void ResetTimeSinceLastAttack();

};
