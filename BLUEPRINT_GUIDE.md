# Blueprint Development Guide

This guide explains how to work with the C++ classes in Blueprints for Finance Frenzy.

## Core Blueprint Classes

### 1. GameMode Blueprint (BP_FinanceFrenzyGameMode)

**Parent Class**: `AFinanceFrenzyGameMode` (C++)

**Purpose**: Controls game rules and flow

**Key Properties**:
- `Day Duration` (float): Seconds per game day (default: 1.0)
- `Total Game Days` (int): Total days in game (default: 7300)
- `Starting Cash` (float): Initial player money (default: 2000.0)

**How to Create**:
1. Content Browser → Blueprints folder
2. Right-click → Blueprint Class
3. Search for "FinanceFrenzyGameMode"
4. Name it `BP_FinanceFrenzyGameMode`

### 2. GameState Blueprint (BP_FinanceFrenzyGameState)

**Parent Class**: `AFinanceFrenzyGameState` (C++)

**Purpose**: Stores game state and player data

**Key Functions** (Blueprint Callable):
- `Get Current Day`: Returns current game day
- `Get Current Cash`: Returns player's cash
- `Get Interest Rate`: Returns current interest rate
- `Get Inflation Rate`: Returns current inflation rate
- `Modify Cash`: Add/subtract money
- `Buy Stock`: Purchase stocks
- `Sell Stock`: Sell stocks
- `Get Stock Holdings`: Returns array of player's stocks
- `Get Current News`: Returns news for today
- `Add Cashflow`: Record a transaction

**Data Tables to Assign**:
- Interest Rate Data Table
- Inflation Data Table
- News Events Data Table

**How to Create**:
1. Content Browser → Blueprints folder
2. Right-click → Blueprint Class
3. Search for "FinanceFrenzyGameState"
4. Name it `BP_FinanceFrenzyGameState`
5. Open and assign data tables in the Details panel

### 3. PlayerController Blueprint (BP_FinanceFrenzyPlayerController)

**Parent Class**: `AFinanceFrenzyPlayerController` (C++)

**Purpose**: Handles player input and UI

**Key Functions**:
- `Open Stock Exchange`: Opens stock trading UI
- `Open Assets`: Opens asset management UI
- `Open Liabilities`: Opens liability management UI
- `Open Cashflows`: Opens cashflow tracker UI

**Widget Classes to Assign**:
- Main HUD Widget Class
- Stock Exchange Widget Class
- Assets Widget Class
- Liabilities Widget Class
- Cashflows Widget Class

**How to Create**:
1. Content Browser → Blueprints folder
2. Right-click → Blueprint Class
3. Search for "FinanceFrenzyPlayerController"
4. Name it `BP_FinanceFrenzyPlayerController`
5. Assign widget classes in the Details panel

## Data Structures (Blueprints)

### FStockData
- Sector Name (String)
- Price (Float)
- Quantity (Integer)
- Purchase Date (DateTime)

### FMarketHistoricalData
- Date (DateTime)
- Price (Float)
- Open (Float)
- High (Float)
- Low (Float)

### FNewsEvent
- Headline (String)
- Day (Integer)
- Description (String)

### FAssetData
- Asset Name (String)
- Value (Float)
- Quantity (Integer)

### FLiabilityData
- Liability Name (String)
- Amount (Float)
- Interest Rate (Float)
- Due Date (DateTime)

### FCashflowData
- Date (DateTime)
- Amount (Float)
- Description (String)
- Is Income (Boolean)

## Widget Blueprint Examples

### Main HUD Widget (WBP_MainHUD)

**Widgets to Add**:
```
Canvas Panel
├── Text Block: Date (bound to GameState->GetCurrentDay)
├── Text Block: Cash (bound to GameState->GetCurrentCash)
├── Text Block: Interest Rate (bound to GameState->GetInterestRate)
├── Text Block: Inflation Rate (bound to GameState->GetInflationRate)
├── Text Block: News Headline (bound to GameState->GetCurrentNews)
├── Button: Stock Exchange (OnClicked → PlayerController->OpenStockExchange)
├── Button: Assets (OnClicked → PlayerController->OpenAssets)
├── Button: Liabilities (OnClicked → PlayerController->OpenLiabilities)
└── Button: Cashflows (OnClicked → PlayerController->OpenCashflows)
```

