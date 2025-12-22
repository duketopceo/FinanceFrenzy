// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinanceFrenzyGameState.h"
#include "Net/UnrealNetwork.h"

AFinanceFrenzyGameState::AFinanceFrenzyGameState()
{
	CurrentDay = 0;
	TotalGameDays = 7300;
	CurrentCash = 0.0f;
	InterestRate = 0.0f;
	InflationRate = 0.0f;
}

void AFinanceFrenzyGameState::InitializeGame(float StartingCash, int32 TotalDays)
{
	CurrentDay = 0;
	TotalGameDays = TotalDays;
	CurrentCash = StartingCash;
	InterestRate = 0.0f;
	InflationRate = 0.0f;

	// Clear all arrays
	StockHoldings.Empty();
	Assets.Empty();
	Liabilities.Empty();
	CashflowHistory.Empty();

	// Add initial cashflow
	FCashflowData InitialCashflow;
	InitialCashflow.Amount = StartingCash;
	InitialCashflow.Description = TEXT("Starting Capital");
	InitialCashflow.bIsIncome = true;
	InitialCashflow.Date = FDateTime::Now();
	CashflowHistory.Add(InitialCashflow);

	UpdateMarketRates();
}

void AFinanceFrenzyGameState::ProgressDay()
{
	CurrentDay++;

	// Check if game is over
	if (CurrentDay >= TotalGameDays)
	{
		// Game Over - trigger end game logic
		UE_LOG(LogTemp, Warning, TEXT("Game Over! Final Net Worth: $%.2f"), CurrentCash);
		return;
	}

	UpdateMarketRates();
}

void AFinanceFrenzyGameState::ModifyCash(float Amount)
{
	CurrentCash += Amount;
}

bool AFinanceFrenzyGameState::BuyStock(const FString& SectorName, int32 Quantity, float Price)
{
	float TotalCost = Quantity * Price;

	if (CurrentCash < TotalCost)
	{
		UE_LOG(LogTemp, Warning, TEXT("Insufficient funds to buy stock"));
		return false;
	}

	// Deduct cash
	ModifyCash(-TotalCost);

	// Find existing stock or add new
	FStockData* ExistingStock = StockHoldings.FindByPredicate([&SectorName](const FStockData& Stock)
	{
		return Stock.SectorName == SectorName;
	});

	if (ExistingStock)
	{
		// Update existing stock - calculate weighted average price
		float TotalValue = (ExistingStock->Quantity * ExistingStock->Price) + TotalCost;
		int32 TotalQuantity = ExistingStock->Quantity + Quantity;
		ExistingStock->Price = TotalValue / TotalQuantity;
		ExistingStock->Quantity = TotalQuantity;
	}
	else
	{
		// Add new stock
		FStockData NewStock;
		NewStock.SectorName = SectorName;
		NewStock.Price = Price;
		NewStock.Quantity = Quantity;
		NewStock.PurchaseDate = FDateTime::Now();
		StockHoldings.Add(NewStock);
	}

	// Add cashflow entry
	FCashflowData Cashflow;
	Cashflow.Amount = -TotalCost;
	Cashflow.Description = FString::Printf(TEXT("Bought %d shares of %s"), Quantity, *SectorName);
	Cashflow.bIsIncome = false;
	Cashflow.Date = FDateTime::Now();
	AddCashflow(Cashflow);

	return true;
}

bool AFinanceFrenzyGameState::SellStock(const FString& SectorName, int32 Quantity, float Price)
{
	FStockData* ExistingStock = StockHoldings.FindByPredicate([&SectorName](const FStockData& Stock)
	{
		return Stock.SectorName == SectorName;
	});

	if (!ExistingStock || ExistingStock->Quantity < Quantity)
	{
		UE_LOG(LogTemp, Warning, TEXT("Insufficient stock to sell"));
		return false;
	}

	float TotalValue = Quantity * Price;

	// Add cash
	ModifyCash(TotalValue);

	// Update stock quantity
	ExistingStock->Quantity -= Quantity;

	// Remove stock if quantity is 0
	if (ExistingStock->Quantity == 0)
	{
		StockHoldings.RemoveAll([&SectorName](const FStockData& Stock)
		{
			return Stock.SectorName == SectorName;
		});
	}

	// Add cashflow entry
	FCashflowData Cashflow;
	Cashflow.Amount = TotalValue;
	Cashflow.Description = FString::Printf(TEXT("Sold %d shares of %s"), Quantity, *SectorName);
	Cashflow.bIsIncome = true;
	Cashflow.Date = FDateTime::Now();
	AddCashflow(Cashflow);

	return true;
}

void AFinanceFrenzyGameState::AddCashflow(const FCashflowData& Cashflow)
{
	CashflowHistory.Add(Cashflow);
}

FString AFinanceFrenzyGameState::GetCurrentNews() const
{
	if (NewsEventsDataTable)
	{
		TArray<FNewsEvent*> AllNews;
		NewsEventsDataTable->GetAllRows<FNewsEvent>(TEXT("GetCurrentNews"), AllNews);

		for (FNewsEvent* News : AllNews)
		{
			if (News && News->Day == CurrentDay)
			{
				return News->Headline;
			}
		}
	}

	return TEXT("No news today");
}

void AFinanceFrenzyGameState::UpdateMarketRates()
{
	// Update interest rate from data table
	if (InterestRateDataTable)
	{
		FString RowName = FString::Printf(TEXT("Day%d"), CurrentDay);
		FMarketHistoricalData* RateData = InterestRateDataTable->FindRow<FMarketHistoricalData>(FName(*RowName), TEXT("UpdateMarketRates"));
		if (RateData)
		{
			InterestRate = RateData->Price;
		}
	}

	// Update inflation rate from data table
	if (InflationDataTable)
	{
		FString RowName = FString::Printf(TEXT("Day%d"), CurrentDay);
		FMarketHistoricalData* RateData = InflationDataTable->FindRow<FMarketHistoricalData>(FName(*RowName), TEXT("UpdateMarketRates"));
		if (RateData)
		{
			InflationRate = RateData->Price;
		}
	}
}

void AFinanceFrenzyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFinanceFrenzyGameState, CurrentDay);
	DOREPLIFETIME(AFinanceFrenzyGameState, CurrentCash);
	DOREPLIFETIME(AFinanceFrenzyGameState, InterestRate);
	DOREPLIFETIME(AFinanceFrenzyGameState, InflationRate);
}
