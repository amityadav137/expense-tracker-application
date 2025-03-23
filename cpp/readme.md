# Expense Tracker Application

A simple Expense Tracker application built in C++. This guide provides step-by-step instructions to set up your development environment and run the application on macOS (or Linux) and Windows.

---

## Table of Contents

- [Prerequisites](#prerequisites)
- [Environment Setup](#environment-setup)
  - [macOS / Linux](#macos--linux)
  - [Windows](#windows)
- [Compilation and Running](#compilation-and-running)
  - [macOS / Linux](#macos--linux-1)
  - [Windows](#windows-1)
- [Additional Information](#additional-information)

---

## Prerequisites

- **C++ Compiler:**  
  - macOS: Install [clang](https://clang.llvm.org/) via Xcode Command Line Tools or g++ (if installed via Homebrew).  
  - Windows: Install a compiler such as g++ through MinGW.
- **Visual Studio Code (VS Code):**  
  - Ensure you have VS Code installed.
  - Install the **C/C++** extension by Microsoft from the Extensions Marketplace.

---

## Environment Setup

### macOS / Linux

1. **Install the Compiler:**  
   Open Terminal and run:
   ```bash
   xcode-select --install
   ```
   This command installs the Xcode Command Line Tools, which include the clang compiler. If you prefer using g++ (installed via Homebrew or another package manager), you can do so.

2. **Install VS Code Extensions:**  
   - Open VS Code.
   - Click on the Extensions icon (or press ⇧⌘X).
   - Search for **"C/C++"** (by Microsoft) and install the extension.

### Windows

1. **Setup the C++ Environment:**  
   Follow the instructions provided in the [VS Code C++ configuration for MinGW](https://code.visualstudio.com/docs/cpp/config-mingw) guide to set up your environment.

---

## Compilation and Running

### macOS / Linux

1. **Compile the Application:**  
   Open Terminal, navigate to your project directory, and run:
   ```bash
   g++ -std=c++20 main.cpp ExpenseTracker.cpp ExpenseStorage.cpp -o ExpenseTrackerApp
   ```
   > **Note:** The output executable is named `ExpenseTrackerApp`. Make sure to use the same name when running the application.

2. **Run the Application:**  
   From the same directory, execute:
   ```bash
   ./ExpenseTrackerApp
   ```

### Windows

1. **Compile the Application:**  
   Open Command Prompt, navigate to your project directory, and run:
   ```bash
   g++ -std=c++20 main.cpp ExpenseTracker.cpp ExpenseStorage.cpp -o ExpenseTrackerApp
   ```
   > **Note:** Although the compile command names the executable as `ExpenseTrackerApp`, the provided instructions indicate running the executable as `ExpenseTracker.exe`. Ensure that your output name is consistent with the command you use to run the application.

2. **Run the Application:**  
   From the same directory, execute:
   ```bash
   ExpenseTracker.exe
   ```

---

## Additional Information

- **Executable Name:**  
  Verify that the output executable name in your compilation command matches the command used to run the application.
- **Further Customization:**  
  You can modify this README as needed to include additional information such as troubleshooting, contributing guidelines, or licensing details.

