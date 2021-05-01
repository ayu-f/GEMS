#pragma once
#include "FieldOfSquares.hpp"

class Bonus {
public:
    FieldOfSquares** squares;
    bool isActive = false;
    Point position;
    int count;

    virtual void Do(RenderWindow& window) = 0;
};

class Recolourer : public Bonus {
public:
    Point prev[2];
    Color curColor;

    virtual void Do(RenderWindow& window);
};

class Boom : public Bonus {
public:
    void GenerateNewPosition(Point& newPos) {
        newPos = { rand() % 9, rand() % 9 };
    }

    virtual void Do(RenderWindow& window);
};
