# Contributing to Finance Frenzy (Unreal Engine 5)

Thank you for your interest in contributing! This guide will help you get started.

## Development Setup

1. **Prerequisites**
   - Unreal Engine 5.3+
   - Visual Studio 2022 (Windows), Xcode 14+ (Mac), or GCC/Clang (Linux)
   - Git
   - 16GB RAM minimum
   - 100GB free disk space

2. **Fork and Clone**
   ```bash
   git clone https://github.com/YOUR_USERNAME/FinanceFrenzy.git
   cd FinanceFrenzy
   ```

3. **Set Up Project**
   - Right-click `FinanceFrenzy.uproject`
   - Select "Generate Visual Studio project files"
   - Open solution and build

## Code Style Guidelines

### C++ Code Style

Follow Unreal Engine's coding standards:

**Naming Conventions**:
- Classes: `AFinanceFrenzyGameMode`, `UFinanceFrenzyWidget`
- Functions: `PascalCase()` for public, `PascalCase()` for private
- Variables: `PascalCase` for public, `PascalCase` for private
- Member variables: No special prefix (UE handles with reflection)
- Constants: `UPPER_SNAKE_CASE`
- Booleans: Prefix with `b` (e.g., `bIsActive`)

**Example**:
```cpp
class FINANCEFRENZY_API AFinanceFrenzyGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
    float DayDuration;

    UFUNCTION(BlueprintCallable, Category = "Game")
    void ProgressDay();

private:
    float DayTimer;
};
```

**Comments**:
- Use `/** */` for documentation comments
- Use `//` for inline comments
- Document all public functions
- Explain complex logic

### Blueprint Naming

- Widget Blueprints: `WBP_[Name]` (e.g., `WBP_MainHUD`)
- Actor Blueprints: `BP_[Name]` (e.g., `BP_GameMode`)
- Data Tables: `DT_[Name]` (e.g., `DT_StockData`)
- Materials: `M_[Name]` (e.g., `M_UI_Background`)
- Textures: `T_[Name]` (e.g., `T_Logo`)

## Project Structure

### Adding New Features

1. **C++ Classes**
   - Header files: `Source/FinanceFrenzy/Public/`
   - Implementation: `Source/FinanceFrenzy/Private/`
   - Follow existing naming patterns

2. **Blueprints**
   - Game logic: `Content/Blueprints/`
   - UI: `Content/UI/`
   - Data: `Content/Data/`

3. **Assets**
   - Materials: `Content/Materials/`
   - Textures: `Content/Textures/`
   - Maps: `Content/Maps/`

## Contribution Workflow

### 1. Create a Feature Branch

```bash
git checkout -b feature/your-feature-name
```

Branch naming:
- Features: `feature/description`
- Bug fixes: `bugfix/description`
- Documentation: `docs/description`

### 2. Make Your Changes

- Write clean, well-documented code
- Follow the style guidelines
- Test thoroughly in the editor
- Add comments for complex logic

### 3. Test Your Changes

**Before Committing**:
- [ ] Code compiles without errors
- [ ] No new warnings introduced
- [ ] Tested in PIE (Play In Editor)
- [ ] Tested packaged build (if applicable)
- [ ] UI works as expected
- [ ] No performance regressions

**Testing Checklist**:
- [ ] Buy/sell stocks works
- [ ] Cash updates correctly
- [ ] Day progression works
- [ ] UI displays data correctly
- [ ] No crashes or errors in logs

### 4. Commit Your Changes

```bash
git add .
git commit -m "feat: Add stock sorting functionality"
```

**Commit Message Format**:
```
<type>: <description>

[optional body]
[optional footer]
```

**Types**:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting)
- `refactor`: Code refactoring
- `test`: Adding tests
- `chore`: Maintenance tasks

**Examples**:
```
feat: Add multiplayer support for stock trading
fix: Resolve crash when selling all stocks
docs: Update blueprint guide with new examples
refactor: Optimize game state update logic
```

### 5. Push and Create Pull Request

```bash
git push origin feature/your-feature-name
```

1. Go to GitHub repository
2. Click "New Pull Request"
3. Fill in the template:
   - Description of changes
   - Testing performed
   - Screenshots (if UI changes)
   - Related issues

## What to Contribute

### High Priority
- [ ] Complete UI widget implementations
- [ ] Data table integration for CSV data
- [ ] Save/load game system
- [ ] Game over screen with statistics
- [ ] Main menu implementation
- [ ] Sound effects and music
- [ ] Tutorial system

### Medium Priority
- [ ] More financial instruments (bonds, options)
- [ ] Achievement system
- [ ] Leaderboard integration
- [ ] Difficulty settings
- [ ] Localization support
- [ ] Performance optimizations

### Documentation
- [ ] More blueprint examples
- [ ] Video tutorials
- [ ] API documentation
- [ ] Translation of docs

### Bug Fixes
Check the [Issues](https://github.com/duketopceo/FinanceFrenzy/issues) page for open bugs.

## Code Review Process

1. **Automated Checks**
   - Code must compile
   - No critical warnings
   - Follows naming conventions

2. **Manual Review**
   - Code quality and style
   - Logic correctness
   - Performance considerations
   - Documentation completeness

3. **Testing**
   - Reviewer tests the changes
   - Verifies no regressions
   - Checks UI/UX if applicable

4. **Approval**
   - At least one approval required
   - Address all review comments
   - Rebase if needed

## Best Practices

### Performance
- Avoid Tick() when possible, use timers
- Cache frequently-accessed references
- Use object pooling for UI elements
- Optimize data table lookups

### Memory Management
- Use `UPROPERTY()` for garbage collection
- Clear arrays when data is no longer needed
- Avoid memory leaks in C++

### UI/UX
- Ensure UI is responsive
- Add loading indicators for slow operations
- Provide clear feedback for user actions
- Support keyboard and gamepad navigation

### Multiplayer Considerations
- Mark replicated properties correctly
- Use RPCs appropriately
- Test in multiplayer scenarios
- Handle network latency gracefully

## Getting Help

### Resources
- [Unreal Engine Documentation](https://docs.unrealengine.com/5.3/)
- [UE5 API Reference](https://docs.unrealengine.com/5.3/en-US/API/)
- [C++ Programming Guide](https://docs.unrealengine.com/5.3/en-US/ProgrammingAndScripting/ProgrammingWithCPP/)

### Community
- GitHub Discussions: Ask questions and share ideas
- GitHub Issues: Report bugs and request features
- Pull Requests: Review others' contributions

### Questions?
- Open a [Discussion](https://github.com/duketopceo/FinanceFrenzy/discussions)
- Check existing [Issues](https://github.com/duketopceo/FinanceFrenzy/issues)
- Read the documentation in the repo

## License

By contributing, you agree that your contributions will be licensed under the same license as the project.

## Recognition

Contributors will be acknowledged in:
- README.md credits section
- Release notes
- In-game credits (for major contributions)

Thank you for contributing to Finance Frenzy! 🎮💰
