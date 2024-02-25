#ifndef BLACKJACKGAME_HPP
#define BLACKJACKGAME_HPP

#include "player.hpp"
#include <vector>
#include <algorithm>
#include <random>

enum class Action {
    Hit = 'h',
    Stand = 's',
    Quit = 'q'
};

class BlackJackGame {
public:
    BlackJackGame(const Player & player, const Player & dealer) :
        player_(player), dealer_(dealer), gameState_(GameState::Start), dealtCard_(Card(-1)) {
            initializeDeck();
            initializeHands();
        }
    enum class GameState {
        Start,
        Ongoing,
        PlayerWins,
        DealerWins,
        Tie,
        PlayerBusts,
        DealerBusts
        // Other states as needed
    };

    GameState getState() const;
    void play();
    void hit(Player & player);
    void stand();
    Card draw(Player & player);
    Card getDealtCard() const;
    void setDealtCard(const Card & card);
    Player getPlayer() const;
    Player getDealer() const;
    void printCards();
private:
    Player player_;
    Player dealer_;
    std::vector<Card> deck_;
    GameState gameState_;
    Card dealtCard_;

    void initializeDeck () {
        for (int i = 0; i < 51; i++) {
            Card c(i);
            deck_.push_back(c);
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck_.begin(), deck_.end(), g);
    }

    void initializeHands () {
        draw(player_);
        draw(player_);
        draw(dealer_);
        std::cout<<"Initial draw:"<<std::endl;
        player_.printHand();
        dealer_.printHand();
    }
    void updateStateAfterHit();
    void updateStateAfterStand();
};

#endif