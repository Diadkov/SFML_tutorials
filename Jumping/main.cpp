#include <SFML/Graphics.hpp> 
#include "Animation.h"
#include "Player.h" 
#include <iostream> 
#include "Platform.h" 
#include <vector> 

static const float VIEW_HEIGHT = 512.f;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {

    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));


    sf::Texture playerTexture;
    playerTexture.loadFromFile("C:\\Users\\vd\\source\\repos\\SFML_PROJECTS\\SFML_PROJECTS\\penguin_sprite.png");

    Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.f, 200);

    float deltaTime = 0.0f;
    sf::Clock clock;
    std::vector <Platform> platforms;
    platforms.push_back(Platform(nullptr, sf::Vector2f(400.f, 200.f), sf::Vector2f(500.f, 200.f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(400.f, 200.f), sf::Vector2f(500.f, 0.f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(1000.f, 200.f), sf::Vector2f(500.f, 500.f)));
    
    while (window.isOpen()) {

        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;

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
        Collider ColliderPlayer = (Collider&)player.GetCollider();
        
        sf::Vector2f direction;

        //for (int i = 0; i < platforms.size(); i++) {
        //    Platform& platform = platforms[i];
        //}

        for (Platform& platform : platforms) {
            if (platform.GetCollider().CheckCollison(ColliderPlayer, direction, 1.0f))
                player.OnCollission(direction);

        }


        view.setCenter(player.GetPosition());
        window.clear(sf::Color(150, 150, 150));

       
        for (Platform& platform : platforms)
            platform.Draw(window);

        window.setView(view);
        player.Draw(window);

        window.display();
    }

    return 0;
}
