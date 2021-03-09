// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProximityAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTOTYPEVANSW_API UProximityAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Attacking;

protected:
	float TimeSinceLastAttack;

public:
	// Sets default values for this component's properties
	UProximityAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void ResetTimeSinceLastAttack();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		bool DistanceAbleToAttack();

	UFUNCTION(BlueprintCallable)
		bool DistanceInRange();

	UFUNCTION(BlueprintCallable)
		bool TimeAbleToAttack();

	UFUNCTION(BlueprintCallable)
		void HitPlayer();

};
