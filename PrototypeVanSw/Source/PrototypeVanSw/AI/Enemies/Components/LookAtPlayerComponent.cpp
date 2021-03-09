// Fill out your copyright notice in the Description page of Project Settings.


#include "LookAtPlayerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
ULookAtPlayerComponent::ULookAtPlayerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Active = true;
}


// Called when the game starts
void ULookAtPlayerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void ULookAtPlayerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Active)
	{
		FRotator Rotator = FRotator::ZeroRotator;
		Rotator.Yaw = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation()).Yaw;
		GetOwner()->SetActorRotation(Rotator);
	}
}

