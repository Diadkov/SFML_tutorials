#include <SFML/Graphics.hpp> 
#include "Animation.h"
#include "Player.h" 
#include <iostream> 

static const float VIEW_HEIGHT = 512.f;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));


    sf::Texture playerTexture;
    playerTexture.loadFromFile("C:\\Users\\vd\\source\\repos\\SFML_PROJECTS\\SFML_PROJECTS\\penguin_sprite.png");

    Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.f);

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
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            }

        }

        player.Update(deltaTime);
        view.setCenter(player.GetPosition());

        window.clear(sf::Color(150, 150, 150));

       

        window.setView(view);
        player.Draw(window);

        window.display();
    }

    return 0;
}
