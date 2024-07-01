#include <unordered_map>
#include <iostream>
#include <string>
#include "GameEntity.h"
#include <memory>

class EntityManager {
public:
	static EntityManager& Instance() {
		static EntityManager* instance = new EntityManager;
		return *instance;
	}

	// creates new data structure :
	// / adds it to ourr structure
	std::shared_ptr<GameEntity> CreateEntity(std::string name){
		std::shared_ptr<GameEntity> newEntity = std::make_shared<GameEntity>(name);
		m_entities.insert(std::make_pair(name, newEntity));
	return newEntity;
	};

	// retrieve entity
	std::shared_ptr<GameEntity> GetEntity(std::string name) {
		return m_entities[name];
	}

	void RenderAll(sf::RenderWindow& ref) {
		// display all 
		for (auto it = m_entities.begin(); it != m_entities.end(); it++) {
			it->second->Render(ref);
		}

	}
	
private:
	EntityManager() {

	}
	~EntityManager() {

	}
	// container structure
	std::unordered_map <std::string, std::shared_ptr<GameEntity>> m_entities;
};
