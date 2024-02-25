#include "blackjackcontroller.hpp"
#include <sstream>

void BlackJackController::playGame() {
    while (game_.getState() != BlackJackGame::GameState::Exit) {
        processGameState();
        view_.displayActionPrompt();
        Action action = getUserAction();
        processPlayerAction(action);
    }
}

Action BlackJackController::getUserAction() {
    std::string input;
    char character;
    std::getline(std::cin, input);
    std::istringstream stream(input);
    if (stream >> character) {
        switch (character) {
            case 'h':
                return Action::Hit;
            case 's':
                return Action::Stand;
            case 'q':
                return Action::Quit;
            default:
                return Action::BadInput;
        }
    } else {
        return Action::Error;
    }
}


void BlackJackController::processPlayerAction(Action action) {
    switch(action) {
        case Action::Hit: {
            game_.hitPlayer();
            view_.displayAction(action, game_);
            break;
        }
        case Action::Stand:
            view_.displayAction(action, game_);
            while (game_.getState() == BlackJackGame::GameState::Ongoing) {
                game_.hitDealer();
                view_.displayDealtHand(game_.getDealer(), game_);
                view_.displayHands(game_); 
            }
            break;
        case Action::Quit:
            game_.exit();
            view_.displayAction(action, game_);
            break;
        default:
            view_.displayAction(action, game_);
            break;
    }
}

void BlackJackController::processGameState() {
    const BlackJackGame::GameState gameState = game_.getState();
    switch(gameState) {
        case BlackJackGame::GameState::Start: {
            startNewGame("Welcome to Blackjack game");
            break;
        }
        case BlackJackGame::GameState::DealerBusts:
        case BlackJackGame::GameState::DealerWins:
        case BlackJackGame::GameState::PlayerBusts:
        case BlackJackGame::GameState::PlayerWins:
        case BlackJackGame::GameState::Tie: {
            view_.displayGameState(gameState);
            startNewGame("\nStarting a new Blackjack game");
            break;
        }
        case BlackJackGame::GameState::Exit:
            view_.displayGameState(gameState);
            break;
        default:
            return;
    }
    
}

void BlackJackController::startNewGame(const std::string& message) {
    view_.displayMessage(message);
    game_.startGame();
    view_.displayInitialHand(game_);
}