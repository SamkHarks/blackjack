#include "player.hpp"

void Player::drawCard(const Card & card) {
    hand_.push_back(card);
}

int Player::getHandValue() const {
    int handValue = 0;
    int numAces = 0;
    for(std::vector<Card>::const_iterator it = hand_.begin(); it != hand_.end(); it++) {
        if (it->getRank() == "Ace") {
            numAces += 1;
        } else {
            handValue += it->getPoints();
        }
    }
    // Determine value of Aces
    for (int i = 0; i < numAces; i++) {
        if (handValue + 11 <= 21) {
            handValue += 11;
        } else {
            handValue += 1;
        }
    }
    return handValue;
}

void Player::printHand() const {
    std::string handString =  name_ + "'s hand: ";
    bool firstCard = true;

    for (const Card& card : hand_) {
        if (!firstCard) {
            handString += ", ";
        } else {
            firstCard = false;
        }
        handString += card.getRank() + " of " + card.getSuit();
    }

    int totalValue = getHandValue();
    handString += " (total rank: " + std::to_string(totalValue) + ")";

    std::cout<<handString<<std::endl;
}

std::string Player::getName() const {
    return name_;
}

void Player::clearHand() {
    hand_.clear();
}