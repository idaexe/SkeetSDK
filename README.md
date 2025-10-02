# SkeetSDK

---
## TL;DR
- **The Point:** To make building addons for skeet way easier, without ever having to touch the DLL file.
- **How it Works:** It uses sig scanning to find the cheat's functions in memory after it's injected, then hooks them on-the-fly.
- **What You Get:** A clean, ready-to-use API to add UI elements, draw your own visuals, and interact with the cheat and the game directly.
- **The Payoff:** You can focus on coding actual features instead of wasting your life reverse engineering and patching the binary every time something changes.

---

### Table of Contents

1.  **[Introduction](#1-introduction)**
    *   [1.1. The Problem We All Hate](#11-the-problem-we-all-hate)
    *   [1.2. Why This SDK Exists](#12-why-this-sdk-exists)
2.  **[Getting Set Up](#2-getting-set-up)**
    *   [2.1. Your Toolbox](#21-your-toolbox)
    *   [2.2. Project Setup](#22-project-setup)
3.  **TODO [How It All Works (The Core Concepts)](#3-how-it-all-works-the-core-concepts)**
    *   TODO [3.1. Kicking Things Off](#31-kicking-things-off)
    *   TODO [3.2. Memory Management](#32-memory-management)
    *   TODO [3.3. Sig Scanning & Hooking](#33-sig-scanning--hooking)

---

### **1. Introduction**

#### **1.1. The Problem We All Hate**
Have you ever tried making an addon for skeet? It sucks, you have to reverse-engineer the DLL, patch it, you have constant crashes, you have to find offsets, etc. It's a slow and annoying process that kills the fun of coding (for some) and makes developing addons a nightmare.

#### **1.2. Why This SDK Exists**
SkeetSDK was made to fix that. Instead of messing with the DLL file on your disk, this SDK lets you hook into the cheat *while it's running*. We give you a high-level API to talk directly to the cheat. That means you can add your own buttons, draw your own ESP, and script whatever you want without the headache.

The goal is simple: make the creation of addons for skeet fast, stable, and actually enjoyable, so you can spend less time RE'ing and more time creating cool projects.

### **2. Getting Set Up**

#### **2.1. Your Toolbox**
To get started, you'll need:
*   **IDE:** CLion or VS Code
*   **Build System:** CMake
*   **Compiler:** Visual Studio Build Tools (MSVC)
*   **Language:** C++20 / C++23
*   **Version Control:** Git

#### **2.2. Project Setup**
1.  First, clone the repo with Git.
2.  Follow the instructions for your IDE of choice below.

**For CLion Users:**
*   Just open the project folder in CLion. It should automatically detect the `CMakeLists.txt` and set everything up for you.
*   Make sure your toolchain is configured to use the MSVC compiler from your Visual Studio install.
*   Hit build. If it compiles, you're good to go.

**For VS Code Users:**
*   Open the project folder in VS Code.
*   You'll need a couple of extensions. Go to the Extensions tab (Ctrl+Shift+X) and install the **C/C++ Extension Pack** and **CMake Tools**.
*   After they're installed, VS Code will probably ask you to select a "kit." A kit is just your compiler. Look for something like **Visual Studio... amd64** or similar. If it doesn't ask, you can run the `CMake: Select a Kit` command from the command palette (Ctrl+Shift+P).
*   Once the kit is selected, CMake Tools will configure the project. You can see the build/debug buttons on the bottom status bar.
*   Hit the **Build** button. If everything compiles in the output window without errors, you're ready to start coding.

**For VS Users:**
*   Soon I'll be making a branch for Visual Studio 2022 and Visual Studio 2025 Preview with .slnx.
