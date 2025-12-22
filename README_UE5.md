# Finance Frenzy - Unreal Engine 5

<img src="https://challengepost-s3-challengepost.netdna-ssl.com/photos/production/software_thumbnail_photos/001/568/048/datas/medium.jpg"/>

> Hydrangea Hacks 2021 Finance Hack and Top 6 Winner - **Now rebuilt for Unreal Engine 5!**

## Overview

Finance Frenzy is a financial simulation game that teaches players about market conditions and financial decision-making. This UE5 version provides enhanced graphics, performance, and expanded gameplay features while maintaining the educational core of the original.

## Features

- **Real Historical Data**: Uses actual stock prices, interest rates, and inflation data from 2000-2020
- **Dynamic Market Simulation**: Experience realistic market conditions and economic cycles
- **Portfolio Management**: Buy and sell stocks across 11 major market sectors
- **Financial Planning**: Manage assets, liabilities, and track cashflows
- **Educational Gameplay**: Learn about market relationships, wealth management, and financial decision-making
- **20-Year Campaign**: Play through 20 years of market history (7,300 game days)

## Unreal Engine 5 Requirements

### Engine Version
- **Unreal Engine 5.3** or later

### Platform Support
- Windows 10/11 (64-bit)
- macOS 12.0 or later
- Linux (Ubuntu 20.04 LTS or later)

### Development Requirements

#### Windows
- Visual Studio 2022 (Community, Professional, or Enterprise)
- Windows 10/11 SDK
- .NET 6.0 SDK
- 8GB RAM minimum (16GB recommended)
- 100GB free disk space

#### macOS
- Xcode 14.0 or later
- macOS 12.0 (Monterey) or later
- 8GB RAM minimum (16GB recommended)
- 100GB free disk space

