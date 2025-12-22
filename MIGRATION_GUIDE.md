# Migration Guide: Python to Unreal Engine 5

This guide helps developers familiar with the Python/PyQt6 version understand how the concepts translate to the UE5 implementation.

## Architecture Comparison

### Python Version (PyQt6)
```
app.py (main)
├── Window class (QWidget)
├── Stock data (pandas DataFrames)
├── Game state (class variables)
└── UI dialogs (separate files)
    ├── stock_exchange.py
    ├── assets.py
    ├── liabilities.py
    └── cashflows.py
```

### UE5 Version (C++/Blueprints)
```
FinanceFrenzy.uproject
├── GameMode (game rules & flow)
├── GameState (replicated game data)
├── PlayerController (input & UI management)
├── Data Structures (C++ structs)
└── UI Widgets (UMG)
    ├── WBP_MainHUD
    ├── WBP_StockExchange
    ├── WBP_Assets
    ├── WBP_Liabilities
    └── WBP_Cashflows
```

## Concept Mapping

### Main Game Window → GameMode + GameState + Main HUD

**Python (app.py)**:
```python
class Window(QWidget):
    def __init__(self):
        self.day = 0
        self.cash = 2000
        self.timer = QTimer()
        self.timer.timeout.connect(self.a_day_has_passed)
```

**UE5 (C++)**:
```cpp
// GameMode handles timing
class AFinanceFrenzyGameMode : public AGameModeBase {
    float DayDuration = 1.0f;
    void Tick(float DeltaTime) override;
};

// GameState stores data
class AFinanceFrenzyGameState : public AGameStateBase {
    int32 CurrentDay = 0;
    float CurrentCash = 2000.0f;
    void ProgressDay();
};
```

### CSV Data Loading → Data Tables

**Python**:
```python
self.consumer_dis_data = pd.read_csv("./data/SP-500-Consumer-Discretionary-Historical-Data.csv")
self.inflation_data = pd.read_csv("./data/Inflation.csv")
```

**UE5**:
```cpp
// C++ - Define structure
USTRUCT(BlueprintType)
struct FMarketHistoricalData : public FTableRowBase {
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Price;
    // ...
};

// GameState - Reference data table
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
UDataTable* InflationDataTable;

// Usage
FMarketHistoricalData* RateData = InflationDataTable->FindRow<FMarketHistoricalData>(
    FName(*RowName), TEXT("Context")
);
```

**In Editor**: Import CSV → Data Table asset

### Stock Trading → GameState Functions

**Python**:
```python
def buy_stock(self):
    cost = quantity * price
    if self.cash >= cost:
        self.cash -= cost
        self.stocks.append(stock_data)
```

**UE5 (C++)**:
```cpp
bool AFinanceFrenzyGameState::BuyStock(
    const FString& SectorName, 
    int32 Quantity, 
    float Price
) {
    float TotalCost = Quantity * Price;
    if (CurrentCash < TotalCost) return false;
    
    ModifyCash(-TotalCost);
    StockHoldings.Add(NewStock);
    return true;
}
```

**In Blueprint**: Call `BuyStock` function from UI widget

### Dialog Windows → UMG Widgets

**Python (stock_exchange.py)**:
```python
class StockExchangeDialog(QDialog):
    def __init__(self, app):
        super().__init__()
        self.setupUi()
        self.buy_button.clicked.connect(self.buy_stock)
```

**UE5 (Blueprint Widget)**:
```
WBP_StockExchange (UMG Widget)
├── Canvas Panel
│   ├── List View (stocks)
│   ├── Text Box (quantity)
│   └── Button (Buy)
│       └── OnClicked → BuyStock logic
```

### Timer Events → Tick / Timer Manager

**Python**:
```python
self.timer = QTimer()
self.timer.setInterval(1000)  # 1 second
self.timer.timeout.connect(self.a_day_has_passed)
self.timer.start()
```

**UE5 (C++)**:
```cpp
// In GameMode
void AFinanceFrenzyGameMode::Tick(float DeltaTime) {
    DayTimer += DeltaTime;
    if (DayTimer >= DayDuration) {
        DayTimer = 0.0f;
        GameState->ProgressDay();
    }
}
```

Or use Timer Manager:
```cpp
GetWorld()->GetTimerManager().SetTimer(
    TimerHandle, 
    this, 
    &AFinanceFrenzyGameMode::OnDayPassed, 
    DayDuration, 
    true  // loop
);
```

### UI Updates → Data Binding

**Python**:
```python
def set_cash(self):
    self.cash_lbl.setText(f"Cash: ${self.cash:.2f}")
```

**UE5 (Blueprint Widget)**:
```
Text Block "Cash Display"
└── Text Binding
    └── Get Game State → Get Current Cash → Format as Currency
```

## Key Differences

### 1. Separation of Concerns

**Python**: Everything in one class
```python
class Window(QWidget):
    # Game logic
    # UI
    # Data
    # Timer
```

**UE5**: Separated by responsibility
- **GameMode**: Rules and flow
- **GameState**: Data (replicated for multiplayer)
- **PlayerController**: Input and UI management
- **Widgets**: UI only

### 2. Data Persistence

**Python**: Class variables
```python
self.cash = 2000
self.stocks = []
```

**UE5**: Replicated properties
```cpp
UPROPERTY(BlueprintReadOnly, Replicated)
float CurrentCash;

UPROPERTY(BlueprintReadOnly)
TArray<FStockData> StockHoldings;
```

