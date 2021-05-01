#include "GameController.hpp"

GameController::GameController() {
    CreateField();
    recolourer.squares = sq;
    boom.squares = sq;
}

void GameController::CreateField() {

    sq = new FieldOfSquares * [width];

    for (int i = 0; i < width; i++)
    {
        sq[i] = new FieldOfSquares[height];
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sq[i][j].s = new RectangleShape(Vector2f(64, 64));
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Color color[] = { Color::Red, Color::Yellow, Color::Green, Color::Cyan, Color::Blue, Color::Magenta, Color::Color(255, 99, 71) };
            int c = rand() % 7;
            if (j != 0) {
                if (sq[i][j - 1].s->getFillColor() == color[c]) {
                    if (c == 0)
                        c = c + rand() % 3 + 1;
                    else
                        c = c - 1;
                }
            }
            if (i != 0) {
                if (sq[i - 1][j].s->getFillColor() == color[c]) {
                    if (c == 0)
                        c = c + rand() % 3 + 1;
                    else
                        c = c - 1;
                }
            }
            // outline
            sq[i][j].s->setOutlineThickness(-0.5);
            sq[i][j].s->setOutlineColor(Color::Black);
            //color
            sq[i][j].s->setFillColor(color[c]);
            // start position
            sq[i][j].s->setPosition(Vector2f(i * 64.f, j * 64.f));
        }
    }
}

bool GameController::IsSameColors(RectangleShape* r1, RectangleShape* r2) {
    return (*r1).getFillColor() == (*r2).getFillColor();
}

bool GameController::CheckColorOfNeighboors(vector<Point>& p) {
    bool IsNeighWithSameColor = false;
    int k = p.size();
    for (unsigned int i = 0; i < p.size(); i++)
    {
        if (p[i].x != width - 1) { // ���� ������
            if (IsSameColors(sq[p[i].x][p[i].y].s, sq[p[i].x + 1][p[i].y].s) && !sq[p[i].x + 1][p[i].y].isToDelete) {
                sq[p[i].x + 1][p[i].y].isToDelete = true;
                p.push_back(sq[p[i].x + 1][p[i].y].getPoint());
                IsNeighWithSameColor = true;
            }
        }
        if (p[i].x != 0) { // ���� �����
            if (IsSameColors(sq[p[i].x][p[i].y].s, sq[p[i].x - 1][p[i].y].s) && !sq[p[i].x - 1][p[i].y].isToDelete) {
                sq[p[i].x - 1][p[i].y].isToDelete = true;
                p.push_back(sq[p[i].x - 1][p[i].y].getPoint());
                IsNeighWithSameColor = true;
            }
        }
        if (p[i].y != height - 1) { // ���� �����
            if (IsSameColors(sq[p[i].x][p[i].y].s, sq[p[i].x][p[i].y + 1].s) && !sq[p[i].x][p[i].y + 1].isToDelete) {
                sq[p[i].x][p[i].y + 1].isToDelete = true;
                p.push_back(sq[p[i].x][p[i].y + 1].getPoint());
                IsNeighWithSameColor = true;
            }
        }
        if (p[i].y != 0) { // ���� ������
            if (IsSameColors(sq[p[i].x][p[i].y].s, sq[p[i].x][p[i].y - 1].s) && !sq[p[i].x][p[i].y - 1].isToDelete) {
                sq[p[i].x][p[i].y - 1].isToDelete = true;
                p.push_back(sq[p[i].x][p[i].y - 1].getPoint());
                IsNeighWithSameColor = true;
            }
        }
    }
    return IsNeighWithSameColor;
}

bool GameController::CheckComboAll()
{
    bool answer = false;
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            if (sq[i][j].s->getFillColor() == Color::Black)
                continue;

            vector<Point> sqToDelete;
            sqToDelete.push_back(sq[i][j].getPoint());
            sq[i][j].isToDelete = true;
            while (CheckColorOfNeighboors(sqToDelete)) {

            }
            for (auto square : sqToDelete) {
                if (sqToDelete.size() < 3) {
                    sq[square.x][square.y].isToDelete = false;
                }
                else {
                    sq[square.x][square.y].s->setFillColor(Color::Black);
                    answer = true;
                }
            }
            if (sqToDelete.size() >= 3) {
                score += sqToDelete.size() * (sqToDelete.size() - 2);
            }
        }
    }
    return answer;
}

