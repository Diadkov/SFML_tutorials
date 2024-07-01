#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::VideoMode vm(400, 400);
    sf::RenderWindow window(vm, "TimberGame", sf::Style::Default);

    sf::Texture monoLisaTexture;
    monoLisaTexture.loadFromFile("C:\\Users\\vd\\Downloads\\mono_lisa.png");

    sf::Font font;
    font.loadFromFile("C:\\Users\\vd\\Downloads\\28_days_later\\28 Days Later.ttf");

    sf::String visualRepresentation = "Mono Lisa";
    sf::Text text;
    text.setFont(font);
    text.setString(visualRepresentation);
    text.move(100.f, 0.f);

    sf::Sprite spriteLisa;
    spriteLisa.setTexture(monoLisaTexture);
    spriteLisa.setPosition(0, 0);
    spriteLisa.setScale(0.5,0.5);

    float xPosition{0.0f};

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
        spriteLisa.setPosition(xPosition, 0.0f);
        xPosition += 1.f;
        if (xPosition > 100.f) {
            xPosition = 0.0f;
        }

        window.clear();
        window.draw(spriteLisa);
        window.draw(text);
        window.display();
    }

    return 0;
}
