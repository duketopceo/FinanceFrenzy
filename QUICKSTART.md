# Finance Frenzy - Quick Start Guide (Unreal Engine 5)

## Prerequisites Checklist

- [ ] Unreal Engine 5.3 installed
- [ ] Visual Studio 2022 (Windows) or Xcode 14+ (Mac) or GCC/Clang (Linux)
- [ ] 16GB RAM available
- [ ] 100GB free disk space

## 5-Minute Setup

### Step 1: Open the Project
1. Navigate to the cloned repository
2. Double-click `FinanceFrenzy.uproject`
3. If prompted, select "Yes" to rebuild modules

### Step 2: First-Time Setup
1. Wait for shader compilation (this may take 10-15 minutes)
2. The editor will open to the default level

### Step 3: Create Initial Content

#### Create the Main Menu Level
1. File → New Level → Empty Level
2. Save as `Content/Maps/MainMenu`

#### Create the Game Level
1. File → New Level → Basic
2. Save as `Content/Maps/GameLevel`

#### Set Default Maps
1. Edit → Project Settings → Maps & Modes
2. Set Editor Startup Map: `MainMenu`
3. Set Game Default Map: `MainMenu`

### Step 4: Create Basic UI

#### Main HUD Widget
1. Content Browser → Right-click → User Interface → Widget Blueprint
2. Name it `WBP_MainHUD`
3. Add text blocks for:
   - Current Date
   - Cash Amount
   - Interest Rate
   - Inflation Rate
   - News Headline
4. Add buttons for:
   - Stock Exchange
   - Assets
   - Liabilities
   - Cashflows

#### Test the Game
1. Click Play (Alt+P)
2. The game should start with the main HUD visible

## Project Setup Complete!

Your Unreal Engine 5 Finance Frenzy project is now ready for development.

## Next Steps

1. **Import Historical Data**
   - Create Data Tables from CSV files in `data/` folder
   - Link to GameState in blueprints

2. **Build Out UI**
   - Create stock exchange widget
   - Create asset/liability management widgets
   - Create cashflow tracking widget
   - Create game over summary widget

3. **Configure GameMode**
   - Open MainMenu level
   - World Settings → GameMode Override → FinanceFrenzyGameMode
   - Configure starting values

4. **Test Gameplay**
   - Play through a few game days
   - Test stock trading
   - Verify data is loading correctly

## Common First-Time Issues

### "Module out of date"
- Right-click .uproject → Generate Visual Studio project files
- Rebuild in Visual Studio

### "Cannot open project"
- Verify UE5.3 is installed
- Check engine association in .uproject file

### Slow Editor Performance
- Close unnecessary background applications
- Ensure GPU drivers are up to date
- Consider reducing viewport quality (Settings → Engine Scalability)

## Development Workflow

1. **Code Changes**: Make changes in Visual Studio/Xcode
2. **Hot Reload**: Use Hot Reload in UE5 editor (Ctrl+Alt+F11)
3. **Blueprint Changes**: Edit directly in UE5 editor
4. **Test**: Use PIE (Play In Editor) frequently
5. **Package**: File → Package Project when ready to test standalone

## Documentation Resources

- Full README: `README_UE5.md`
- Content Guide: `Content/README.md`
- Legacy Python: `Legacy/Python/README.md`
- Unreal Engine Docs: https://docs.unrealengine.com/5.3/

## Need Help?

Check the troubleshooting section in `README_UE5.md` or open an issue on GitHub.

Happy developing! 🎮💰
