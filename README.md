# HMI Simulation System
 
This project implements a Human-Machine Interface (HMI) simulation system in C++. The system includes a menu navigation system, a vehicle data display, an event handling system for touchscreen input, and a skin customization feature. Each component is designed to simulate functionalities commonly found in automotive HMI clusters.
 
## Table of Contents
 
- [Objectives](#objectives)
- [Tasks](#tasks)
- [Requirements](#requirements)
- [Usage](#usage)
- [Installation](#installation)
- [Contributing](#contributing)
- [License](#license)
 
## Objectives
 
The primary objectives of this project are:
1. To build a hierarchical menu navigation system.
2. To simulate real-time vehicle data display.
3. To implement an event handling system for touchscreen interactions.
4. To create a skin customization system for theme management.
 
## Tasks
 
### Task 1: Build a Menu Navigation System
- **Description**: Implements a hierarchical menu structure using classes and data structures.
- **Features**:
  - Navigate through menu levels (up, down, enter, back).
  - Display current menu options on the console.
  - Keyboard-based interaction for navigation.
 
### Task 2: Simulate an Instrument Cluster Data Display
- **Description**: Creates a simplified data display system to show vehicle parameters.
- **Features**:
  - Class-based design for vehicle data management.
  - Real-time updates for speed, fuel level, and engine temperature.
  - Display warnings for parameter thresholds.
 
### Task 3: Event Handling System for Touchscreen Input
- **Description**: Simulates an event-driven system for processing touchscreen inputs.
- **Features**:
  - Event class to represent user interactions.
  - Event queue for managing multiple events.
  - Processing and handling specific events (Tap, Swipe).
 
### Task 4: HMI Skin Customization System
- **Description**: Manages different themes or skins for an HMI display.
- **Features**:
  - Theme class to store attributes like colors and font size.
  - Multiple themes stored using `std::map`.
  - User interface for theme selection and preview.
 
## Requirements
 
- C++11 or higher
- A C++ compiler (e.g., g++, clang++)
- Standard library headers: `<iostream>`, `<map>`, `<string>`, `<vector>`, `<thread>`, `<queue>`, `<random>`, `<chrono>`
 
## Usage
 
To run the programs, compile each source file separately and execute the generated binaries. Below is an example command:
 
```bash
g++ -o menu_navigation menu_navigation.cpp
./menu_navigation
