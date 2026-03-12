<p align="center">
  <img src="https://challengepost-s3-challengepost.netdna-ssl.com/photos/production/software_thumbnail_photos/001/568/048/datas/medium.jpg" alt="Finance Frenzy" width="200"/>
  <h1 align="center">Finance Frenzy</h1>
  <p align="center">
    Financial literacy simulation game — learn markets through real historical data.
    <br />
    <strong>Hydrangea Hacks 2021</strong> &mdash; Best Finance Hack &amp; Top 6 Winner
  </p>
</p>

<p align="center">
  <a href="https://github.com/duketopceo/FinanceFrenzy/releases/tag/v1.0.0"><img src="https://img.shields.io/badge/release-v1.0.0-blue.svg" alt="Release"></a>
  <a href="https://devpost.com/software/finance-frenzy/"><img src="https://img.shields.io/badge/hackathon-winner-gold.svg" alt="Hackathon Winner"></a>
  <a href="#tech-stack"><img src="https://img.shields.io/badge/python-PyQt6-3776AB.svg" alt="Python"></a>
  <a href="#tech-stack"><img src="https://img.shields.io/badge/engine-Unreal%20Engine%205-0E1128.svg" alt="UE5"></a>
</p>

---

## Overview

Finance Frenzy is a simulation game where players navigate 20 years of real market conditions (2000–2020) — making investment, savings, and spending decisions using actual historical stock prices, interest rates, and inflation data. Built to teach financial literacy through gameplay rather than textbooks.

**Awards:** Best Finance Hack and Top 6 Overall at [Hydrangea Hacks 2021](https://devpost.com/software/finance-frenzy/).

---

## Gameplay

- Manage a virtual portfolio over a 20-year simulation period
- React to real historical market events, recessions, and bull runs
- Invest in 11 S&P sector ETFs representing different industries
- Face random financial challenges (job loss, medical bills, windfalls)
- Track your net worth against other players on the high score board
- End-of-game cashflow analysis shows what decisions drove outcomes

---

## Two Versions

### Unreal Engine 5 (Current)

Full rebuild with modern game engine architecture, enhanced graphics, and cross-platform support.

- **[UE5 Documentation](README_UE5.md)** — Setup and development guide
- **[Quick Start](QUICKSTART.md)** — Get running in 5 minutes
- **[Blueprint Guide](BLUEPRINT_GUIDE.md)** — Working with Blueprints and C++

### Python / PyQt6 (Legacy)

The original hackathon prototype, preserved in `Legacy/Python/` for reference.

```bash
cd Legacy/Python
pip install -r requirements.txt
python main.py
```

---

## Tech Stack

| Component | Technology |
|-----------|-----------|
| **Game Engine** | Unreal Engine 5.3 (C++ + Blueprints) |
| **Original Prototype** | Python, PyQt6, Matplotlib |
| **Data** | Historical S&P sector prices, US interest rates, inflation (2000–2020) |
| **Charts** | UMG widgets (UE5) / Matplotlib (Python) |

---

## Project Structure

```
FinanceFrenzy/
├── Source/                    # UE5 C++ source
├── Content/                   # UE5 assets, Blueprints, UI
├── Config/                    # UE5 project configuration
├── FinanceFrenzy.uproject     # Unreal project file
├── Legacy/
│   └── Python/                # Original PyQt6 prototype
├── data/                      # Historical market data (CSV)
├── assets/                    # Design assets and mockups
├── QUICKSTART.md              # 5-minute setup guide
├── BLUEPRINT_GUIDE.md         # UE5 Blueprint reference
├── CONTRIBUTING.md            # Contribution guidelines
└── README_UE5.md              # Full UE5 documentation
```

---

## Quick Start (UE5)

1. Install [Unreal Engine 5.3](https://www.unrealengine.com/)
2. Clone this repository
3. Open `FinanceFrenzy.uproject`
4. Build and run (Play in Editor)

See **[QUICKSTART.md](QUICKSTART.md)** for detailed instructions.

---

## Documentation

| Document | Description |
|----------|-------------|
| [QUICKSTART.md](QUICKSTART.md) | 5-minute setup guide |
| [README_UE5.md](README_UE5.md) | Full UE5 architecture and development |
| [BLUEPRINT_GUIDE.md](BLUEPRINT_GUIDE.md) | Blueprint and C++ workflow |
| [CONTRIBUTING.md](CONTRIBUTING.md) | How to contribute |
| [BUILD.md](BUILD.md) | Build configuration and packaging |
| [MIGRATION_GUIDE.md](MIGRATION_GUIDE.md) | PyQt6 → UE5 migration notes |

---

## License

MIT
