#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

const std::string suits[] = { "Spades", "Hearts", "Clubs", "Diamonds" };
const std::string ranks[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


class Card {
    public:
        Card(int cardValue);

        int getPoints () const;

        std::string getRank () const;

        std::string getSuit () const;

        void printCard() {
            std::cout << rank_ << " of " << suit_ << " (" << points_ << " points)" << std::endl;
        }

private:
    int value_;
    int points_;
    std::string rank_;
    std::string suit_;
};

#endif // CARD_HPP