### 3. UI Framework

**Python**: Qt Widgets
- Widget tree in code
- Signals and slots
- Immediate mode

**UE5**: UMG (Unreal Motion Graphics)
- Visual designer
- Event graph
- Retained mode
- Hardware accelerated

### 4. Asset Management

**Python**: File paths
```python
QIcon("./assets/star.png")
```

**UE5**: Content Browser references
```cpp
UPROPERTY(EditDefaultsOnly)
UTexture2D* StarIcon;
```

In Blueprint: Assign via dropdown in editor

### 5. Threading Model

**Python**: Single-threaded with QTimer
```python
self.timer.timeout.connect(self.callback)
```

**UE5**: Game thread with tick
```cpp
void Tick(float DeltaTime) override;
```

## Feature Parity Checklist

| Feature | Python | UE5 | Status |
|---------|--------|-----|--------|
| Day progression | ✅ | ✅ | Implemented |
| Cash management | ✅ | ✅ | Implemented |
| Stock trading | ✅ | ✅ | Implemented |
| Interest rates | ✅ | ✅ | Implemented |
| Inflation rates | ✅ | ✅ | Implemented |
| News events | ✅ | ✅ | Implemented |
| Stock portfolio | ✅ | ✅ | Implemented |
| Cashflow history | ✅ | ✅ | Implemented |
| UI - Main HUD | ✅ | ⏳ | Blueprint needed |
| UI - Stock Exchange | ✅ | ⏳ | Blueprint needed |
| UI - Assets | ✅ | ⏳ | Blueprint needed |
| UI - Liabilities | ✅ | ⏳ | Blueprint needed |
| UI - Cashflows | ✅ | ⏳ | Blueprint needed |
| UI - Game Over | ✅ | ⏳ | Blueprint needed |
| Save/Load | ❌ | ⏳ | To be added |
| High Scores | ❌ | ⏳ | To be added |

✅ = Complete | ⏳ = In Progress | ❌ = Not Implemented

## Migration Steps for Developers

### If you want to extend the Python version:
1. Python code is in `Legacy/Python/`
2. Requires: `pip install PyQt6 pandas`
3. Run: `python Legacy/Python/app.py`

### If you want to work on the UE5 version:
1. Install UE5.3
2. Run setup script: `./Scripts/setup.sh` or `Scripts\setup.bat`
3. Open `FinanceFrenzy.uproject`
4. Build in Visual Studio/Xcode
5. Create blueprint widgets (see `POST_SETUP_CHECKLIST.md`)

## Common Tasks

### Adding a New Stock Sector

**Python**:
```python
# In __init__
self.new_sector_data = pd.read_csv("./data/NewSector.csv")

# In UI
# Add to stock list
```

**UE5**:
```cpp
// 1. Import CSV as Data Table in Content Browser
// 2. No code changes needed
// 3. UI widget automatically shows new sector from data table
```

### Changing Starting Cash

**Python**:
```python
# In Window.__init__
self.cash = 5000  # Changed from 2000
```

**UE5**:
```cpp
// In BP_FinanceFrenzyGameMode (Blueprint)
Starting Cash = 5000  // Edit in Details panel
```

### Adding New UI Elements

**Python**:
```python
# In Window class
self.new_label = QLabel("Text", self)
self.new_label.setGeometry(x, y, w, h)
```

**UE5**:
```
// In WBP_MainHUD (UMG Widget)
1. Open widget in UMG designer
2. Drag Text Block from palette
3. Position visually
4. Bind to data source
```

## Performance Considerations

### Python Version
- Single-threaded
- Limited to ~60 FPS (Qt event loop)
- CSV parsing on load
- Memory: ~50-100 MB

### UE5 Version
- Multi-threaded engine
- 60+ FPS (configurable)
- Data tables cached in memory
- Memory: ~200-500 MB (includes engine overhead)
- Benefits: Hardware acceleration, better scaling

## Testing

### Python
```bash
# Run directly
python app.py

# No automated tests in original
```

### UE5
```bash
# Play in Editor (PIE)
Alt+P in Unreal Editor

# Automation tests (to be added)
# In C++ or Blueprint
```

## Debugging

### Python
```python
print(f"Cash: {self.cash}")  # Console output
```

### UE5
```cpp
UE_LOG(LogTemp, Warning, TEXT("Cash: %.2f"), CurrentCash);
```

Or in Blueprint: Add "Print String" node

## Best Practices

### When porting Python features to UE5:

1. **Separate concerns**: Don't put everything in GameMode
2. **Use data tables**: Better than hardcoding data
3. **Blueprint-friendly**: Expose functions with `UFUNCTION(BlueprintCallable)`
4. **Document types**: Use `UPROPERTY()` macros properly
5. **Test incrementally**: Build and test each feature
6. **Replicate data**: Mark networked data with `Replicated`
7. **Optimize UI updates**: Don't update every frame unless needed

## Resources

- **Python Code**: `Legacy/Python/`
- **UE5 Code**: `Source/FinanceFrenzy/`
- **Documentation**: 
  - `README_UE5.md` - Setup
  - `BLUEPRINT_GUIDE.md` - Blueprints
  - `BUILD.md` - Building
  - `CONTRIBUTING.md` - Contributing

## Questions?

Open an issue on GitHub with the "question" label.

---

Happy migrating! 🚀
