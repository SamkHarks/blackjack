#ifndef BLACKJACKVIEW_HPP
#define BLACKJACKVIEW_HPP

#include "blackjackgame.hpp"

class BlackJackView {
public:
    void displayInitialHand(const BlackJackGame& game);
    void displayHand(const Player& player);
    void displayHands(const BlackJackGame& game);
    void displayDealtHand(const Player& player, const BlackJackGame& game);
    void displayAction(const Action& action, const BlackJackGame& game);
    void displayGameState(const BlackJackGame::GameState& gameState);
    void displayActionPrompt();
    void displayMessage(const std::string& message);
};

#endif