#pragma once

#include<string>
#include <SFML/Graphics.hpp>

class Icomponent {
public:
    virtual ~Icomponent() {}
    // not force to implement this!
    // move this to a Irenderablecomponent 
    virtual void Render(sf::RenderWindow& ref) {}
    virtual void SetPosition(float x, float y) {}
};

class Sprite2Dcomponent : public Icomponent {
public:
    Sprite2Dcomponent(std::string filepath);
    ~Sprite2Dcomponent() {}
    void Render(sf::RenderWindow& ref);
    void SetPosition(float x, float y);
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

class GameEntity {
public:
    GameEntity(std::string name);
    ~GameEntity() {}
    void SetPosition(float x, float y);
    //  Add components to a new component

    void AddSpriteComonent2D(std::string filename);
    // walk through all components
    void Render(sf::RenderWindow& ref);
    float GetxPosition() const;
    float GetyPosition() const;
public:
    float xDirection = 1.0f;
    float yDirection = 1.0f;
private:
    float m_x, m_y; // positions of game entity
    std::string m_name;
    std::vector <std::shared_ptr <Icomponent>> m_components;
};