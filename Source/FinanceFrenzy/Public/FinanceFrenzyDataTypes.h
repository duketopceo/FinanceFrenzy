// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FinanceFrenzyDataTypes.generated.h"

/**
 * Stock data structure representing a market sector
 */
USTRUCT(BlueprintType)
struct FStockData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stock")
	FString SectorName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stock")
	float Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stock")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stock")
	FDateTime PurchaseDate;

	FStockData()
		: SectorName(TEXT("")),
		  Price(0.0f),
		  Quantity(0),
		  PurchaseDate(FDateTime::Now())
	{}
};

/**
 * Historical market data for a specific day
 */
USTRUCT(BlueprintType)
struct FMarketHistoricalData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	FDateTime Date;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	float Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	float Open;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	float High;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	float Low;

	FMarketHistoricalData()
		: Date(FDateTime::Now()),
		  Price(0.0f),
		  Open(0.0f),
		  High(0.0f),
		  Low(0.0f)
	{}
};

/**
 * News event data structure
 */
USTRUCT(BlueprintType)
struct FNewsEvent : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "News")
	FString Headline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "News")
	int32 Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "News")
	FString Description;

	FNewsEvent()
		: Headline(TEXT("")),
		  Day(0),
		  Description(TEXT(""))
	{}
};

/**
 * Asset data structure
 */
USTRUCT(BlueprintType)
struct FAssetData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Asset")
	FString AssetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Asset")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Asset")
	int32 Quantity;

	FAssetData()
		: AssetName(TEXT("")),
		  Value(0.0f),
		  Quantity(0)
	{}
};

/**
 * Liability data structure
 */
USTRUCT(BlueprintType)
struct FLiabilityData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liability")
	FString LiabilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liability")
	float Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liability")
	float InterestRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Liability")
	FDateTime DueDate;

	FLiabilityData()
		: LiabilityName(TEXT("")),
		  Amount(0.0f),
		  InterestRate(0.0f),
		  DueDate(FDateTime::Now())
	{}
};

/**
 * Cashflow data structure
 */
USTRUCT(BlueprintType)
struct FCashflowData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cashflow")
	FDateTime Date;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cashflow")
	float Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cashflow")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cashflow")
	bool bIsIncome;

	FCashflowData()
		: Date(FDateTime::Now()),
		  Amount(0.0f),
		  Description(TEXT("")),
		  bIsIncome(true)
	{}
};
