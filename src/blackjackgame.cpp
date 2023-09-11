#include <sstream>
#include "blackjackgame.hpp"
#include "card.hpp"

Card BlackJackGame::draw(Player & player) {
    if (!deck_.empty()) {
        Card card = deck_.back();
        deck_.pop_back();
        player.drawCard(card);
        return card;
    }
    Card card(-1);
    return card;
}

void BlackJackGame::hit(Player & player) {
    Card card = draw(player);
    if (card.getPoints() > 0) {
        std::cout<<player.getName()<<" dealt: "<<card.getRank()<<" of "<<card.getSuit()<<std::endl;
        player_.printHand();
        dealer_.printHand();
        return;
    }

    std::cout<<"Error couldn't draw a card.."<<std::endl;
}

void BlackJackGame::stand() {
    std::cout<<"Player stands!"<<std::endl;
    player_.printHand();
    dealer_.printHand();
    int playerHandValue = player_.getHandValue(); 
    while(true) {
        hit(dealer_);
        int dealerHandValue = dealer_.getHandValue();
        if (dealerHandValue > 21) {
            std::cout<<"Dealer busts!"<<std::endl;
            std::cout<<"Player wins!"<<std::endl;
            break;
        } else if (dealerHandValue > playerHandValue) {
            std::cout<<"Dealer wins!"<<std::endl;
            break;
        } else if (dealerHandValue == 21 && playerHandValue == dealerHandValue) {
            std::cout<<"Tie"<<std::endl;
            break;
        }
    }
}

void BlackJackGame::printCards() {
    for (auto card : deck_) {
        card.printCard();
    }
    std::cout<<deck_.size()<<std::endl;
}

void BlackJackGame::play() {
    std::string input;
    Action action;
    while (true) {
        std::cout<<"Select action (h = hit, s = stand, q = quit)"<<std::endl;
        char character;
        std::getline(std::cin, input);
        std::istringstream stream(input);
        if (stream >> character) {
            action = static_cast<Action>(character);
            switch (action) {
                case Action::Hit: {
                    hit(player_);
                    int handValue = player_.getHandValue();
                    if (handValue > 21) {
                        std::cout<<"Player busts!"<<std::endl;
                        std::cout<<"Dealer wins!";
                        action = Action::Quit;
                    }/* else if (handValue == 21) {
                        stand();
                        action = Action::Quit;
                    }*/
                    break;
                }
                case Action::Stand: {
                    stand();
                    action = Action::Quit;
                    break;
                }
                case Action::Quit: {
                    std::cout<<"Exiting.."<<std::endl;
                    break;
                }
                default:
                    std::cout<<"Invalid input."<<std::endl;
                    break;
            }
        } else {
            std::cout<<"Couldn't parse input."<<std::endl;
        }
        if (action == Action::Quit) {
            std::cout<<std::endl;
            break;
        }
    }
}