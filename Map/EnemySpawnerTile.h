#ifndef ENEMYSPAWNERTILE_H
#define ENEMYSPAWNERTILE_H

#include "../header_files/Header.h"
#include "Tile.h"

class EnemySpawnerTile : public Tile
{
private:
	int enemyType;
	int enemyAmount;
	int enemyCounter;
	sf::Clock enemySpawnTimer;
	sf::Int32 enemyTimeToSpawn;
	float enemyMaxDistance;
	bool firstSpawn;

public:
	EnemySpawnerTile(int grid_x, int grid_y, float gridSizeF,
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		int enemy_type, int enemy_amount, sf::Int32 enemy_time_to_spawn, float enemy_max_distance);
	virtual ~EnemySpawnerTile();

	//Accessors
	virtual const std::string getAsString() const;
	const int& getEnemyAmount() const;
	const int& getEnemyCounter() const;
	const bool getSpawnTimer();
	const int& getEnemyType() const;
	const float& getEnemyMaxDistance() const;

	//Functions
	void increaseEnemyCounter();
	void decreaseEnemyCounter();

	void update();
	void render(sf::RenderTarget & target, const sf::Vector2f player_position = sf::Vector2f());
};

#endif 