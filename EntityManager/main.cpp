#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "GameEntity.h"

int main() {
    sf::VideoMode vm(400, 400);
    sf::RenderWindow window(vm, "Game entity", sf::Style::Default);



    std::srand(std::time(nullptr));


    for (int i = 0; i < 50; i++) {
        std::shared_ptr<GameEntity> test =
            EntityManager::Instance().CreateEntity("ghost" + std::to_string(i));

        test->AddSpriteComonent2D("D:\\2024\\Company\\1 LBW\\SFML_tutorial\\Tutorials_basics\\Game entity\\ghost.png");
        float xPosition = rand() % 400, yPosition = rand() % 400;

        test->SetPosition(xPosition, yPosition);
    }

    sf::Clock clock;
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        float currentTime = clock.restart().asSeconds();  // fps
        float fps = 1.0f / (currentTime);

        std::cout << "fps: " << fps << std::endl;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear();
        //window.draw(spriteLisa);
        //entity.Render(window);

        EntityManager::Instance().RenderAll(window);
        for (int i = 0; i < 50; i++) {
            // retrieve each of our entities
            std::shared_ptr<GameEntity> ent = EntityManager::Instance().GetEntity("ghost" + std::to_string(i));

            float x = ent->GetxPosition() + ent->xDirection;
            float y = ent->GetyPosition() + ent->yDirection;
            ent->SetPosition(x, y);
            // keep our values inside 
            if (x > 400) {
                ent->xDirection = -1.f;

            }
            if (x < 0) {
                ent->xDirection = 1.f;

            }
            if (y > 400) {
                ent->yDirection = -1.f;

            }
            if (y < 0) {
                ent->yDirection = 1.f;

            }
        }
        //window.draw(text);
        window.display();
    }

    return 0;
}