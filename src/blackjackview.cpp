#include "blackjackview.hpp"
#include <sstream>

void BlackJackView::displayInitialHand(const BlackJackGame& game) {
    displayMessage("Initial draw:");
    displayHand(game.getPlayer());
    displayHand(game.getDealer());
}

void BlackJackView::displayHand(const Player& player) {
    std::ostringstream oss;
    oss << player.getName() << "'s hand: ";
    displayMessage(oss.str());
    player.printHand();
}

void BlackJackView::displayDealtHand(const Player& player, const BlackJackGame& game) {
    const Card card = game.getDealtCard();
    std::ostringstream oss;
    oss << player.getName() << " dealt: " << card.getRank() << " of " << card.getSuit();
    displayMessage(oss.str());
}

void BlackJackView::displayHands(const BlackJackGame& game) {
    displayHand(game.getPlayer());
    displayHand(game.getDealer());
}

void BlackJackView::displayActionPrompt() {
    displayMessage("Select action (h = hit, s = stand, q = quit)");
}

void BlackJackView::displayAction(const Action &action, const BlackJackGame& game) {
    switch (action) {
        case Action::Hit: {
            displayDealtHand(game.getPlayer(), game);
            displayHands(game);
        }
        case Action::Stand: {
            displayMessage("Player stands!");
            displayHands(game);
        }
        case Action::Quit:
            displayMessage("Thank you for playing! Exiting...");
       
    }
}

void BlackJackView::displayGameState(const BlackJackGame& game) {
    switch (game.getState()) {
        case BlackJackGame::GameState::PlayerWins: 
            displayMessage("Player wins!");
            break;
        case BlackJackGame::GameState::PlayerBusts:
            displayMessage("Player busts!");
            displayMessage("Dealer wins!");
            break;
        case BlackJackGame::GameState::DealerWins:
            displayMessage("Dealer wins!");
            break;
        case BlackJackGame::GameState::DealerBusts:
            displayMessage("Dealer busts!");
            displayMessage("Player wins!");

            break;
        case BlackJackGame::GameState::Tie:
            displayMessage("Tie");
            break;
        default:
            break;
        
    }
}

void BlackJackView::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}