#### Linux
- GCC 11.0 or Clang 13.0
- 8GB RAM minimum (16GB recommended)
- 100GB free disk space

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/duketopceo/FinanceFrenzy.git
cd FinanceFrenzy
```

### 2. Generate Project Files

#### Windows
Right-click on `FinanceFrenzy.uproject` and select "Generate Visual Studio project files"

Or via command line:
```cmd
"%ProgramFiles%\Epic Games\UE_5.3\Engine\Build\BatchFiles\Build.bat" -projectfiles -project="%cd%\FinanceFrenzy.uproject" -game -engine
```

#### macOS
Right-click on `FinanceFrenzy.uproject` and select "Generate Xcode project"

Or via command line:
```bash
/Users/Shared/Epic Games/UE_5.3/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh -project="$(pwd)/FinanceFrenzy.uproject" -game -engine
```

#### Linux
```bash
/home/user/UnrealEngine/Engine/Build/BatchFiles/Linux/GenerateProjectFiles.sh -project="$(pwd)/FinanceFrenzy.uproject" -game -engine
```

### 3. Build the Project

#### Windows (Visual Studio)
1. Open `FinanceFrenzy.sln`
2. Set the build configuration to "Development Editor"
3. Build the solution (Ctrl+Shift+B)

Or via command line:
```cmd
"%ProgramFiles%\Epic Games\UE_5.3\Engine\Build\BatchFiles\Build.bat" FinanceFrenzyEditor Win64 Development -project="%cd%\FinanceFrenzy.uproject"
```

#### macOS (Xcode)
1. Open `FinanceFrenzy.xcworkspace`
2. Select "FinanceFrenzyEditor" scheme
3. Build (Cmd+B)

Or via command line:
```bash
/Users/Shared/Epic\ Games/UE_5.3/Engine/Build/BatchFiles/Mac/Build.sh FinanceFrenzyEditor Mac Development "$(pwd)/FinanceFrenzy.uproject"
```

#### Linux
```bash
/home/user/UnrealEngine/Engine/Build/BatchFiles/Linux/Build.sh FinanceFrenzyEditor Linux Development "$(pwd)/FinanceFrenzy.uproject"
```

### 4. Open the Project in Unreal Editor

#### Windows
```cmd
"%ProgramFiles%\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe" "%cd%\FinanceFrenzy.uproject"
```

#### macOS
```bash
/Users/Shared/Epic\ Games/UE_5.3/Engine/Binaries/Mac/UnrealEditor.app/Contents/MacOS/UnrealEditor "$(pwd)/FinanceFrenzy.uproject"
```

#### Linux
```bash
/home/user/UnrealEngine/Engine/Binaries/Linux/UnrealEditor "$(pwd)/FinanceFrenzy.uproject"
```

Or simply double-click `FinanceFrenzy.uproject` on Windows/macOS.

## Project Structure

```
FinanceFrenzy/
├── Config/                      # Unreal Engine configuration files
│   ├── DefaultEngine.ini
│   ├── DefaultGame.ini
│   ├── DefaultInput.ini
│   └── DefaultEditor.ini
├── Content/                     # Game assets and blueprints
│   ├── Maps/                    # Level files
│   ├── UI/                      # User interface widgets
│   ├── Data/                    # Data tables and assets
│   ├── Blueprints/              # Blueprint classes
│   ├── Materials/               # Material assets
│   └── Textures/                # Texture assets
├── Source/                      # C++ source code
│   ├── FinanceFrenzy/           # Main game module
│   │   ├── Public/              # Public header files
│   │   │   ├── FinanceFrenzy.h
│   │   │   ├── FinanceFrenzyGameMode.h
│   │   │   ├── FinanceFrenzyGameState.h
│   │   │   ├── FinanceFrenzyPlayerController.h
│   │   │   └── FinanceFrenzyDataTypes.h
│   │   ├── Private/             # Implementation files
│   │   │   ├── FinanceFrenzy.cpp
│   │   │   ├── FinanceFrenzyGameMode.cpp
│   │   │   ├── FinanceFrenzyGameState.cpp
│   │   │   └── FinanceFrenzyPlayerController.cpp
│   │   └── FinanceFrenzy.Build.cs
│   ├── FinanceFrenzy.Target.cs
│   └── FinanceFrenzyEditor.Target.cs
├── Legacy/                      # Original Python implementation
│   └── Python/                  # PyQt6 version (for reference)
├── data/                        # Historical market data (CSV files)
├── assets/                      # Original image assets
├── FinanceFrenzy.uproject       # Unreal project file
└── README.md                    # This file
```

## Development Guide

### Core Systems

#### Game State Management
The `AFinanceFrenzyGameState` class manages:
- Current game day and time progression
- Player's cash and financial holdings
- Market interest and inflation rates
- Stock portfolio
- Assets and liabilities
- Cashflow history

#### Player Controller
The `AFinanceFrenzyPlayerController` handles:
- UI management and navigation
- Player input
- Opening/closing game menus

#### Data Types
Custom data structures (`FinanceFrenzyDataTypes.h`):
- `FStockData` - Stock holdings
- `FMarketHistoricalData` - Historical market data
- `FNewsEvent` - News events
- `FAssetData` - Player assets
- `FLiabilityData` - Player liabilities
- `FCashflowData` - Cashflow entries

### Creating Game Content

#### 1. Import Historical Data
1. Create Data Tables in the Content Browser
2. Use the CSV import feature to import data from the `data/` folder
3. Assign data tables to the GameState blueprint

#### 2. Design UI Widgets
Create UMG widgets for:
- Main HUD (displays date, cash, rates, news)
- Stock Exchange dialog
- Assets management
- Liabilities management
- Cashflows tracking
- Game Over screen

#### 3. Create Game Levels
- **MainMenu**: Title screen and game options
- **GameLevel**: Main gameplay level

### Building for Distribution

#### Package the Game

1. In Unreal Editor: File → Package Project → Select Platform
2. Choose output directory
3. Wait for packaging to complete

#### Shipping Configuration

Edit `Config/DefaultGame.ini` to configure:
- Compression settings
- Localization
- Platform-specific settings

## Extending the Game

### Adding New Stock Sectors

1. Add historical data CSV to `data/` folder
2. Import as Data Table
3. Update UI to display new sector
4. Add sector to `AFinanceFrenzyGameState`

### Adding Game Events

1. Create new `FNewsEvent` entries in NewsEventsDataTable
2. Optionally add gameplay effects in `AFinanceFrenzyGameState::ProgressDay()`

### Custom Financial Instruments

1. Define new data structure in `FinanceFrenzyDataTypes.h`
2. Add management functions to `AFinanceFrenzyGameState`
3. Create UI for trading/managing the instrument

## Troubleshooting

### Build Errors

**"Cannot find UnrealEngine installation"**
- Ensure UE5.3 is properly installed
- Verify engine association in `FinanceFrenzy.uproject`

**"Missing module: FinanceFrenzy"**
- Regenerate project files
- Rebuild the solution

**"Plugin 'Bridge' failed to load"**
- Update the plugin or disable it in `FinanceFrenzy.uproject`

### Runtime Issues

**Black screen on launch**
- Check that default maps are set in `Config/DefaultEngine.ini`
- Ensure MainMenu map exists in `Content/Maps/`

**Data tables not loading**
- Verify CSV data format matches struct definition
- Check data table paths in GameState blueprint

## Original Python Version

The original Python/PyQt6 implementation is preserved in the `Legacy/Python/` directory for reference. See `Legacy/Python/README.md` for instructions on running the Python version.

## Contributing

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## Credits

### Original Team
- Hydrangea Hacks 2021 Finance Hack Team
- See original Devpost: https://devpost.com/software/finance-frenzy/

### UE5 Port
- Adapted for Unreal Engine 5.3
- Enhanced with modern game engine features

## License

Copyright © 2024 Finance Frenzy Team. All rights reserved.

## Inspiration & Educational Value

This project aims to improve financial literacy by providing an interactive, engaging way to learn about:
- Stock market dynamics
- Interest rates and inflation
- Portfolio management
- Risk assessment
- Long-term financial planning

Perfect for:
- Students learning economics and finance
- Individuals wanting to understand investing
- Educational institutions teaching financial literacy
- Anyone interested in market simulation games

## What's Next

Future enhancements planned:
- Multiplayer competitive mode
- More complex financial instruments (options, bonds, futures)
- Real-time market integration
- VR support
- Mobile platform support
- Advanced analytics and reporting
- Difficulty levels (Easy/Normal/Hard)
- Challenge modes with specific goals
- Achievement system
- Leaderboards

## Support

For issues, questions, or contributions, please visit:
- GitHub Issues: https://github.com/duketopceo/FinanceFrenzy/issues
- Original Devpost: https://devpost.com/software/finance-frenzy/

---

**Remember:** This is a simulation for educational purposes. Always consult with financial professionals for real investment decisions.
