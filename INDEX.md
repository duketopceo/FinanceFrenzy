# Finance Frenzy - Documentation Index

Welcome to Finance Frenzy! This index helps you find the right documentation for your needs.

## 🚀 Getting Started

**New to the project?** Start here:

1. **[README.md](README.md)** - Project overview and history
2. **[README_UE5.md](README_UE5.md)** - Complete UE5 setup guide ⭐ START HERE
3. **[QUICKSTART.md](QUICKSTART.md)** - Get running in 5 minutes

## 👨‍💻 For Developers

### Setup & Building
- **[README_UE5.md](README_UE5.md)** - Full setup instructions
- **[BUILD.md](BUILD.md)** - Build system and packaging
- **[Scripts/setup.sh](Scripts/setup.sh)** / **[Scripts/setup.bat](Scripts/setup.bat)** - Automated setup

### Development Guides
- **[BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md)** - Working with Blueprints
- **[CONTRIBUTING.md](CONTRIBUTING.md)** - How to contribute
- **[POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md)** - Content creation tasks

### Migration & Reference
- **[MIGRATION_GUIDE.md](MIGRATION_GUIDE.md)** - Python to UE5 mapping
- **[SUMMARY.md](SUMMARY.md)** - Project completion summary

## 📚 Documentation by Purpose

### I want to...

#### ...understand what this project is
→ **[README.md](README.md)**

#### ...set up Unreal Engine 5 and start developing
→ **[README_UE5.md](README_UE5.md)** then **[QUICKSTART.md](QUICKSTART.md)**

#### ...build the project
→ **[BUILD.md](BUILD.md)**

#### ...create Blueprints and widgets
→ **[BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md)**

#### ...contribute to the project
→ **[CONTRIBUTING.md](CONTRIBUTING.md)**

#### ...understand the C++ code
→ **[Source/FinanceFrenzy/Public/](Source/FinanceFrenzy/Public/)** (header files)

#### ...see what needs to be done next
→ **[POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md)**

#### ...migrate from Python version
→ **[MIGRATION_GUIDE.md](MIGRATION_GUIDE.md)**

#### ...run the original Python version
→ **[Legacy/Python/README.md](Legacy/Python/README.md)**

#### ...understand the content structure
→ **[Content/README.md](Content/README.md)**

## 📂 Project Structure

```
FinanceFrenzy/
├── 📄 README.md                    # Main readme
├── 📄 README_UE5.md                # UE5 setup guide ⭐
├── 📄 QUICKSTART.md                # 5-minute start
├── 📄 BUILD.md                     # Build instructions
├── 📄 BLUEPRINT_GUIDE.md           # Blueprint reference
├── 📄 CONTRIBUTING.md              # Contribution guide
├── 📄 MIGRATION_GUIDE.md           # Python → UE5
├── 📄 POST_SETUP_CHECKLIST.md      # Next steps
├── 📄 SUMMARY.md                   # Project summary
│
├── 🎮 FinanceFrenzy.uproject       # Main project file
│
├── 📁 Source/                      # C++ source code
│   ├── FinanceFrenzy/
│   │   ├── Public/                 # Header files
│   │   ├── Private/                # Implementation
│   │   └── FinanceFrenzy.Build.cs
│   ├── FinanceFrenzy.Target.cs
│   └── FinanceFrenzyEditor.Target.cs
│
├── 📁 Config/                      # UE5 configuration
│   ├── DefaultEngine.ini
│   ├── DefaultGame.ini
│   ├── DefaultInput.ini
│   └── DefaultEditor.ini
│
├── 📁 Content/                     # Game assets (to create)
│   ├── 📄 README.md
│   ├── Blueprints/
│   ├── Maps/
│   ├── UI/
│   ├── Data/
│   ├── Materials/
│   └── Textures/
│
├── 📁 Scripts/                     # Development scripts
│   ├── 📄 README.md
│   ├── setup.sh                    # Unix setup
│   └── setup.bat                   # Windows setup
│
├── 📁 Legacy/                      # Original Python version
│   └── Python/
│       ├── 📄 README.md
│       └── *.py files
│
├── 📁 data/                        # Historical market data
│   └── *.csv files (13 files)
│
└── 📁 assets/                      # Original image assets
    └── *.png files (7 files)
```

## 🎯 Quick Reference by Role

### Project Manager / Stakeholder
- [README.md](README.md) - Project overview
- [SUMMARY.md](SUMMARY.md) - Current status
- [POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md) - Remaining work

### C++ Developer
- [README_UE5.md](README_UE5.md) - Setup
- [Source/FinanceFrenzy/](Source/FinanceFrenzy/) - Code
- [BUILD.md](BUILD.md) - Building
- [CONTRIBUTING.md](CONTRIBUTING.md) - Standards

