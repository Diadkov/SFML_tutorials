#pragma once // Ensure the file is included only once during compilation

#include "Animation.h" // Include the Animation header
#include "Collider.h"

class Player {
public:

    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);


    ~Player();


    void Update(float deltaTime);


    void Draw(sf::RenderWindow& window);

    sf::Vector2f GetPosition() {
        return body.getPosition();
    }

    Collider GetCollider() { 
        return Collider(body); 
    }

private:
    sf::RectangleShape body;
    Animation animation; 
    int row;
    float deltaTime; 
    float speed;
    bool faceRight;
};


// AND WHAT IF I WILL BE NEXT BEST PROGRAMMER