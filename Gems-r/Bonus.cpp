#include "Bonus.hpp"

void Recolourer::Do(RenderWindow& window, FieldOfSquares** squares) {
    Point posSq = position;
    Point newPos1 = { rand() % 9, rand() % 9 }, newPos2 = { rand() % 9, rand() % 9 };
    curColor = squares[position.x][position.y].s->getFillColor();
    newPos1 = prev[0];
    newPos2 = prev[1];

    if (squares[posSq.x][posSq.y].IsNeighboor(newPos1)) {
        newPos1.x = newPos1.x + 1;
        newPos1.y = newPos1.y + 1;
    }
    if (squares[posSq.x][posSq.y].IsNeighboor(newPos2)) {
        newPos2.x = newPos2.x + 1;
        newPos2.y = newPos2.y + 1;
    }

    squares[newPos1.x][newPos1.y].s->setFillColor(Color::Black);
    squares[newPos2.x][newPos2.y].s->setFillColor(Color::Black);
    window.draw(*squares[newPos1.x][newPos1.y].s);
    window.draw(*squares[newPos2.x][newPos2.y].s);
    window.display();
    sleep(seconds(0.2f));

    squares[newPos1.x][newPos1.y].s->setFillColor(curColor);
    squares[newPos2.x][newPos2.y].s->setFillColor(curColor);

    window.draw(*squares[newPos1.x][newPos1.y].s);
    window.draw(*squares[newPos2.x][newPos2.y].s);
    window.display();
    sleep(seconds(0.2f));
    squares[position.x][position.y].s->setOutlineThickness(-0.5);
}

void Boom::Do(RenderWindow& window, FieldOfSquares** squares) {
    Point positions[4];
    for (auto pos : positions) {
        GenerateNewPosition(pos);
        squares[pos.x][pos.y].s->setFillColor(Color::Black);
    }
}