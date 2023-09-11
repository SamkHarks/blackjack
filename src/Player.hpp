#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>
#include "card.hpp"

class Player {
    public:
        Player(const std::string & name) : name_(name) {}
        void drawCard(const Card& card);
        int getHandValue() const;
        void printHand() const;
        std::string getName () const;
    private:
        std::vector<Card> hand_;
        std::string name_;
};

#endif // PLAYER_HPP