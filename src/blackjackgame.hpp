#ifndef BLACKJACKGAME_HPP
#define BLACKJACKGAME_HPP

#include "player.hpp"
#include <vector>
#include <algorithm>
#include <random>

enum class Action {
    Hit = 'h',
    Stand = 's',
    Quit = 'q',
    BadInput = -1,
    Error = -2,
};

class BlackJackGame {
public:
    BlackJackGame(const Player & player, const Player & dealer) :
        player_(player), dealer_(dealer), gameState_(GameState::Start), dealtCard_(Card(-1)) {
        }
    enum class GameState {
        Start,
        Ongoing,
        PlayerWins,
        DealerWins,
        Tie,
        PlayerBusts,
        DealerBusts,
        Exit,
    };

    GameState getState() const;
    void hitPlayer();
    void hitDealer();
    void exit();
    void startGame();
    void draw(Player & player);
    Card getDealtCard() const;
    const Player& getPlayer() const;
    const Player& getDealer() const;
private:
    Player player_;
    Player dealer_;
    std::vector<Card> deck_;
    GameState gameState_;
    Card dealtCard_;
    void printCards();
    void initializeDeck () {
        deck_.clear();
        for (int i = 0; i < 52; i++) {
            Card c(i);
            deck_.push_back(c);
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck_.begin(), deck_.end(), g);
    }

    void initializeHands () {
        player_.clearHand();
        dealer_.clearHand();
        draw(player_);
        draw(player_);
        draw(dealer_);
    }
    void updatePlayerState();
    void updateDealerState();
    void setDealtCard(const Card & card);
};

#endif