void GameController::DrawField(RenderWindow& window) {
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            window.draw(*sq[i][j].s);
        }
        sleep(seconds(0.01f));
    }
}

void GameController::RebuildPlayingField(RenderWindow& window) {
    for (int i = 0; i < width; i++)
    {
        for (int j = height - 1; j >= 0; j--)
        {
            Color tmp;
            if (sq[i][j].s->getFillColor() == Color::Black) {
                int k = j - 1;
                while (k >= 0) {
                    if (sq[i][k].s->getFillColor() != Color::Black) {
                        sq[i][j].s->setFillColor(sq[i][k].s->getFillColor());
                        sq[i][k].s->setFillColor(Color::Black);
                        window.clear();
                        DrawField(window);
                        window.display();
                        break;
                    }
                    k--;
                }
            }
        }
    }
}

Point GameController::GetPositionForBonus(Point cur) {
    int shiftX = rand() % 6 - 3;
    int shiftY = rand() % 6 - 3;

    while (cur.x + shiftX < 0)
        shiftX++;
    while (cur.x + shiftX >= 10)
        shiftX--;
    while (cur.y + shiftY < 0)
        shiftX++;
    while (cur.y + shiftY >= 10)
        shiftX--;
    return { cur.x + shiftX, cur.y + shiftY };
}

void GameController::Move(RenderWindow& window, Point cur, Point prev) {
    Color tmp;
    if (sq[prev.x][prev.y].IsNeighboor(cur)) {
        tmp = sq[prev.x][prev.y].s->getFillColor();
        sq[prev.x][prev.y].s->setFillColor(sq[cur.x][cur.y].s->getFillColor());
        sq[cur.x][cur.y].s->setFillColor(tmp);
        window.draw(*sq[prev.x][prev.y].s);
        window.draw(*sq[cur.x][cur.y].s);
        window.display();
        sleep(seconds(0.1f));


        if (!CheckComboAll()) {
            sq[cur.x][cur.y].s->setFillColor(sq[prev.x][prev.y].s->getFillColor());
            sq[prev.x][prev.y].s->setFillColor(tmp);
        }
        else {
            // create position 
            Point tmpPos = GetPositionForBonus(cur);
            if (rand() % 2 == 0) {
                boom.isActive = true;
                boom.position = tmpPos;
            }
            else {
                recolourer.isActive = true;
                recolourer.position = tmpPos;
                //recolourer.curColor = sq[tmpPos.x][tmpPos.y].s->getFillColor();
                sq[tmpPos.x][tmpPos.y].s->setOutlineThickness(-4);
            }
        }
    }
}

void GameController::CreateNewSqInPlaceOfDestroyed(RenderWindow& window) {
    Color color[] = { Color::Red, Color::Yellow, Color::Green, Color::Cyan, Color::Blue, Color::Magenta, Color::Color(255, 99, 71) };
    for (int i = 0; i < width; i++)
    {
        int k = 0;

        while (sq[i][k].s->getFillColor() == Color::Black && k < height) {
            int c = rand() % 7;
            if (k == 0) {
                sq[i][k].s->setFillColor(color[c]);
            }
            else {
                int j = k;
                while (j >= 1) {
                    Color tmp = sq[i][j - 1].s->getFillColor();
                    sq[i][j].s->setFillColor(tmp);
                    sq[i][j - 1].s->setFillColor(color[c]);

                    window.clear();
                    DrawField(window);
                    window.display();
                    j--;
                }
            }
            sleep(seconds(0.001f));
            k++;
        }
    }
}

GameController::~GameController() {
    for (int i = 0; i < width; i++)
    {
        delete[] sq[i];
    }
    delete[] sq;
}