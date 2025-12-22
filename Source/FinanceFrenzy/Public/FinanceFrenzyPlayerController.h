// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FinanceFrenzyPlayerController.generated.h"

/**
 * Player Controller for Finance Frenzy
 * Handles player input and UI interactions
 */
UCLASS()
class FINANCEFRENZY_API AFinanceFrenzyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AFinanceFrenzyPlayerController();

	virtual void BeginPlay() override;

	/** Open the stock exchange UI */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void OpenStockExchange();

	/** Open the assets UI */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void OpenAssets();

	/** Open the liabilities UI */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void OpenLiabilities();

	/** Open the cashflows UI */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void OpenCashflows();

protected:
	/** Main HUD widget class */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MainHUDClass;

	/** Stock Exchange widget class */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> StockExchangeWidgetClass;

	/** Assets widget class */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> AssetsWidgetClass;

	/** Liabilities widget class */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> LiabilitiesWidgetClass;

	/** Cashflows widget class */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UUserWidget> CashflowsWidgetClass;

	/** Current main HUD widget */
	UPROPERTY()
	class UUserWidget* MainHUDWidget;

private:
	void CreateMainHUD();
};
