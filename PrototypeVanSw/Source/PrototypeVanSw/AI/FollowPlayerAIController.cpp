// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowPlayerAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


AFollowPlayerAIController::AFollowPlayerAIController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Active = true;
}

// Called when the game starts or when spawned
void AFollowPlayerAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFollowPlayerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Active)
	{
		APawn* P0 = UGameplayStatics::GetPlayerPawn(this, 0);
		if (P0)
		{
			FVector Dest = P0->GetActorLocation();
			APawn* P1 = UGameplayStatics::GetPlayerPawn(this, 1);
			APawn* OwnerPawn = GetPawn();
			if (P1 && (FVector::Dist(OwnerPawn->GetActorLocation(), P0->GetActorLocation()) > FVector::Dist(OwnerPawn->GetActorLocation(), P1->GetActorLocation())))
			{
				Dest = P1->GetActorLocation();
			}
			MoveToLocation(Dest);
		}
	}
}

void AFollowPlayerAIController::SetActive(bool _Active)
{
	Active = _Active;
}