**Event Graph**:
```
Event Construct
└── Get Owning Player
    └── Cast to FinanceFrenzyPlayerController
        └── Store as variable

Event Tick
└── Update all text blocks with current game state values
```

### Stock Exchange Widget (WBP_StockExchange)

**Widgets to Add**:
```
Canvas Panel
├── List View: Available Stocks
├── Text Box: Quantity Input
├── Button: Buy
├── Button: Sell
└── Button: Close
```

**Event Graph**:
```
Event Construct
└── Get Game State
    └── Load stock sectors and prices

Buy Button Clicked
└── Get Game State
    └── Call Buy Stock
        └── Refresh UI

Sell Button Clicked
└── Get Game State
    └── Call Sell Stock
        └── Refresh UI
```

## Data Table Creation

### 1. Create Data Table Asset

1. Content Browser → Data folder
2. Right-click → Miscellaneous → Data Table
3. Select row structure (e.g., MarketHistoricalData)
4. Name it (e.g., `DT_InterestRates`)

### 2. Import CSV Data

1. Open the Data Table
2. Click "Import" button
3. Select CSV file from `data/` folder
4. Verify data imported correctly

### 3. Row Naming Convention

For time-series data:
- Use format: `Day0`, `Day1`, `Day2`, etc.
- Matches game day progression

### 4. Assign to GameState

1. Open `BP_FinanceFrenzyGameState`
2. In Details panel, find data table properties
3. Assign your created data tables

## Blueprint Communication Patterns

### Getting Game State from Widget

```
Get Owning Player
└── Get Game State
    └── Cast to FinanceFrenzyGameState
        └── Call functions or get variables
```

### Calling Player Controller Functions

```
Get Owning Player
└── Cast to FinanceFrenzyPlayerController
    └── Call Open[Widget] function
```

### Displaying Dynamic Data

Use **Bindings** in Widget Blueprint:
1. Select Text Block in Designer
2. In Details, click "Bind" next to Text property
3. Create function that returns the value
4. Mark function as "Pure"

## Best Practices

1. **Always cast safely**: Check if cast succeeded before using
2. **Cache references**: Store frequently-used references as variables
3. **Use events**: Trigger UI updates with events from GameState
4. **Validate input**: Check player has enough money before transactions
5. **Clear feedback**: Show success/failure messages to player
6. **Performance**: Don't update UI every tick if not necessary

## Example Blueprint Logic

### Buy Stock Button Click

```
Event: OnBuyButtonClicked
├── Get Quantity from Input Box
├── Get Selected Stock from List
├── Get Current Price for Stock
├── Calculate Total Cost
├── Get Game State
│   └── Check if Current Cash >= Total Cost
│       ├── TRUE:
│       │   └── Call Buy Stock
│       │       └── Show Success Message
│       │       └── Refresh Stock List
│       └── FALSE:
│           └── Show "Insufficient Funds" Message
```

### Update Cash Display (Every Frame)

```
Event: Tick
└── Get Game State
    └── Get Current Cash
        └── Format as Currency String
            └── Set Text Block
```

## Testing in Editor

1. **Play In Editor (PIE)**: Alt+P
2. **Simulate**: Alt+S (for testing without player control)
3. **Debug**: Add Print String nodes to see values
4. **Breakpoints**: Use Blueprint debugger (F9 on nodes)

## Common Issues

### "Access None" Errors
- Game State not initialized yet
- Cast failed
- Solution: Add null checks

### Data Not Loading
- Data table not assigned
- Row name mismatch
- Solution: Verify data table paths and row names

### UI Not Showing
- Widget not added to viewport
- Z-order issues
- Solution: Check AddToViewport call and widget hierarchy

## Resources

- [UE5 Blueprint Documentation](https://docs.unrealengine.com/5.3/en-US/blueprints-visual-scripting-in-unreal-engine/)
- [UMG UI Designer](https://docs.unrealengine.com/5.3/en-US/umg-ui-designer-for-unreal-engine/)
- [Data Tables](https://docs.unrealengine.com/5.3/en-US/data-driven-gameplay-elements-in-unreal-engine/)

---

Happy Blueprint-ing! Remember: The C++ classes provide the logic, Blueprints make it accessible and customizable.
