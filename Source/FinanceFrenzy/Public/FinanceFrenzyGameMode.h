// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FinanceFrenzyGameMode.generated.h"

/**
 * Main Game Mode for Finance Frenzy
 * Manages the overall game flow and rules
 */
UCLASS()
class FINANCEFRENZY_API AFinanceFrenzyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFinanceFrenzyGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	/** Time dilation for game progression (1 day = X seconds) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	float DayDuration;

	/** Total game duration in days (default: 20 years = 7300 days) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	int32 TotalGameDays;

	/** Starting cash for the player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Settings")
	float StartingCash;

private:
	float DayTimer;
};
