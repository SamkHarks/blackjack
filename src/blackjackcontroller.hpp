#include "blackjackgame.hpp"
#include "blackjackview.hpp"

class BlackJackController {
public:
    BlackJackController(BlackJackGame& game, BlackJackView& view)
        : game_(game), view_(view) {};

    void playGame();

private:
    // Processes the player's chosen action
    void processPlayerAction(Action action);

    // Reads and interprets user input, returning an Action enum
    Action getUserAction();

    void processGameState();
    void startNewGame(const std::string& message);

    // References to the model and view
    BlackJackGame& game_;
    BlackJackView& view_;
};