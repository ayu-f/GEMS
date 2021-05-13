#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;


#define width 10
#define height 10

typedef struct {
    int x, y;
}Point;

class FieldOfSquares {
public:
    Point pointSq;
    int sizeSquare = 64;
    RectangleShape* s;
    bool isToDelete = false;

    bool IsNeighboor(Point neigh);

    Point getPoint();
};