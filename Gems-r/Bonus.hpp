#pragma once
#include "FieldOfSquares.hpp"

class Bonus {
protected:
    Point position;
public:
    bool isActive = false;

    virtual void Do(RenderWindow& window, FieldOfSquares** squares) = 0;
    void SetPosition(Point position) {
        this->position = position;
    }
};

class Recolourer : public Bonus {
public:
    Point prev[2];
    Color curColor;

    virtual void Do(RenderWindow& window, FieldOfSquares** squares);
};

class Boom : public Bonus {
private:
    void GenerateNewPosition(Point& newPos) {
        newPos = { rand() % 9, rand() % 9 };
    }
public:
    virtual void Do(RenderWindow& window, FieldOfSquares** squares);
};
