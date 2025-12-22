// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinanceFrenzyGameMode.h"
#include "FinanceFrenzyGameState.h"
#include "FinanceFrenzyPlayerController.h"

AFinanceFrenzyGameMode::AFinanceFrenzyGameMode()
{
	// Enable ticking for this actor
	PrimaryActorTick.bCanEverTick = true;

	// Set default game state and player controller classes
	GameStateClass = AFinanceFrenzyGameState::StaticClass();
	PlayerControllerClass = AFinanceFrenzyPlayerController::StaticClass();

	// Set default game settings
	DayDuration = 1.0f; // 1 second = 1 day
	TotalGameDays = 7300; // 20 years
	StartingCash = 2000.0f;
	DayTimer = 0.0f;
}

void AFinanceFrenzyGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Initialize game state
	if (AFinanceFrenzyGameState* FFGameState = GetGameState<AFinanceFrenzyGameState>())
	{
		FFGameState->InitializeGame(StartingCash, TotalGameDays);
	}
}

void AFinanceFrenzyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DayTimer += DeltaTime;

	// Progress day when timer exceeds day duration
	if (DayTimer >= DayDuration)
	{
		DayTimer = 0.0f;
		
		if (AFinanceFrenzyGameState* FFGameState = GetGameState<AFinanceFrenzyGameState>())
		{
			FFGameState->ProgressDay();
		}
	}
}
