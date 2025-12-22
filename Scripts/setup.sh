#!/bin/bash
# Setup script for Finance Frenzy Unreal Engine 5 project
# This script helps set up the development environment

set -e

echo "=========================================="
echo "Finance Frenzy - UE5 Setup Script"
echo "=========================================="
echo ""

# Check if UE5 is installed
echo "Checking for Unreal Engine 5.3..."

UE_PATH=""

# Check common installation paths
if [ "$(uname)" == "Darwin" ]; then
    # macOS
    if [ -d "/Users/Shared/Epic Games/UE_5.3" ]; then
        UE_PATH="/Users/Shared/Epic Games/UE_5.3"
    elif [ -d "/Users/Shared/Epic Games/UE_5.4" ]; then
        UE_PATH="/Users/Shared/Epic Games/UE_5.4"
    fi
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # Linux
    if [ -d "$HOME/UnrealEngine" ]; then
        UE_PATH="$HOME/UnrealEngine"
    fi
fi

if [ -z "$UE_PATH" ]; then
    echo "ERROR: Unreal Engine 5.3 not found in standard locations."
    echo "Please install Unreal Engine 5.3 from Epic Games Launcher"
    echo "or build from source: https://github.com/EpicGames/UnrealEngine"
    exit 1
fi

echo "Found Unreal Engine at: $UE_PATH"
echo ""

# Generate project files
echo "Generating project files..."

PROJECT_PATH="$(pwd)/FinanceFrenzy.uproject"

if [ "$(uname)" == "Darwin" ]; then
    # macOS
    "$UE_PATH/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh" \
        -project="$PROJECT_PATH" -game -engine
    echo ""
    echo "Project files generated!"
    echo "Next steps:"
    echo "1. Open FinanceFrenzy.xcworkspace in Xcode"
    echo "2. Select 'FinanceFrenzyEditor' scheme"
    echo "3. Build with Cmd+B"
    echo "4. Run the editor by opening FinanceFrenzy.uproject"
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # Linux
    "$UE_PATH/Engine/Build/BatchFiles/Linux/GenerateProjectFiles.sh" \
        -project="$PROJECT_PATH" -game -engine
    echo ""
    echo "Project files generated!"
    echo "Next steps:"
    echo "1. Build: $UE_PATH/Engine/Build/BatchFiles/Linux/Build.sh FinanceFrenzyEditor Linux Development \"$PROJECT_PATH\""
    echo "2. Run: $UE_PATH/Engine/Binaries/Linux/UnrealEditor \"$PROJECT_PATH\""
fi

echo ""
echo "=========================================="
echo "Setup complete!"
echo "=========================================="
echo ""
echo "For more information, see:"
echo "  - README_UE5.md - Complete UE5 documentation"
echo "  - QUICKSTART.md - Quick start guide"
echo "  - BUILD.md - Detailed build instructions"
echo ""
