#pragma once

#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation(texture, imageCount, switchTime) {
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;
        
    body.setSize(sf::Vector2f(80.0f, 150.0f));
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
    body.setOrigin(body.getSize() / 2.0f);
}


Player::~Player() {
}

void Player::OnCollission(sf::Vector2f direction) {
    if (direction.x < 0.0f) {
        // collision on the left
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f) {
        // collision on the right
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f) {
        // collision on the bottom
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f) {
        // collision on the top
        velocity.y = 0.0f;
    }
}


void Player::Update(float deltaTime) {
    velocity.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -= speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
        canJump = false;
        velocity.y = -sqrt(2.0f * 981.0f * jumpHeight); // 100 SFML UNITS = METER
    }
    velocity.y += 981.0f * deltaTime;


    if (velocity.x == 0.0f) {
        row = 0;
    }
    else {
        row = 1;

        if (velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }


    animation.Update(row, deltaTime, faceRight);

    body.setTextureRect(animation.uvRect);

    body.move(velocity * deltaTime);
}

// Draw function: draws the player on the provided window
void Player::Draw(sf::RenderWindow& window) {
    window.draw(body); // Draw the player's body
}
