# Blackjack Game

## Overview
This Blackjack game is a console-based card game implemented in C++ using the Model-View-Controller (MVC) design pattern. It allows a player to play a simplified version of Blackjack against a dealer (controlled by the game logic).

## Structure
The application follows the MVC pattern:

1. **Model (`BlackJackGame`)**: Handles the game's logic and state.
2. **View (`BlackJackView`)**: Manages display and user interactions.
3. **Controller (`BlackJackController`)**: Mediates between the model and view.

### Key Files
- `blackjackgame.hpp/cpp`
- `blackjackview.hpp/cpp`
- `blackjackcontroller.hpp/cpp`
- `player.hpp/cpp`
- `card.hpp/cpp`

## How to Play
- Compile and run the executable.
- Follow prompts to hit (`h`), stand (`s`), or quit (`q`).
- Aim to have a hand value closer to 21 than the dealer's.

## Compilation and Execution
Ensure you have a C++ compiler and CMake installed. Compile the project using CMake and run the generated executable.

1. Navigate to the project directory.
2. Create a build directory and navigate into it: mkdir build && cd build
3. Run CMake: cmake ..
4. Compile the project: make
5. Run the game: ./blackjack

## Dependencies
- C++17 Standard Library
- CMake

## Author
Sami Härkönen

