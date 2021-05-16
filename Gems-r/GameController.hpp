#pragma once
#include "FieldOfSquares.hpp"
#include "Bonus.hpp"

class GameController {
private:
    int score = 0;

    bool IsSameColors(RectangleShape* r1, RectangleShape* r2);

    Point GetPositionForBonus(Point cur);

    bool CheckColorOfNeighboors(vector<Point>& p);
public:
    Recolourer recolourer;
    Boom boom;
    FieldOfSquares** sq; // main objects - field of squares 
    GameController();
    // avoid copying 
    GameController(const GameController&) = delete;
    GameController& operator=(const GameController&) = delete;

    void DrawField(RenderWindow& window);

    void Move(RenderWindow& window, Point cur, Point prev);

    bool CheckComboAll();

    void RebuildPlayingField(RenderWindow& window);

    void CreateNewSqInPlaceOfDestroyed(RenderWindow& window);

    void CreateField();

    int getScore() {
        return score;
    }

    ~GameController();
};
