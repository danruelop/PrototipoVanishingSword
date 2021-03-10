// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrototypeVanSwGameMode.h"
#include "PrototypeVanSwCharacter.h"
#include "UObject/ConstructorHelpers.h"

APrototypeVanSwGameMode::APrototypeVanSwGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
