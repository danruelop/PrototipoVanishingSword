// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrototypeVanSwGameMode.h"
#include "PrototypeVanSwCharacter.h"
#include "UObject/ConstructorHelpers.h"

APrototypeVanSwGameMode::APrototypeVanSwGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Code/Player/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
