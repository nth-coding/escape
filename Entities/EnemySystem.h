#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "../HeaderFiles/Header.h"
#include "../Map/EnemySpawnerTile.h"
#include "Charger.h"
#include "Demon.h"

enum EnemyTypes {DEMON = 0, CHARGER = 1};

class EnemySystem
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;
	Entity& player;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies, 
		std::map<std::string, sf::Texture>& textures, Entity& player);
	virtual ~EnemySystem();

	//Accessors

	//Modifiers

	//Functions
	void createEnemy(const short type, const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile);
	void removeEnemy(const int index);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

#endif //!ENEMYSYSTEM_H