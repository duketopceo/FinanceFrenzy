# Development Scripts

This directory contains helper scripts for Finance Frenzy development.

## Available Scripts

### setup.sh / setup.bat
**Purpose**: Initial project setup and project file generation

**Windows Usage**:
```cmd
cd FinanceFrenzy
Scripts\setup.bat
```

**macOS/Linux Usage**:
```bash
cd FinanceFrenzy
./Scripts/setup.sh
```

**What it does**:
- Checks for Unreal Engine 5.3 installation
- Generates project files (.sln for Windows, .xcworkspace for Mac)
- Verifies required tools are installed
- Provides next steps

## Future Scripts

Additional scripts that could be added:

### build.sh / build.bat
Automated build script for different configurations

### package.sh / package.bat
Automated packaging for different platforms

### test.sh / test.bat
Run automated tests

### clean.sh / clean.bat
Clean all generated files for fresh rebuild

### import_data.py
Python script to convert CSV data to UE5 data tables

## Contributing

When adding new scripts:
1. Add both .sh (Unix) and .bat (Windows) versions
2. Make Unix scripts executable: `chmod +x script.sh`
3. Add clear comments in the script
4. Update this README with script description
5. Handle errors gracefully

## Notes

- All paths should be relative to project root
- Scripts should check for prerequisites before running
- Provide clear error messages
- Support both development and CI/CD usage
