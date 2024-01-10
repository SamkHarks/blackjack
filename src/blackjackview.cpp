#include "blackjackview.hpp"
#include <sstream>

Action BlackJackView::getUserAction() {
    std::string input;
    std::cout<<"Select action (h = hit, s = stand, q = quit)"<<std::endl;
    char character;
    std::getline(std::cin, input);
    std::istringstream stream(input);
    if (stream >> character) {
        return static_cast<Action>(character);
    } else {
        //std::cout<<"Couldn't parse input."<<std::endl;
        return Action {}; //Action::Invalid
    }
}