// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinanceFrenzyPlayerController.h"
#include "Blueprint/UserWidget.h"

AFinanceFrenzyPlayerController::AFinanceFrenzyPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void AFinanceFrenzyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	CreateMainHUD();
}

void AFinanceFrenzyPlayerController::CreateMainHUD()
{
	if (MainHUDClass)
	{
		MainHUDWidget = CreateWidget<UUserWidget>(this, MainHUDClass);
		if (MainHUDWidget)
		{
			MainHUDWidget->AddToViewport();
		}
	}
}

void AFinanceFrenzyPlayerController::OpenStockExchange()
{
	if (StockExchangeWidgetClass)
	{
		UUserWidget* StockExchangeWidget = CreateWidget<UUserWidget>(this, StockExchangeWidgetClass);
		if (StockExchangeWidget)
		{
			StockExchangeWidget->AddToViewport();
		}
	}
}

void AFinanceFrenzyPlayerController::OpenAssets()
{
	if (AssetsWidgetClass)
	{
		UUserWidget* AssetsWidget = CreateWidget<UUserWidget>(this, AssetsWidgetClass);
		if (AssetsWidget)
		{
			AssetsWidget->AddToViewport();
		}
	}
}

void AFinanceFrenzyPlayerController::OpenLiabilities()
{
	if (LiabilitiesWidgetClass)
	{
		UUserWidget* LiabilitiesWidget = CreateWidget<UUserWidget>(this, LiabilitiesWidgetClass);
		if (LiabilitiesWidget)
		{
			LiabilitiesWidget->AddToViewport();
		}
	}
}

void AFinanceFrenzyPlayerController::OpenCashflows()
{
	if (CashflowsWidgetClass)
	{
		UUserWidget* CashflowsWidget = CreateWidget<UUserWidget>(this, CashflowsWidgetClass);
		if (CashflowsWidget)
		{
			CashflowsWidget->AddToViewport();
		}
	}
}
