# Building Finance Frenzy for Unreal Engine 5

## Windows Build Instructions

### Prerequisites
- Windows 10/11 (64-bit)
- Visual Studio 2022 (Community, Professional, or Enterprise)
  - Desktop development with C++
  - Game development with C++
  - .NET desktop development
- Unreal Engine 5.3
- Git

### Step 1: Generate Visual Studio Project

Open Command Prompt or PowerShell:

```cmd
cd C:\Path\To\FinanceFrenzy
"%ProgramFiles%\Epic Games\UE_5.3\Engine\Build\BatchFiles\Build.bat" -projectfiles -project="%cd%\FinanceFrenzy.uproject" -game -engine
```

Or right-click `FinanceFrenzy.uproject` and select "Generate Visual Studio project files"

### Step 2: Build in Visual Studio

```cmd
cd C:\Path\To\FinanceFrenzy
"%ProgramFiles%\Epic Games\UE_5.3\Engine\Build\BatchFiles\Build.bat" FinanceFrenzyEditor Win64 Development -project="%cd%\FinanceFrenzy.uproject"
```

Or:
1. Open `FinanceFrenzy.sln` in Visual Studio 2022
2. Set build configuration to "Development Editor"
3. Set platform to "Win64"
4. Build → Build Solution (Ctrl+Shift+B)

### Step 3: Run the Editor

```cmd
"%ProgramFiles%\Epic Games\UE_5.3\Engine\Binaries\Win64\UnrealEditor.exe" "%cd%\FinanceFrenzy.uproject"
```

Or double-click `FinanceFrenzy.uproject`

## macOS Build Instructions

### Prerequisites
- macOS 12.0 (Monterey) or later
- Xcode 14.0 or later with Command Line Tools
- Unreal Engine 5.3
- Git

### Step 1: Generate Xcode Project

Open Terminal:

```bash
cd /Path/To/FinanceFrenzy
"/Users/Shared/Epic Games/UE_5.3/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" -project="$(pwd)/FinanceFrenzy.uproject" -game -engine
```

### Step 2: Build with Xcode

```bash
cd /Path/To/FinanceFrenzy
"/Users/Shared/Epic Games/UE_5.3/Engine/Build/BatchFiles/Mac/Build.sh" FinanceFrenzyEditor Mac Development "$(pwd)/FinanceFrenzy.uproject"
```

Or:
1. Open `FinanceFrenzy.xcworkspace` in Xcode
2. Select "FinanceFrenzyEditor" scheme
3. Product → Build (Cmd+B)

### Step 3: Run the Editor

```bash
"/Users/Shared/Epic Games/UE_5.3/Engine/Binaries/Mac/UnrealEditor.app/Contents/MacOS/UnrealEditor" "$(pwd)/FinanceFrenzy.uproject"
```

Or double-click `FinanceFrenzy.uproject`

## Linux Build Instructions

### Prerequisites
- Ubuntu 20.04 LTS or later (or compatible distribution)
- GCC 11.0 or Clang 13.0
- Unreal Engine 5.3 (built from source)
- Git
- Required libraries:
  ```bash
  sudo apt-get install build-essential mono-complete mono-devel
  ```

### Step 1: Generate Makefiles

```bash
cd /path/to/FinanceFrenzy
/home/user/UnrealEngine/Engine/Build/BatchFiles/Linux/GenerateProjectFiles.sh -project="$(pwd)/FinanceFrenzy.uproject" -game -engine
```

### Step 2: Build

```bash
cd /path/to/FinanceFrenzy
/home/user/UnrealEngine/Engine/Build/BatchFiles/Linux/Build.sh FinanceFrenzyEditor Linux Development "$(pwd)/FinanceFrenzy.uproject"
```

### Step 3: Run the Editor

```bash
/home/user/UnrealEngine/Engine/Binaries/Linux/UnrealEditor "$(pwd)/FinanceFrenzy.uproject"
```

## Clean Build

If you encounter build issues, perform a clean build:

### Windows
```cmd
rmdir /s /q Binaries Intermediate Saved
del FinanceFrenzy.sln
```
Then regenerate and rebuild.

### macOS/Linux
```bash
rm -rf Binaries/ Intermediate/ Saved/ *.xcworkspace *.sln
```
Then regenerate and rebuild.

## Common Build Issues

### "Could not find UnrealEngine installation"
**Solution**: 
- Verify UE5.3 is installed
- Check engine association in `.uproject`
- Update paths in build commands

### "Missing module: FinanceFrenzy"
**Solution**:
```bash
# Delete intermediate files
rm -rf Binaries/ Intermediate/
# Regenerate project files
# Rebuild
```

### "Unable to build while UnrealEditor is running"
**Solution**: Close the Unreal Editor before building

### Visual Studio "Project out of date"
**Solution**: 
- Right-click project → Properties → Configuration Properties
- Verify Configuration matches (Development Editor / Win64)
- Clean and rebuild

### Xcode "Build failed"
**Solution**:
- Product → Clean Build Folder (Cmd+Shift+K)
- Quit Xcode
- Delete derived data: `~/Library/Developer/Xcode/DerivedData`
- Rebuild

### Linux Linker Errors
**Solution**:
```bash
# Update build tools
sudo apt-get update
sudo apt-get upgrade build-essential

# Verify clang/gcc version
clang --version  # Should be 13.0+
gcc --version    # Should be 11.0+
```

## Build Configurations

### Development
- Debugging symbols included
- Some optimizations
- Use for testing

### Development Editor
- For running in Unreal Editor
- Default for development
- Best debugging experience

### Shipping
- Full optimizations
- No debugging symbols
- Smallest binary size
- Use for final distribution

### Debug
- No optimizations
- Full debugging symbols
- Slowest but easiest to debug

## Packaging for Distribution

### Package via Unreal Editor

1. Open project in Unreal Editor
2. File → Package Project → Windows/Mac/Linux
3. Select output directory
4. Wait for packaging to complete

### Package via Command Line

#### Windows
```cmd
"%ProgramFiles%\Epic Games\UE_5.3\Engine\Build\BatchFiles\RunUAT.bat" BuildCookRun -project="%cd%\FinanceFrenzy.uproject" -platform=Win64 -clientconfig=Shipping -cook -stage -pak -archive -archivedirectory="%cd%\Packaged"
```

#### macOS
```bash
"/Users/Shared/Epic Games/UE_5.3/Engine/Build/BatchFiles/RunUAT.sh" BuildCookRun -project="$(pwd)/FinanceFrenzy.uproject" -platform=Mac -clientconfig=Shipping -cook -stage -pak -archive -archivedirectory="$(pwd)/Packaged"
```

#### Linux
```bash
/home/user/UnrealEngine/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -project="$(pwd)/FinanceFrenzy.uproject" -platform=Linux -clientconfig=Shipping -cook -stage -pak -archive -archivedirectory="$(pwd)/Packaged"
```

## Continuous Integration

For CI/CD pipelines, see examples in `.github/workflows/` (to be added).

## Performance Tips

- Use **Development** builds for testing
- Use **Shipping** builds for final distribution
- Enable **Unity Build** for faster full rebuilds (in .Build.cs)
- Use **Precompiled Headers** to speed up compilation
- Consider **IncrediBuild** or **FastBuild** for distributed builds

## Getting Help

- Check UE5 build documentation: https://docs.unrealengine.com/5.3/en-US/building-unreal-engine-from-source/
- Visit [Troubleshooting section](README_UE5.md#troubleshooting) in main README
- Open an issue on GitHub

---

Happy Building! 🔨
