#include "blackjackgame.hpp"
#include "blackjackview.hpp"

class BlackJackController {
public:
    BlackJackController(BlackJackGame& game, BlackJackView& view)
        : game_(game), view_(view) {};

    void playGame();

private:
    BlackJackGame& game_;
    BlackJackView& view_;
};