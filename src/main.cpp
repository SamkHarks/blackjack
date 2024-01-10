#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "card.hpp"
#include "player.hpp"
#include "blackjackgame.hpp"
#include "blackjackcontroller.hpp"

int main(void) {
    Player player("Player");
    Player dealer("Dealer");
    BlackJackGame game(player, dealer);
    BlackJackView view;
    BlackJackController controller(game, view);
    controller.playGame();
    game.play();
    return 0;
}