@echo off
REM Setup script for Finance Frenzy Unreal Engine 5 project (Windows)
REM This script helps set up the development environment

echo ==========================================
echo Finance Frenzy - UE5 Setup Script
echo ==========================================
echo.

REM Check if UE5 is installed
echo Checking for Unreal Engine 5.3...

set UE_PATH=
if exist "%ProgramFiles%\Epic Games\UE_5.3" (
    set UE_PATH=%ProgramFiles%\Epic Games\UE_5.3
) else if exist "%ProgramFiles%\Epic Games\UE_5.4" (
    set UE_PATH=%ProgramFiles%\Epic Games\UE_5.4
) else if exist "C:\Program Files\Epic Games\UE_5.3" (
    set UE_PATH=C:\Program Files\Epic Games\UE_5.3
)

if "%UE_PATH%"=="" (
    echo ERROR: Unreal Engine 5.3 not found in standard locations.
    echo Please install Unreal Engine 5.3 from Epic Games Launcher
    echo Visit: https://www.unrealengine.com/download
    pause
    exit /b 1
)

echo Found Unreal Engine at: %UE_PATH%
echo.

REM Generate project files
echo Generating Visual Studio project files...

set PROJECT_PATH=%cd%\FinanceFrenzy.uproject

"%UE_PATH%\Engine\Build\BatchFiles\Build.bat" -projectfiles -project="%PROJECT_PATH%" -game -engine

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Failed to generate project files
    pause
    exit /b 1
)

echo.
echo Project files generated!
echo.

REM Check if Visual Studio is installed
echo Checking for Visual Studio 2022...

set VS_PATH=
if exist "%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" (
    set VS_PATH=%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe
) else if exist "%ProgramFiles%\Microsoft Visual Studio\2022\Professional\Common7\IDE\devenv.exe" (
    set VS_PATH=%ProgramFiles%\Microsoft Visual Studio\2022\Professional\Common7\IDE\devenv.exe
) else if exist "%ProgramFiles%\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.exe" (
    set VS_PATH=%ProgramFiles%\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.exe
)

if "%VS_PATH%"=="" (
    echo WARNING: Visual Studio 2022 not found
    echo Please install Visual Studio 2022 with C++ development tools
    echo Visit: https://visualstudio.microsoft.com/downloads/
) else (
    echo Found Visual Studio 2022
)

echo.
echo ==========================================
echo Setup complete!
echo ==========================================
echo.
echo Next steps:
echo 1. Open FinanceFrenzy.sln in Visual Studio 2022
echo 2. Set build configuration to "Development Editor"
echo 3. Set platform to "Win64"
echo 4. Build the solution (Ctrl+Shift+B)
echo 5. Run the editor by opening FinanceFrenzy.uproject
echo.
echo For more information, see:
echo   - README_UE5.md - Complete UE5 documentation
echo   - QUICKSTART.md - Quick start guide
echo   - BUILD.md - Detailed build instructions
echo.

pause
