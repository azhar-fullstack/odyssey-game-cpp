# Odyssey Game (C++)

A turn-based adventure game implemented in C++, demonstrating object-oriented programming, modular design, and interactive gameplay.

## 🎮 Game Overview
Odyssey Game is a console-based, turn-based RPG where players control entities, navigate a map, manage inventory, and engage in combat. The project showcases advanced C++ programming and game development concepts.

## ✨ Features
- **Turn-Based Combat:** Attack, use potions, swap weapons, and perform special moves.
- **Entity System:** Each character has stats (HP, defense, gold, condition, inventory, etc.).
- **Map Navigation:** Move your character across a grid-based map.
- **Inventory Management:** Use and swap items during gameplay.
- **OOP Design:** Modular code with classes for entities, game logic, and map.

## 🛠️ Technologies Used
- C++ (OOP, STL)
- Modular design (multiple .cpp/.h files)
- Console I/O

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)

### Build Instructions
#### Using Makefile (recommended)
```bash
make
```
#### Or compile manually:
```bash
g++ -o game Entity.cpp Game.cpp Map.cpp GameDriver.cpp
```

### Run the Game
```bash
./game
```
Or on Windows:
```bash
game.exe
```

## 🎮 Controls
- Follow on-screen prompts to:
  - Attack
  - Use Potion
  - Swap Weapon
  - Attempt to Run
  - Special Attack
- Input choices as numbers when prompted.

## 📁 Project Structure
```
odyssey-game-cpp/
├── Entity.cpp/.h      # Entity class (player/enemy)
├── Game.cpp/.h        # Game logic
├── Map.cpp/.h         # Map and navigation
├── GameDriver.cpp     # Main entry point
├── game.exe           # Compiled executable (ignore in repo)
└── README.md          # This file
```

## 🧑‍💻 Skills Demonstrated
- C++ OOP (classes, encapsulation)
- Modular code organization
- Game loop and state management
- Interactive CLI design
- Inventory and combat systems


```

## 📄 License
This project is open source and available under the MIT License.

---
**Author:** Azhar Mehmood
**Language:** C++
**Category:** Game Development, Algorithms, Interactive Systems 
