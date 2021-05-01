#include "Game.hpp"

int main()
{
    srand(time(0));

    Game game;

    int clickSquare = 0, clickBonus = 0;
    Point prev;
    while (game.window.isOpen())
    {
        game.Update(clickSquare, clickBonus, prev);
        game.UpdateField();
        game.Draw();
    }

    return 0;
}