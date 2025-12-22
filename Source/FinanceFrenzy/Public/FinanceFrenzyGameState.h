// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FinanceFrenzyDataTypes.h"
#include "Engine/DataTable.h"
#include "FinanceFrenzyGameState.generated.h"

/**
 * Game State for Finance Frenzy
 * Manages the current state of the game including player finances, market data, and time
 */
UCLASS()
class FINANCEFRENZY_API AFinanceFrenzyGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AFinanceFrenzyGameState();

	/** Initialize the game with starting parameters */
	UFUNCTION(BlueprintCallable, Category = "Game State")
	void InitializeGame(float StartingCash, int32 TotalDays);

	/** Progress the game by one day */
	UFUNCTION(BlueprintCallable, Category = "Game State")
	void ProgressDay();

	/** Get current day */
	UFUNCTION(BlueprintPure, Category = "Game State")
	int32 GetCurrentDay() const { return CurrentDay; }

	/** Get current cash */
	UFUNCTION(BlueprintPure, Category = "Game State")
	float GetCurrentCash() const { return CurrentCash; }

	/** Add/subtract cash */
	UFUNCTION(BlueprintCallable, Category = "Game State")
	void ModifyCash(float Amount);

	/** Get current interest rate */
	UFUNCTION(BlueprintPure, Category = "Game State")
	float GetInterestRate() const { return InterestRate; }

	/** Get current inflation rate */
	UFUNCTION(BlueprintPure, Category = "Game State")
	float GetInflationRate() const { return InflationRate; }

	/** Buy stock */
	UFUNCTION(BlueprintCallable, Category = "Game State")
	bool BuyStock(const FString& SectorName, int32 Quantity, float Price);

	/** Sell stock */
	UFUNCTION(BlueprintCallable, Category = "Game State")
	bool SellStock(const FString& SectorName, int32 Quantity, float Price);

	/** Get player's stock holdings */
	UFUNCTION(BlueprintPure, Category = "Game State")
	TArray<FStockData> GetStockHoldings() const { return StockHoldings; }

	/** Add cashflow entry */
	UFUNCTION(BlueprintCallable, Category = "Game State")
	void AddCashflow(const FCashflowData& Cashflow);

	/** Get news for current day */
	UFUNCTION(BlueprintPure, Category = "Game State")
	FString GetCurrentNews() const;

protected:
	/** Current game day (0-7299 for 20 years) */
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Game State")
	int32 CurrentDay;

	/** Total game days */
	UPROPERTY(BlueprintReadOnly, Category = "Game State")
	int32 TotalGameDays;

	/** Player's current cash */
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Game State")
	float CurrentCash;

	/** Current interest rate */
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Game State")
	float InterestRate;

	/** Current inflation rate */
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Game State")
	float InflationRate;

	/** Player's stock holdings */
	UPROPERTY(BlueprintReadOnly, Category = "Game State")
	TArray<FStockData> StockHoldings;

	/** Player's assets */
	UPROPERTY(BlueprintReadOnly, Category = "Game State")
	TArray<FAssetData> Assets;

	/** Player's liabilities */
	UPROPERTY(BlueprintReadOnly, Category = "Game State")
	TArray<FLiabilityData> Liabilities;

	/** Player's cashflow history */
	UPROPERTY(BlueprintReadOnly, Category = "Game State")
	TArray<FCashflowData> CashflowHistory;

	/** Data tables for historical market data */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
	UDataTable* InterestRateDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
	UDataTable* InflationDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Data")
	UDataTable* NewsEventsDataTable;

	/** Update market rates for current day */
	void UpdateMarketRates();

	/** Get property replication list */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
