#ifndef ENEMYSYSTEM_H
#define ENEMYSYSTEM_H

#include "../header_files/Header.h"
#include "../map/EnemySpawnerTile.h"
#include "Charger.h"
#include "Demon.h"
#include "Muddy.h"
#include "Ogre.h"
#include "Chest.h"

enum EnemyTypes {DEMON = 0, CHARGER = 1, MUDDY = 2, OGRE = 3, CHEST = 4};

class EnemySystem
{
private:
	std::map<std::string, sf::Texture>& textures;
	std::vector<Enemy*>& activeEnemies;
	Entity& player;

public:
	EnemySystem(std::vector<Enemy*>& activeEnemies, std::map<std::string, sf::Texture>& textures, Entity& player);
	virtual ~EnemySystem();

	//Functions
	void createEnemy(const short type, const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile);
	void removeEnemy(const int index);

	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

#endif