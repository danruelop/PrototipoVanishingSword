// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDyingEnemyDelegate);

UCLASS()
class PROTOTYPEVANSW_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
		FDyingEnemyDelegate DyingEnemyDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 InitialHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Dificulty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Beaten;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Dying;

private:
	bool Dead;
	float FadeOutOffset;
	float FadeOutInitialPosZ;
	float FadeOutSpeed;

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DeactivateCharacterMovementComponent();

	void DisableCollision();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void Damage(int32 Damage);

	UFUNCTION(BlueprintCallable)
		void SetFadeOutDestroy(float Offset, float Speed);

	UFUNCTION(BlueprintCallable)
		virtual void SetBeaten(bool _Beaten);

	UFUNCTION(BlueprintCallable)
		virtual void SetDying(bool _Dying);
};