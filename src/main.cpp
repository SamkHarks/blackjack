#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "card.hpp"
#include "player.hpp"
#include "blackjackgame.hpp"

int main(void) {
    Player player("Player");
    Player dealer("Dealer");
    BlackJackGame game(player, dealer);
    game.play();
    return 0;
}