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
        player_(player), dealer_(dealer) {
            initializeDeck();
            initializeHands();
        }
    void play();
    void hit(Player & player);
    void stand();
    Card draw(Player & player);
    Player getPlayer() const;
    Player getDealer() const;
    void printCards();
private:
    Player player_;
    Player dealer_;
    std::vector<Card> deck_;

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
};