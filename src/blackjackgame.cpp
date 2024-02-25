#include <sstream>
#include "blackjackgame.hpp"
#include "card.hpp"

const Player&  BlackJackGame::getPlayer() const {
    return player_;
}

const Player&  BlackJackGame::getDealer() const {
    return dealer_;
}

Card BlackJackGame::getDealtCard() const {
    return dealtCard_;
}

void BlackJackGame::setDealtCard(const Card& card) {
    dealtCard_ = card;
}

void BlackJackGame::draw(Player & player) {
    if (!deck_.empty()) {
        Card card = deck_.back();
        deck_.pop_back();
        player.drawCard(card);
        setDealtCard(card);
    } else {
        Card card(-1);
        setDealtCard(card);
    }
}

void BlackJackGame::hitPlayer() {
    draw(player_);
    updatePlayerState();
}

void BlackJackGame::hitDealer() {
    draw(dealer_);
    updateDealerState();
}

void BlackJackGame::updatePlayerState() {
    int playerHandValue = player_.getHandValue();
    int dealerHandValue = dealer_.getHandValue();
    if (playerHandValue > 21) {
        gameState_ = GameState::PlayerBusts;
    } else if (playerHandValue == 21 && dealerHandValue == playerHandValue) {
        gameState_ = GameState::Tie;
    } else {
        gameState_ = GameState::Ongoing;
    }
}

void BlackJackGame::updateDealerState() {
    int playerHandValue = player_.getHandValue();
    int dealerHandValue = dealer_.getHandValue();
    if (dealerHandValue > 21) {
        gameState_ = GameState::DealerBusts;
    } else if (dealerHandValue > playerHandValue) {
        gameState_ = GameState::DealerWins;
    } else if (dealerHandValue == 21 && dealerHandValue == playerHandValue) {
        gameState_ = GameState::Tie;
    } else {
        gameState_ = GameState::Ongoing;
    }
}

void BlackJackGame::printCards() {
    for (auto card : deck_) {
        card.printCard();
    }
    std::cout<<deck_.size()<<std::endl;
}

BlackJackGame::GameState BlackJackGame::getState() const {
    return gameState_;
}

void BlackJackGame::exit() {
    gameState_ = GameState::Exit;
}

void BlackJackGame::startGame() {
    initializeDeck();
    initializeHands();
    gameState_ = GameState::Ongoing;
}