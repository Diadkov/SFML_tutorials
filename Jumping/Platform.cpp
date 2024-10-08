#include "Platform.h"
#include<SFML/Graphics.hpp>

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) {
	body.setSize(size);
	body.setOrigin(size / 2.f);
	body.setPosition(position);
	body.setTexture(texture);
}

void Platform::Draw(sf::RenderWindow& window) {
		window.draw(body);
}

