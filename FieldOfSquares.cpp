#include "FieldOfSquares.hpp"

bool FieldOfSquares::IsNeighboor(Point neigh) {
    Point cur = { (int)s->getPosition().x / sizeSquare, (int)s->getPosition().y / sizeSquare };
    if (cur.x == neigh.x) {
        return (cur.y = neigh.y + 1 || cur.y == neigh.y - 1);
    }
    if (cur.y == neigh.y) {
        return (cur.x == neigh.x + 1 || cur.x == neigh.x - 1);
    }
    return false;
}

Point FieldOfSquares::getPoint() {
    pointSq = { (int)s->getPosition().x / sizeSquare,  (int)s->getPosition().y / sizeSquare };
    return pointSq;
}