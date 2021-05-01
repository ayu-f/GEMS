#pragma once
#include "GameController.hpp"

class Game {
public:
    Text tScore;
    Font font;
    string scoreToPrint = "Score: ";
    GameController controller;

    Game();

    RenderWindow window{ VideoMode(740, 640), "GEMS" };

    void UpdateField();

    void Draw();

    void Update(int& countOfClick, int& clickBonus, Point& prev);
};
