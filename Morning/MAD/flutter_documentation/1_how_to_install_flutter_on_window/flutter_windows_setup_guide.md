# 🚀 Flutter Complete Setup Guide for Windows
### End-to-End Installation, Configuration & Commands Reference
> **Last updated:** October 2026 | **Flutter Stable:** 3.47.1 (Dart 3.13.1) | **Windows:** 10/11 (64-bit)

---

## 📋 Table of Contents

1. [System Requirements](#1-system-requirements)
2. [Prerequisites – Install Git](#2-prerequisites--install-git)
3. [Install Flutter SDK](#3-install-flutter-sdk)
   - [Method A: Via VS Code (Recommended)](#method-a-via-vs-code-recommended)
   - [Method B: Manual Download & Extract](#method-b-manual-download--extract)
   - [Method C: Clone via Git](#method-c-clone-via-git)
4. [Set Up PATH Environment Variable](#4-set-up-path-environment-variable)
5. [Install & Configure Android Studio](#5-install--configure-android-studio)
6. [Install & Configure VS Code](#6-install--configure-vs-code)
7. [Install Visual Studio (Windows Desktop Dev)](#7-install-visual-studio-windows-desktop-dev)
8. [Run Flutter Doctor](#8-run-flutter-doctor)
9. [Create Your First Flutter App](#9-create-your-first-flutter-app)
10. [Flutter CLI Commands – Complete Reference](#10-flutter-cli-commands--complete-reference)
11. [VS Code Commands & Shortcuts](#11-vs-code-commands--shortcuts)
12. [PowerShell Commands for Flutter](#12-powershell-commands-for-flutter)
13. [CMD Commands for Flutter](#13-cmd-commands-for-flutter)
14. [Android Emulator Commands](#14-android-emulator-commands)
15. [Flutter Build Commands](#15-flutter-build-commands)
16. [Troubleshooting Common Issues](#16-troubleshooting-common-issues)
17. [Useful Links & Resources](#17-useful-links--resources)

---

## 1. System Requirements

| Requirement | Minimum |
|---|---|
| **Operating System** | Windows 10 (64-bit) or Windows 11 |
| **RAM** | 8 GB (16 GB recommended) |
| **Disk Space** | 10 GB free (Flutter SDK ~2 GB + Android SDK ~8 GB) |
| **PowerShell** | 5.0 or newer (pre-installed on Windows 10/11) |
| **Git** | 2.x or later |
| **Screen Resolution** | 1280×800 minimum |

---

## 2. Prerequisites – Install Git

Flutter requires Git for version control and SDK management.

### Download Git for Windows
👉 **Download:** https://git-scm.com/download/win

### Installation Notes
- During setup, select **"Use Git from the Windows Command Prompt"**
- This ensures `git` is available in both CMD and PowerShell

### Verify Git Installation (PowerShell / CMD)
```powershell
git --version
# Expected output: git version 2.x.x.windows.x
```

---

## 3. Install Flutter SDK

### Method A: Via VS Code (Recommended)

This is the **fastest and easiest** method.

1. Install VS Code first → https://code.visualstudio.com/download
2. Install the Flutter extension (search `Flutter` in Extensions panel)
3. Open the **Command Palette** (`Ctrl + Shift + P`)
4. Type: `Flutter: New Project`
5. VS Code will prompt: **"Download SDK"** → click it
6. Choose a folder (e.g., `C:\dev\flutter` or `%USERPROFILE%\dev`)
7. VS Code downloads and initializes the SDK automatically
8. When prompted **"Do you want to add the Flutter SDK to PATH?"** → click **"Add SDK to PATH"**
9. Close and reopen all PowerShell windows

---

### Method B: Manual Download & Extract

#### Step 1 – Download the Flutter SDK
👉 **Official Download Page:** https://docs.flutter.dev/get-started/install/windows/desktop

Direct link to SDK Archive (all versions):
👉 https://docs.flutter.dev/release/archive

```
Latest stable: Flutter 3.47.1 (August 2026)
File: flutter_windows_3.47.1-stable.zip (~500 MB)
```

#### Step 2 – Extract to a Safe Location

> ⚠️ **DO NOT extract to:**
> - `C:\Program Files\` (requires admin rights)
> - Any path with **spaces** or **special characters**
> - `C:\Users\<YourName>\Downloads\` (bad for permanent install)

**Recommended locations:**
```
C:\dev\flutter
C:\src\flutter
%USERPROFILE%\dev\flutter
```

#### Step 3 – Extract via PowerShell

```powershell
# Create target directory
New-Item -ItemType Directory -Force -Path "$env:USERPROFILE\dev"

# Extract the downloaded zip (adjust filename as needed)
Expand-Archive -Path "$env:USERPROFILE\Downloads\flutter_windows_3.47.1-stable.zip" `
               -Destination "$env:USERPROFILE\dev\"
```

After extraction, Flutter SDK will be at:
```
%USERPROFILE%\dev\flutter\
```

---

### Method C: Clone via Git

```powershell
# Create directory and clone stable channel
git clone https://github.com/flutter/flutter.git -b stable C:\dev\flutter
```

---

## 4. Set Up PATH Environment Variable

This lets you run `flutter` commands from **any** terminal window.

### Method 1: Via PowerShell (Permanent, User-Level)

```powershell
# Add Flutter bin to the user PATH permanently
[Environment]::SetEnvironmentVariable(
  "PATH",
  "$env:PATH;$env:USERPROFILE\dev\flutter\bin",
  "User"
)

# Verify it was added
$env:PATH -split ";" | Select-String "flutter"

# Reload PATH in current session
$env:PATH = [Environment]::GetEnvironmentVariable("PATH", "User") + ";" + [Environment]::GetEnvironmentVariable("PATH", "Machine")
```

### Method 2: Via GUI (Recommended for Beginners)

1. Press `Windows + Pause` → **Advanced System Settings**
   *or* search **"Edit the system environment variables"** in Start
2. Click **"Environment Variables..."**
3. Under **User variables**, find and select **`Path`** → click **Edit**
4. Click **New** and type:
   ```
   %USERPROFILE%\dev\flutter\bin
   ```
   *(adjust if you installed elsewhere, e.g., `C:\dev\flutter\bin`)*
5. Click **OK** on all dialogs
6. **Close and reopen** all terminal windows

### Method 3: Temporary (Current Session Only)

```powershell
# Temporary – only lasts for current PowerShell session
$env:PATH += ";$env:USERPROFILE\dev\flutter\bin"
```

### Verify Flutter is in PATH

```powershell
flutter --version
# Expected output:
# Flutter 3.47.1 • channel stable • https://github.com/flutter/flutter.git
# Framework • revision xxxxx • 2026-08-xx
# Engine • revision xxxxx
# Tools • Dart 3.13.1 • DevTools x.x.x
```

---

## 5. Install & Configure Android Studio

Android Studio provides the Android SDK, emulator, and build tools required by Flutter.

### Download Android Studio
👉 **Download:** https://developer.android.com/studio

### Installation Steps

1. Run the installer
2. In the setup wizard, ensure these are **checked**:
   - ✅ Android SDK
   - ✅ Android SDK Platform
   - ✅ Android Virtual Device (AVD)
3. Complete the **Android Studio Setup Wizard** (installs SDK components automatically)

### Install Required SDK Components

After Android Studio opens:

1. Go to **File → Settings → Appearance & Behavior → System Settings → Android SDK**
   *(or from the welcome screen: **More Options → SDK Manager**)*
2. Click the **SDK Platforms** tab → check **Android API 35** (or latest)
3. Click the **SDK Tools** tab → ensure these are **checked**:
   - ✅ Android SDK Command-line Tools
   - ✅ Android SDK Build-Tools
   - ✅ Android SDK Platform-Tools
   - ✅ Android Emulator
4. Click **Apply** → **OK**

### Accept Android Licenses (PowerShell / CMD)

```powershell
flutter doctor --android-licenses
# Press 'y' and Enter to accept each license
```

### Set Android SDK Path in Flutter (if needed)

```powershell
# If Flutter can't find the Android SDK, set it manually
flutter config --android-sdk "C:\Users\<YourName>\AppData\Local\Android\Sdk"

# Verify the path
flutter config --list
```

---

## 6. Install & Configure VS Code

### Download VS Code
👉 **Download:** https://code.visualstudio.com/download

### Install Flutter & Dart Extensions

**Method 1 – Via VS Code UI:**
1. Open VS Code
2. Click the **Extensions** icon (sidebar) or press `Ctrl + Shift + X`
3. Search `Flutter` → click **Install** on the official Flutter extension
   (The **Dart** extension installs automatically alongside it)

**Method 2 – Via VS Code Command Palette:**
1. Press `Ctrl + Shift + P`
2. Type: `ext install Dart-Code.flutter`
3. Press Enter

**Method 3 – Via PowerShell (VS Code CLI):**
```powershell
code --install-extension Dart-Code.flutter
code --install-extension Dart-Code.dart-code
```

### Recommended Additional VS Code Extensions for Flutter

```powershell
# Install all recommended extensions via PowerShell
code --install-extension Dart-Code.flutter
code --install-extension Dart-Code.dart-code
code --install-extension nash.awesome-flutter-snippets
code --install-extension felixangelov.bloc
code --install-extension usernamehw.errorlens
code --install-extension aaron-bond.better-comments
code --install-extension ms-vscode.vscode-json
code --install-extension PKief.material-icon-theme
code --install-extension esbenp.prettier-vscode
code --install-extension streetsidesoftware.code-spell-checker
```

| Extension | Publisher | Purpose |
|---|---|---|
| Flutter | Dart Code | Core Flutter support |
| Dart | Dart Code | Dart language support |
| Awesome Flutter Snippets | Nash | Speed up widget coding |
| bloc | Felix Angelov | BLoC pattern support |
| Error Lens | Alexander | Inline error highlighting |
| Better Comments | Aaron Bond | Color-coded comments |
| Material Icon Theme | PKief | Better file icons |
| Pubspec Assist | Jeroen Meijer | Quick pub.dev package adding |

### Validate Flutter in VS Code

1. Open **Command Palette** (`Ctrl + Shift + P`)
2. Type: `Flutter: Run Flutter Doctor`
3. View the output in the terminal panel

---

## 7. Install Visual Studio (Windows Desktop Dev)

Required **only** if you want to build Flutter apps for **Windows desktop**.

### Download Visual Studio (Community Edition – Free)
👉 **Download:** https://visualstudio.microsoft.com/downloads/

> ⚠️ **Note:** This is **Visual Studio** (full IDE), NOT **VS Code**.
> Both can be installed side-by-side.

### Required Workload During Installation

- ✅ **Desktop development with C++**

This installs the Windows SDK and C++ build tools needed for Flutter Windows apps.

### Verify in Flutter

```powershell
flutter doctor -v
# Look for: [✓] Visual Studio - develop Windows apps
```

---

## 8. Run Flutter Doctor

`flutter doctor` is the **diagnostic command** that checks your entire setup.

```powershell
# Basic check
flutter doctor

# Verbose output (recommended – shows full details)
flutter doctor -v
```

### Understanding the Output

```
[✓] Flutter (Channel stable, 3.47.1, ...)   ← Flutter SDK OK
[✓] Windows version                           ← Windows 10/11 OK
[✓] Android toolchain                         ← Android SDK OK
[✓] Chrome                                    ← Web dev OK
[✓] Visual Studio                             ← Windows desktop OK
[✓] Android Studio (version 2024.x)           ← Android Studio OK
[✓] VS Code (version x.x)                     ← VS Code OK
[✓] Connected device (3 available)            ← Devices found
• No issues found!
```

### Fix Common Doctor Issues

```powershell
# Fix: cmdline-tools missing
# → Open Android Studio → SDK Manager → SDK Tools → check "Android SDK Command-line Tools" → Apply

# Fix: licenses not accepted
flutter doctor --android-licenses

# Fix: Visual Studio missing C++ tools
# → Open Visual Studio Installer → Modify → Add "Desktop development with C++"

# Fix: Android SDK not found
flutter config --android-sdk "C:\Users\<YourName>\AppData\Local\Android\Sdk"
```

---

## 9. Create Your First Flutter App

```powershell
# Navigate to your projects folder
cd C:\Projects        # or wherever you keep projects

# Create a new Flutter app
flutter create my_first_app

# Navigate into the project
cd my_first_app

# List available devices
flutter devices

# Run the app (select device interactively)
flutter run

# Run on a specific device
flutter run -d windows         # Windows desktop
flutter run -d chrome          # Web browser
flutter run -d emulator-5554   # Android emulator
```

---

## 10. Flutter CLI Commands – Complete Reference

### Project Commands

```powershell
# Create a new project
flutter create <project_name>

# Create with custom organization (sets app bundle ID)
flutter create --org com.yourcompany --project-name myapp myfolder

# Create with a description
flutter create --org com.example --description "My Flutter App" my_app

# Create a Flutter plugin (package with native code)
flutter create --template=plugin my_plugin

# Create a Flutter package (pure Dart)
flutter create --template=package my_package

# Create a desktop-only project
flutter create --platforms=windows,macos,linux my_desktop_app
```

### Running the App

```powershell
# Run on default/selected device
flutter run

# Run on specific device
flutter run -d <device_id>
flutter run -d chrome
flutter run -d windows
flutter run -d emulator-5554

# Run in debug mode (default)
flutter run --debug

# Run in profile mode (performance testing)
flutter run --profile

# Run in release mode
flutter run --release

# Run with verbose output
flutter run --verbose

# Run a specific dart file
flutter run lib/main.dart

# Hot reload shortcut (while running)
# Press: r   → Hot reload
# Press: R   → Hot restart
# Press: q   → Quit
# Press: d   → Detach
# Press: h   → Help
```

### Package / Dependency Management

```powershell
# Get all packages listed in pubspec.yaml
flutter pub get

# Upgrade all packages to latest compatible versions
flutter pub upgrade

# Upgrade a specific package
flutter pub upgrade <package_name>

# Add a package
flutter pub add <package_name>

# Add a dev dependency
flutter pub add --dev <package_name>

# Remove a package
flutter pub remove <package_name>

# Check for outdated packages
flutter pub outdated

# Publish a package to pub.dev
flutter pub publish

# Run a pub command
flutter pub <command>

# Clear the pub cache
flutter pub cache clean
flutter pub cache repair
```

### Building the App

```powershell
# Build Android APK (debug)
flutter build apk

# Build Android APK (release – signed)
flutter build apk --release

# Build Android APK split by ABI (smaller files)
flutter build apk --split-per-abi --release

# Build Android App Bundle (for Google Play)
flutter build appbundle
flutter build appbundle --release

# Build for Windows desktop
flutter build windows
flutter build windows --release

# Build for Web
flutter build web
flutter build web --release

# Build for Linux
flutter build linux --release

# Build for macOS (macOS only)
flutter build macos --release
```

### Testing

```powershell
# Run all tests
flutter test

# Run a specific test file
flutter test test/widget_test.dart

# Run tests with coverage
flutter test --coverage

# Run integration tests
flutter drive --target=test_driver/app.dart

# Run tests with verbose output
flutter test --verbose
```

### Code Quality & Analysis

```powershell
# Analyze code for errors/warnings
flutter analyze

# Analyze a specific directory
flutter analyze lib/

# Format Dart code
dart format .
dart format lib/

# Format a specific file
dart format lib/main.dart
```

### Device & Emulator Management

```powershell
# List all connected devices and emulators
flutter devices

# List available emulators
flutter emulators

# Launch a specific emulator
flutter emulators --launch <emulator_id>

# Create an Android emulator
flutter emulators --create --name MyEmulator

# List all emulators with details
flutter emulators --verbose
```

### Flutter SDK Management

```powershell
# Check Flutter version
flutter --version

# Upgrade Flutter to latest on current channel
flutter upgrade

# Show available channels (stable, beta, master/main)
flutter channel

# Switch to stable channel
flutter channel stable

# Switch to beta channel
flutter channel beta

# Switch to master/main (bleeding edge)
flutter channel master

# Downgrade to a previous version (after flutter upgrade)
flutter downgrade

# Clean the Flutter tool cache
flutter clean
```

### Miscellaneous Commands

```powershell
# Clean build artifacts
flutter clean

# Show all flutter commands
flutter --help
flutter -h

# Help for a specific command
flutter help <command>
flutter help build
flutter help run

# Show verbose help
flutter --help --verbose

# Configure Flutter settings
flutter config --list                             # List all config
flutter config --build-dir=<DIRECTORY>           # Custom build dir
flutter config --android-sdk <path>              # Set Android SDK path
flutter config --enable-web                      # Enable web support
flutter config --enable-windows-desktop          # Enable Windows support
flutter config --enable-linux-desktop            # Enable Linux support
flutter config --enable-macos-desktop            # Enable macOS support

# Generate localization files
flutter gen-l10n

# Assemble resources
flutter assemble

# Screenshot from connected device
flutter screenshot

# Create bug report
flutter run --bug-report

# Check version info
flutter --version
dart --version

# Generate code (build_runner)
flutter pub run build_runner build
flutter pub run build_runner build --delete-conflicting-outputs
flutter pub run build_runner watch
flutter pub run build_runner watch --delete-conflicting-outputs
```

---

## 11. VS Code Commands & Shortcuts

### Command Palette Commands (Ctrl + Shift + P)

| Command | Description |
|---|---|
| `Flutter: New Project` | Create a new Flutter project |
| `Flutter: New Project (Application)` | New Flutter app project |
| `Flutter: New Project (Module)` | New Flutter module |
| `Flutter: New Project (Package)` | New Flutter package |
| `Flutter: New Project (Plugin)` | New Flutter plugin |
| `Flutter: Run Flutter Doctor` | Run `flutter doctor` in terminal |
| `Flutter: Select Device` | Pick which device to run on |
| `Flutter: Launch Emulator` | Start an Android emulator |
| `Flutter: Hot Reload` | Hot reload running app |
| `Flutter: Hot Restart` | Hot restart running app |
| `Flutter: Toggle Debug Painting` | Show layout debug lines |
| `Flutter: Toggle Performance Overlay` | Show FPS/GPU overlay |
| `Flutter: Inspect Widget` | Open widget inspector |
| `Flutter: Open DevTools` | Open Flutter DevTools in browser |
| `Flutter: Open DevTools (Widget Inspector)` | Open widget inspector tab |
| `Flutter: Open DevTools (Timeline)` | Open performance timeline |
| `Flutter: Upgrade Packages` | Run `flutter pub upgrade` |
| `Flutter: Get Packages` | Run `flutter pub get` |
| `Flutter: Clean Project` | Run `flutter clean` |
| `Dart: Add Dependency` | Add a pub.dev package |
| `Dart: Format Document` | Format current Dart file |
| `Dart: Sort Members` | Sort class members |
| `Dart: Fix All` | Apply all auto-fixes |
| `Dart: Restart Analysis Server` | Restart Dart language server |

### Keyboard Shortcuts (Windows)

| Shortcut | Action |
|---|---|
| `F5` | Start debugging (run app) |
| `Shift + F5` | Stop debugging |
| `Ctrl + F5` | Run without debugging |
| `Ctrl + Shift + F5` | Restart debugging |
| `F9` | Toggle breakpoint |
| `F10` | Step over |
| `F11` | Step into |
| `Shift + F11` | Step out |
| `Ctrl + Shift + P` | Open Command Palette |
| `Ctrl + P` | Quick file open |
| `Ctrl + Shift + X` | Extensions panel |
| `Ctrl + \`` | Open terminal |
| `Ctrl + Shift + \`` | New terminal |
| `Ctrl + Space` | Trigger suggestions (autocomplete) |
| `Ctrl + .` | Quick fix / Code actions |
| `F2` | Rename symbol |
| `F12` | Go to definition |
| `Alt + F12` | Peek definition |
| `Shift + F12` | Find all references |
| `Ctrl + Shift + I` | Format document |
| `Ctrl + /` | Toggle line comment |
| `Ctrl + Shift + /` | Toggle block comment |
| `Alt + Up/Down` | Move line up/down |
| `Shift + Alt + Up/Down` | Copy line up/down |
| `Ctrl + D` | Select next occurrence |
| `Ctrl + Shift + L` | Select all occurrences |
| `Ctrl + Shift + K` | Delete line |
| `Ctrl + Z` | Undo |
| `Ctrl + Shift + Z` | Redo |
| `Ctrl + B` | Toggle sidebar |
| `Ctrl + J` | Toggle panel (terminal) |
| `Ctrl + Shift + E` | Explorer panel |
| `Ctrl + Shift + F` | Search across files |
| `Ctrl + Shift + G` | Source Control panel |
| `Ctrl + Shift + D` | Debug panel |

### Flutter-Specific Code Snippets (in VS Code)

| Snippet | Expands To |
|---|---|
| `stless` | StatelessWidget template |
| `stful` | StatefulWidget template |
| `build` | build() method |
| `initS` | initState() method |
| `dis` | dispose() method |
| `setState` | setState(() {}) block |
| `FutureBuilder` | FutureBuilder widget |
| `StreamBuilder` | StreamBuilder widget |
| `ListTile` | ListTile widget |
| `customscroll` | CustomScrollView template |

---

## 12. PowerShell Commands for Flutter

### Environment Setup

```powershell
# Check if Flutter is in PATH
$env:PATH -split ";" | Select-String "flutter"

# Add Flutter to PATH for current session
$env:PATH += ";$env:USERPROFILE\dev\flutter\bin"

# Add Flutter to PATH permanently (User level)
[Environment]::SetEnvironmentVariable(
  "PATH",
  "$([Environment]::GetEnvironmentVariable('PATH','User'));$env:USERPROFILE\dev\flutter\bin",
  "User"
)

# Add Flutter to PATH permanently (System level – requires Admin)
[Environment]::SetEnvironmentVariable(
  "PATH",
  "$([Environment]::GetEnvironmentVariable('PATH','Machine'));$env:USERPROFILE\dev\flutter\bin",
  "Machine"
)

# View current Flutter config
flutter config --list

# View environment variables
Get-ChildItem Env: | Where-Object { $_.Name -like "ANDROID*" }
Get-ChildItem Env:PATH
```

### Android SDK via PowerShell

```powershell
# Set ANDROID_HOME (Android SDK root)
[Environment]::SetEnvironmentVariable(
  "ANDROID_HOME",
  "$env:USERPROFILE\AppData\Local\Android\Sdk",
  "User"
)

# Set ANDROID_SDK_ROOT (same as ANDROID_HOME, older tools use this)
[Environment]::SetEnvironmentVariable(
  "ANDROID_SDK_ROOT",
  "$env:USERPROFILE\AppData\Local\Android\Sdk",
  "User"
)

# List installed SDK packages
& "$env:USERPROFILE\AppData\Local\Android\Sdk\cmdline-tools\latest\bin\sdkmanager.bat" --list

# Install specific SDK components
& "$env:USERPROFILE\AppData\Local\Android\Sdk\cmdline-tools\latest\bin\sdkmanager.bat" "platforms;android-35"
& "$env:USERPROFILE\AppData\Local\Android\Sdk\cmdline-tools\latest\bin\sdkmanager.bat" "platform-tools"
& "$env:USERPROFILE\AppData\Local\Android\Sdk\cmdline-tools\latest\bin\sdkmanager.bat" "build-tools;35.0.0"
& "$env:USERPROFILE\AppData\Local\Android\Sdk\cmdline-tools\latest\bin\sdkmanager.bat" "emulator"
```

### Download Flutter via PowerShell (Manual Method)

```powershell
# Create dev directory
New-Item -ItemType Directory -Force -Path "$env:USERPROFILE\dev"

# Download Flutter SDK (adjust version as needed)
$url = "https://storage.googleapis.com/flutter_infra_release/releases/stable/windows/flutter_windows_3.47.1-stable.zip"
$dest = "$env:USERPROFILE\Downloads\flutter_windows_3.47.1-stable.zip"
Invoke-WebRequest -Uri $url -OutFile $dest

# Extract to dev folder
Expand-Archive -Path $dest -Destination "$env:USERPROFILE\dev\" -Force

# Add to PATH
[Environment]::SetEnvironmentVariable(
  "PATH",
  "$([Environment]::GetEnvironmentVariable('PATH','User'));$env:USERPROFILE\dev\flutter\bin",
  "User"
)

Write-Host "Flutter installed! Restart your terminal and run: flutter doctor"
```

### Useful PowerShell Shortcuts

```powershell
# Navigate to project
Set-Location "C:\Projects\my_app"
cd "C:\Projects\my_app"          # shorthand

# Create project directory and navigate
New-Item -ItemType Directory "C:\Projects\my_app"
cd "C:\Projects\my_app"

# Check Flutter version
flutter --version

# Run Flutter Doctor
flutter doctor -v

# Create new project
flutter create my_app

# Run app
flutter run

# Build release APK
flutter build apk --release

# Open current directory in VS Code
code .

# Kill any running Dart processes (if Flutter hangs)
Get-Process | Where-Object { $_.Name -eq "dart" } | Stop-Process -Force
```

---

## 13. CMD Commands for Flutter

```cmd
REM Check Flutter version
flutter --version

REM Run Flutter Doctor
flutter doctor
flutter doctor -v

REM Create new project
flutter create my_app

REM Navigate to project
cd C:\Projects\my_app

REM Get packages
flutter pub get

REM Run app
flutter run

REM Run on Windows desktop
flutter run -d windows

REM Run on Chrome
flutter run -d chrome

REM List devices
flutter devices

REM List emulators
flutter emulators

REM Clean project
flutter clean

REM Build APK
flutter build apk --release

REM Build App Bundle
flutter build appbundle --release

REM Build Windows app
flutter build windows --release

REM Upgrade Flutter
flutter upgrade

REM Check channel
flutter channel

REM Switch channel
flutter channel stable

REM Accept Android licenses
flutter doctor --android-licenses

REM Set Android SDK path
flutter config --android-sdk "C:\Users\YourName\AppData\Local\Android\Sdk"

REM Open project in VS Code
code .

REM Build runner
flutter pub run build_runner build --delete-conflicting-outputs
```

---

## 14. Android Emulator Commands

### Via Flutter CLI

```powershell
# List available emulators
flutter emulators

# Launch an emulator
flutter emulators --launch Pixel_6_API_35

# Create a new emulator
flutter emulators --create --name "Pixel_8_API_35"

# Run app on emulator
flutter run -d emulator-5554
```

### Via ADB (Android Debug Bridge)

```powershell
# Path to ADB (adjust if needed)
$adb = "$env:USERPROFILE\AppData\Local\Android\Sdk\platform-tools\adb.exe"

# List connected devices/emulators
& $adb devices

# Check ADB version
& $adb version

# Start ADB server
& $adb start-server

# Kill ADB server (fix connection issues)
& $adb kill-server
& $adb start-server

# Install APK to device
& $adb install "C:\path\to\app-release.apk"

# Uninstall app from device
& $adb uninstall com.example.myapp

# Copy file to device
& $adb push "localfile.txt" "/sdcard/localfile.txt"

# Copy file from device
& $adb pull "/sdcard/file.txt" "C:\local\file.txt"

# Open shell on device
& $adb shell

# View device logs
& $adb logcat

# Reboot device
& $adb reboot

# Get device properties
& $adb shell getprop ro.product.model
```

### Via Android Emulator (Direct)

```powershell
$emulator = "$env:USERPROFILE\AppData\Local\Android\Sdk\emulator\emulator.exe"

# List available AVDs
& $emulator -list-avds

# Launch a specific AVD
& $emulator -avd Pixel_6_API_35

# Launch with options
& $emulator -avd Pixel_6_API_35 -no-snapshot-load
& $emulator -avd Pixel_6_API_35 -wipe-data
```

---

## 15. Flutter Build Commands

### Android

```powershell
# Debug APK
flutter build apk --debug

# Release APK (requires signing config)
flutter build apk --release

# Split APKs by CPU architecture (smaller download sizes)
flutter build apk --split-per-abi --release

# Build outputs to:
# build/app/outputs/flutter-apk/app-release.apk
# build/app/outputs/flutter-apk/app-arm64-v8a-release.apk  (64-bit)
# build/app/outputs/flutter-apk/app-armeabi-v7a-release.apk (32-bit)
# build/app/outputs/flutter-apk/app-x86_64-release.apk

# Android App Bundle (for Google Play Store)
flutter build appbundle --release
# Output: build/app/outputs/bundle/release/app-release.aab

# Build with a flavor
flutter build apk --flavor production --release
```

### Windows Desktop

```powershell
# Build Windows executable
flutter build windows

# Release build
flutter build windows --release

# Output location:
# build\windows\x64\runner\Release\<AppName>.exe
```

### Web

```powershell
# Build for web
flutter build web

# Release build
flutter build web --release

# Build with HTML renderer (better compatibility)
flutter build web --web-renderer html --release

# Build with CanvasKit renderer (better quality)
flutter build web --web-renderer canvaskit --release

# Output: build/web/ directory
```

---

## 16. Troubleshooting Common Issues

### Issue: `flutter` not recognized after installation

```powershell
# Check if flutter\bin is in PATH
$env:PATH -split ";" | Select-String "flutter"

# If missing, add it
[Environment]::SetEnvironmentVariable(
  "PATH",
  "$([Environment]::GetEnvironmentVariable('PATH','User'));$env:USERPROFILE\dev\flutter\bin",
  "User"
)

# Restart PowerShell completely, then test
flutter --version
```

---

### Issue: `cmdline-tools component is missing`

1. Open **Android Studio**
2. Go to **File → Settings → Appearance & Behavior → System Settings → Android SDK**
3. Click **SDK Tools** tab
4. Check **"Android SDK Command-line Tools (latest)"**
5. Click **Apply** → **OK**

```powershell
# Then re-run
flutter doctor --android-licenses
flutter doctor -v
```

---

### Issue: Android licenses not accepted

```powershell
flutter doctor --android-licenses
# Type 'y' and press Enter for each license prompt
```

---

### Issue: No connected devices

```powershell
# Check connected devices
flutter devices

# Enable Windows desktop (if not showing)
flutter config --enable-windows-desktop
flutter devices

# Enable web
flutter config --enable-web
flutter devices
```

---

### Issue: `Waiting for another flutter command to release the startup lock`

```powershell
# Find and delete the lockfile
Remove-Item -Force "$env:USERPROFILE\dev\flutter\bin\cache\.flutter_tool_state"

# Or kill all Dart processes
Get-Process | Where-Object { $_.Name -eq "dart" } | Stop-Process -Force

# Then retry your command
flutter pub get
```

---

### Issue: Slow `flutter pub get` / pub.dev unreachable

```powershell
# Clear pub cache
flutter pub cache clean

# Repair pub cache
flutter pub pub cache repair

# Try again
flutter pub get
```

---

### Issue: `Unable to locate Android SDK`

```powershell
# Set Android SDK path explicitly
flutter config --android-sdk "$env:USERPROFILE\AppData\Local\Android\Sdk"

# Verify
flutter doctor -v
```

---

### Issue: Build fails with Gradle errors

```powershell
# Clean the project
flutter clean

# Delete Gradle caches (PowerShell)
Remove-Item -Recurse -Force "$env:USERPROFILE\.gradle\caches"

# Re-get packages and rebuild
flutter pub get
flutter run
```

---

### Issue: `Visual Studio - develop Windows apps` missing

1. Download **Visual Studio Community**: https://visualstudio.microsoft.com/downloads/
2. During install, select **"Desktop development with C++"** workload
3. Re-run `flutter doctor -v`

---

## 17. Useful Links & Resources

### Official Documentation

| Resource | URL |
|---|---|
| Flutter Home | https://flutter.dev |
| Flutter Docs | https://docs.flutter.dev |
| Install Flutter (Windows) | https://docs.flutter.dev/get-started/install/windows/desktop |
| Install Flutter (Android on Windows) | https://docs.flutter.dev/get-started/install/windows/mobile |
| Install Flutter (Web on Windows) | https://docs.flutter.dev/get-started/install/windows/web |
| Flutter SDK Archive (all versions) | https://docs.flutter.dev/release/archive |
| Flutter CLI Reference | https://docs.flutter.dev/reference/flutter-cli |
| Flutter Release Notes | https://docs.flutter.dev/release/release-notes |
| Flutter Cookbook | https://docs.flutter.dev/cookbook |
| Flutter Samples | https://flutter.github.io/samples/ |

### Tools Downloads

| Tool | URL |
|---|---|
| Git for Windows | https://git-scm.com/download/win |
| VS Code | https://code.visualstudio.com/download |
| Android Studio | https://developer.android.com/studio |
| Visual Studio Community | https://visualstudio.microsoft.com/downloads/ |
| Java JDK (if needed) | https://adoptium.net/ |

### VS Code Extensions (Marketplace Links)

| Extension | URL |
|---|---|
| Flutter (Dart Code) | https://marketplace.visualstudio.com/items?itemName=Dart-Code.flutter |
| Dart (Dart Code) | https://marketplace.visualstudio.com/items?itemName=Dart-Code.dart-code |
| Awesome Flutter Snippets | https://marketplace.visualstudio.com/items?itemName=Nash.awesome-flutter-snippets |
| Flutter Riverpod Snippets | https://marketplace.visualstudio.com/items?itemName=robert-brunhage.flutter-riverpod-snippets |
| BloC Extension | https://marketplace.visualstudio.com/items?itemName=FelixAngelov.bloc |
| Error Lens | https://marketplace.visualstudio.com/items?itemName=usernamehw.errorlens |
| Better Comments | https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments |
| Material Icon Theme | https://marketplace.visualstudio.com/items?itemName=PKief.material-icon-theme |

### Learning Resources

| Resource | URL |
|---|---|
| Flutter Codelabs | https://docs.flutter.dev/codelabs |
| Write Your First Flutter App | https://docs.flutter.dev/get-started/codelab |
| Flutter YouTube Channel | https://www.youtube.com/@flutterdev |
| Dart Language Tour | https://dart.dev/language |
| Dart Documentation | https://dart.dev/guides |
| pub.dev (Package Repository) | https://pub.dev |
| Flutter Community on Reddit | https://www.reddit.com/r/FlutterDev |
| Flutter GitHub | https://github.com/flutter/flutter |
| Flutter Discord | https://discord.com/invite/google-dev-community |
| Flutter DevTools | https://docs.flutter.dev/tools/devtools/overview |

### VS Code Documentation

| Resource | URL |
|---|---|
| VS Code Flutter Docs | https://docs.flutter.dev/tools/vs-code |
| VS Code Keyboard Shortcuts (Windows PDF) | https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf |
| VS Code Tips & Tricks | https://code.visualstudio.com/docs/getstarted/tips-and-tricks |

### Android Development

| Resource | URL |
|---|---|
| Android Studio Guide | https://developer.android.com/studio/intro |
| ADB Documentation | https://developer.android.com/studio/command-line/adb |
| Android SDK Manager | https://developer.android.com/studio/command-line/sdkmanager |
| AVD Manager | https://developer.android.com/studio/command-line/avdmanager |

---

## ✅ Quick Setup Checklist

```
[ ] Windows 10/11 (64-bit) confirmed
[ ] Git for Windows installed & verified (git --version)
[ ] Flutter SDK downloaded & extracted (e.g., %USERPROFILE%\dev\flutter)
[ ] Flutter bin added to PATH
[ ] Flutter version verified (flutter --version)
[ ] Android Studio installed
[ ] Android SDK components installed (Platform, Build-Tools, CMD-Tools, Emulator)
[ ] Android licenses accepted (flutter doctor --android-licenses)
[ ] VS Code installed
[ ] Flutter & Dart extensions installed in VS Code
[ ] Visual Studio installed with "Desktop development with C++" (for Windows apps)
[ ] flutter doctor -v shows all green ✓
[ ] First app created (flutter create my_app)
[ ] App running successfully (flutter run)
```

---

*Guide compiled October 2026 | Flutter 3.47.1 | Dart 3.13.1*
*Official source: https://docs.flutter.dev/get-started/install/windows/desktop*
