#pragma once
#include "GameController.hpp"

class Game {
private:
    Text tScore;
    Font font;
    string scoreToPrint = "Score: ";
    GameController controller;
public:
    Game();

    RenderWindow window{ VideoMode(740, 640), "GEMS" };

    void UpdateField();

    void Draw();

    void Update(int& countOfClick, int& clickBonus, Point& prev);
};
