#include "card.hpp"

Card::Card (int cardValue) : value_(cardValue) {
    if (value_ < 52 && value_ >= 0) {
        int rank = value_ % 13;
        int suit = value_ / 13;
        rank_ = ranks[rank];
        suit_ = suits[suit];
        points_ = (rank >= 10) ? 10 : rank == 0 ? 11 : (rank + 1);
    } else {
        value_ = -1;
        points_ = -1;
        rank_ = "";
        suit_ = "";
    }
}

int Card::getPoints () const {
    return points_;
}

std::string Card::getRank () const {
    return rank_;
}

std::string Card::getSuit () const {
    return suit_;
}