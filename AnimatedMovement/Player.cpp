#pragma once
#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime) {
	this->speed = speed;
	row = 0;
	faceRight = true;
	
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
} 

Player::~Player() {
}

void Player::Update(float deltaTime) {
	sf::Vector2f movement(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= deltaTime * speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += deltaTime * speed;

	if (movement.x == 0.0f) {
		row = 0;
	}

	else{
		row = 2;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

}
void Player::Draw(sf::RenderWindow &window) {
	window.draw(body);
}
