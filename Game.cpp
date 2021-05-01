#include "Game.hpp"

Game::Game() {
    font.loadFromFile("..\\GEMS_cpp\\Lato-Bold.ttf");
    tScore.setFont(font);
    tScore.setString(scoreToPrint + to_string(controller.getScore()));
    tScore.setPosition(Vector2f(width * 64, height));
    tScore.setCharacterSize(14);
    tScore.setFillColor(Color::White);
}

void Game::UpdateField() {
    controller.CheckComboAll();

    controller.RebuildPlayingField(window);
    controller.CreateNewSqInPlaceOfDestroyed(window);
}

void Game::Update(int& countOfClick, int& clickBonus, Point& prev) {
    int sizeSquare = 64;
    Event event;
    window.setFramerateLimit(60);
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();

        if (event.type == Event::MouseButtonPressed) {
            if (event.key.code == Mouse::Left) {
                Vector2i pos = Mouse::getPosition(window);
                Point cur = { pos.x / sizeSquare , pos.y / sizeSquare };

                // если выбрано 2 квадрата - поменять
                if (controller.recolourer.isActive && clickBonus < 2) {
                    controller.recolourer.prev[clickBonus] = cur;
                    clickBonus++;
                    if (clickBonus >= 2) {
                        clickBonus = 0;
                        controller.recolourer.Do(window);
                        controller.recolourer.isActive = false;
                    }
                    continue;
                }
                countOfClick++;
                if (countOfClick == 2) {
                    controller.Move(window, cur, prev);

                    countOfClick = 0;
                }
                prev = cur;
            }
        }
        if (controller.boom.isActive) {
            controller.boom.Do(window);
            controller.boom.isActive = false;
        }
    }
}

void Game::Draw() {
    window.clear();
    controller.DrawField(window);
    tScore.setString(scoreToPrint + to_string(controller.getScore()));
    window.draw(tScore);
    window.display();
}