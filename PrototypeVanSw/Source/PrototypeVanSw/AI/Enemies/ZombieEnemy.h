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
		AActor* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRate;

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

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void HitPlayer();

	UFUNCTION(BlueprintCallable)
		bool DistanceAbleToAttack();

	UFUNCTION(BlueprintCallable)
		bool DistanceInRange();

	UFUNCTION(BlueprintCallable)
		bool TimeAbleToAttack();

protected:
	void SetAIActive(bool Active);

	void SetCharacterMovementComponentSpeed(float Speed);

	void ResetTimeSinceLastAttack();

};
