#pragma once

#include "GameEntity.h"

Sprite2Dcomponent::Sprite2Dcomponent(std::string filepath) {
        m_texture.loadFromFile(filepath);
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(0.2f, 0.2f);
}

    void Sprite2Dcomponent::Render(sf::RenderWindow& ref) {
        ref.draw(m_sprite);
    }
    void Sprite2Dcomponent::SetPosition(float x, float y) {
        m_sprite.setPosition(x, y);
    }

    GameEntity::GameEntity(std::string name) {
        m_name = name;
        xDirection = (rand() % 5 + 1) - 3;
        yDirection = (rand() % 5 + 1) - 3;
    }
    void GameEntity::SetPosition(float x, float y) {
        m_x = x;
        m_y = y;
        for (int i = 0; i < m_components.size(); i++) {
            m_components[i]->SetPosition(m_x, m_y);
        }
    }
    //  Add components to a new component

    void GameEntity::AddSpriteComonent2D(std::string filename) {
        std::shared_ptr < Sprite2Dcomponent> sprite2DComponent = std::make_shared<Sprite2Dcomponent>(filename);
        m_components.push_back(sprite2DComponent);
    }
    // walk through all components
    void GameEntity::Render(sf::RenderWindow& ref) {
        for (int i = 0; i < m_components.size(); i++) {
            m_components[i]->Render(ref);
        }
    }
    float GameEntity::GetxPosition() const {
        return m_x;
    }
    float GameEntity::GetyPosition() const {
        return m_y;
    }
