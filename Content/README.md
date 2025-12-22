# Content Directory

This directory contains all Unreal Engine 5 assets for Finance Frenzy.

## Structure

- **Maps**: Level files for the game
  - MainMenu.umap - Main menu level
  - GameLevel.umap - Main game level
  
- **UI**: User interface widgets and assets
  - MainHUD - Main game HUD
  - StockExchange - Stock trading interface
  - Assets - Asset management UI
  - Liabilities - Liability management UI
  - Cashflows - Cashflow tracking UI
  - GameOver - End game summary screen

- **Data**: Data tables and assets
  - StockData - Historical stock price data tables
  - InterestRates - Historical interest rate data
  - InflationRates - Historical inflation rate data
  - NewsEvents - News event data for game progression

- **Blueprints**: Blueprint classes and logic
  - GameMode - Game mode blueprints
  - UI - UI widget blueprints
  - Actors - Game actor blueprints

- **Materials**: Material assets for UI and game objects

- **Textures**: Texture assets and images
  - Import the existing PNG files from the assets folder here

## Asset Creation Guide

### Data Tables

1. Create Data Tables based on the C++ structs:
   - FMarketHistoricalData for stock/interest/inflation data
   - FNewsEvent for news events

2. Import CSV data from the `data` folder using UE5's data table CSV import

### UI Widgets

Create UMG widgets for each UI screen:
- Main HUD displaying date, cash, interest/inflation rates
- Stock Exchange dialog for buying/selling stocks
- Assets/Liabilities/Cashflows management screens

## Notes

- All UE5 binary assets (`.uasset`, `.umap`) should be committed to version control
- Source assets (PSDs, FBXs) can optionally be stored in a separate folder