### Blueprint Designer
- [QUICKSTART.md](QUICKSTART.md) - Get started
- [BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md) - Reference
- [POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md) - Tasks

### Content Creator / Artist
- [Content/README.md](Content/README.md) - Asset structure
- [POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md) - What to create

### Python Developer (Migrating)
- [MIGRATION_GUIDE.md](MIGRATION_GUIDE.md) - Mapping guide
- [Legacy/Python/](Legacy/Python/) - Original code

## 🔍 Find Information By Topic

### Setup & Installation
- Setup overview: [README_UE5.md](README_UE5.md#getting-started)
- Quick setup: [QUICKSTART.md](QUICKSTART.md)
- Automated setup: [Scripts/](Scripts/)

### Building & Compilation
- Build guide: [BUILD.md](BUILD.md)
- Windows build: [BUILD.md](BUILD.md#windows-build-instructions)
- macOS build: [BUILD.md](BUILD.md#macos-build-instructions)
- Linux build: [BUILD.md](BUILD.md#linux-build-instructions)

### Development
- C++ classes: [Source/FinanceFrenzy/Public/](Source/FinanceFrenzy/Public/)
- Blueprint guide: [BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md)
- Contributing: [CONTRIBUTING.md](CONTRIBUTING.md)

### Game Design
- Core systems: [README_UE5.md](README_UE5.md#core-systems)
- Data structures: [Source/FinanceFrenzy/Public/FinanceFrenzyDataTypes.h](Source/FinanceFrenzy/Public/FinanceFrenzyDataTypes.h)
- Blueprint classes: [BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md#core-blueprint-classes)

### Content Creation
- Task checklist: [POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md)
- Content structure: [Content/README.md](Content/README.md)
- Data tables: [BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md#data-table-creation)

### Troubleshooting
- Build issues: [BUILD.md](BUILD.md#common-build-issues)
- Setup issues: [README_UE5.md](README_UE5.md#troubleshooting)
- General help: [CONTRIBUTING.md](CONTRIBUTING.md#getting-help)

## 📖 Reading Order for New Contributors

1. **[README.md](README.md)** - Understand the project (5 min)
2. **[README_UE5.md](README_UE5.md)** - Install and setup (30 min)
3. **[QUICKSTART.md](QUICKSTART.md)** - Get project running (10 min)
4. **[BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md)** - Learn development (30 min)
5. **[POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md)** - Pick a task
6. **[CONTRIBUTING.md](CONTRIBUTING.md)** - Follow guidelines

Total time: ~1.5 hours to be productive!

## 🆘 Common Questions

**Q: Where do I start?**  
A: [README_UE5.md](README_UE5.md) then [QUICKSTART.md](QUICKSTART.md)

**Q: How do I build the project?**  
A: [BUILD.md](BUILD.md)

**Q: How do I create Blueprints?**  
A: [BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md)

**Q: What needs to be done?**  
A: [POST_SETUP_CHECKLIST.md](POST_SETUP_CHECKLIST.md)

**Q: I know Python, where do I start?**  
A: [MIGRATION_GUIDE.md](MIGRATION_GUIDE.md)

**Q: How do I contribute?**  
A: [CONTRIBUTING.md](CONTRIBUTING.md)

**Q: Where is the C++ code?**  
A: [Source/FinanceFrenzy/](Source/FinanceFrenzy/)

**Q: Can I run the old Python version?**  
A: Yes! See [Legacy/Python/README.md](Legacy/Python/README.md)

## 📝 Documentation Standards

All documentation follows these principles:
- **Clear**: Easy to understand for the target audience
- **Complete**: Covers all necessary information
- **Current**: Up-to-date with latest code
- **Consistent**: Uses same terminology throughout

## 🔄 Keeping Documentation Updated

When making changes:
1. Update code comments
2. Update relevant markdown files
3. Test all instructions
4. Update this index if adding new docs

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

## 🌐 External Resources

- [Unreal Engine 5 Documentation](https://docs.unrealengine.com/5.3/)
- [UE5 C++ API Reference](https://docs.unrealengine.com/5.3/en-US/API/)
- [UE5 Blueprint Documentation](https://docs.unrealengine.com/5.3/en-US/blueprints-visual-scripting-in-unreal-engine/)
- [Original Devpost](https://devpost.com/software/finance-frenzy/)

## 📧 Support

- **GitHub Issues**: Bug reports and feature requests
- **GitHub Discussions**: Questions and general discussion
- **Contributing**: See [CONTRIBUTING.md](CONTRIBUTING.md)

---

**Last Updated**: December 2024  
**Status**: Documentation Complete ✅  
**Next Phase**: Content Creation 🎨

Happy developing! 🎮💰
