# Finance Frenzy

> Award-winning financial literacy simulation game (Hydrangea Hacks 2021). Two versions: UE5 rebuild and Python/PyQt6 legacy.

**Stack:** Unreal Engine 5 (C++ / Blueprints) · Python/PyQt6 (Legacy) · matplotlib · pandas
**Visibility:** Public
**Roadmap:** See `ROADMAP.md` for version targets and feature specs.

---

## Project Structure

```
FinanceFrenzy/
├── Source/               # UE5 C++ source
├── Content/              # UE5 content (assets, maps)
├── Config/               # UE5 project config
├── Scripts/              # UE5 utility scripts
├── Legacy/
│   └── Python/           # Original PyQt6 hackathon version
├── data/                 # Historical market data (2000-2020)
├── assets/               # UI assets and images
├── QUICKSTART.md         # Get running in 5 min
├── BLUEPRINT_GUIDE.md    # Working with UE5 Blueprints
└── ROADMAP.md            # Version roadmap
```

## Commands

```bash
# UE5 Version
# Open FinanceFrenzy.uproject in Unreal Engine 5

# Legacy Python Version
cd Legacy/Python
pip install -r requirements.txt
python main.py

# No automated tests yet — see ROADMAP.md
```

## Project-Specific Rules
- Legacy code lives in `Legacy/` — do not modify unless explicitly asked
- Historical market data is real (2000-2020) — never modify the source data files
- All financial formulas must match real-world calculations — document sources in comments
- UE5: Follow Epic coding standards for C++
- This is a public repo — no credentials, no proprietary game assets
- Default branch is `master` (legacy convention)


## Cardinal Rules

These rules are non-negotiable. Violating any one of them is grounds to stop and reassess.

### 1. No Partial Implementations
Never add placeholder code, TODO stubs, mock-only features, or partial logic that doesn't work end-to-end.
- No `// TODO: implement later` stubs that ship
- No fake API calls returning hardcoded data pretending to be real
- No skeleton functions that silently do nothing
- No commented-out blocks left as "future work"
- If a feature isn't ready, don't merge it

### 2. Never Half-Do It
Every commit must leave the codebase in a working state. If you start a feature, finish it or revert. No partial migrations, no half-wired routes, no UI that links to nothing.

### 3. Never Be Unsafe
- NEVER commit secrets, API keys, tokens, passwords, PII, or credentials to code or git history
- All secrets live in `.env` files (which are `.gitignore`d)
- `.env.example` is the template — placeholder values only
- Validate all user input server-side — never trust the client
- Use parameterized queries — never concatenate SQL strings
- Never log or print auth tokens, JWTs, or API keys (even in debug)
- Check `.gitignore` before every commit — no `.env`, `.pem`, `__pycache__`, `.idea`, `node_modules`, `dist/`, `.DS_Store`

### 4. Always Build and Pass All Tests
- Run the full test suite before every commit
- If tests break, fix them before pushing — never push broken tests
- If adding a feature, add tests for that feature in the same PR
- CI must pass before merge — no exceptions, no "I'll fix it later"
- Never mock internal functionality without explicit permission — use real DB connections, real services
- External APIs (third-party, rate-limited, paid) may be mocked

### 5. Version Discipline
- Follow semantic versioning: MAJOR.MINOR.PATCH
- Every release gets a git tag and a GitHub Release with notes
- `ROADMAP.md` is the source of truth for what each version delivers
- Never skip versions or release out of order

## Security Checklist (Run Before Every PR)

```bash
# Scan for accidentally committed secrets
grep -rn "sk-\|password=\|secret=\|PRIVATE_KEY\|api_key=" . --include="*.py" --include="*.ts" --include="*.js" --include="*.env" | grep -v node_modules | grep -v ".env.example" | grep -v "test_"

# Verify .gitignore is working
git status --porcelain | grep -E "\.env$|\.pem$|__pycache__|node_modules|dist/|\.DS_Store"

# If anything shows up ↑ — stop and fix .gitignore before committing
```

## Git Workflow

- Default branch: `main` (or `master` for legacy repos)
- Commit messages: imperative mood, concise (`fix: resolve auth redirect loop`, not `fixed stuff`)
- Prefer atomic commits — one logical change per commit
- Never force-push to `main`
- Use feature branches for anything that touches more than 3 files


## .gitignore Must Cover (Verify These Exist)

Every repo's `.gitignore` must include at minimum:

```
# Secrets & credentials
.env
.env.local
.env.*.local
*.pem
*.key
*.p12
*.pfx
service-account*.json

# Python
__pycache__/
*.py[cod]
*.egg-info/
.venv/
venv/
*.pyc

# Node
node_modules/
dist/
.next/
build/

# IDE
.idea/
.vscode/settings.json
*.swp
*.swo
.DS_Store
Thumbs.db

# Docker
*.log

# OS
.DS_Store
Thumbs.db
```

If any of these patterns are missing from the repo's `.gitignore`, add them before doing anything else.


## How to Contribute to This Repo

1. Read `ROADMAP.md` — know what version you're building toward
2. Read this file (`AGENTS.md`) — follow the cardinal rules
3. Check `.gitignore` covers all patterns listed above
4. Branch off `main` for any multi-file change
5. Write tests for new features (same PR, not "later")
6. Run the full test suite before pushing
7. Write clear commit messages (imperative mood)
8. Open a PR — CI must pass before merge
