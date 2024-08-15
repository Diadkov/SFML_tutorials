#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
    player.setPosition(206.0f, 206.0f);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("C:\\Users\\vd\\Downloads\\lil_penguin_walk.png");
    player.setTexture(&playerTexture);

    Animation animation(&playerTexture, sf::Vector2u(4, 1), 1.f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, (float)mousePos.y);
        }



        animation.Update(0, deltaTime);
        player.setTextureRect(animation.uvRect);

        window.clear(sf::Color(2, 200, 200)); // cyan 
        window.draw(player);
        window.display();
    }

    return 0;
}
