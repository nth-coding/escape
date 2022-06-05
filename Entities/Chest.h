#ifndef CHEST_H
#define CHEST_H

#include "../header_files/Header.h"
#include "Enemy.h"

class Chest : public Enemy
{
private:
	void initVariables();
	void initAnimations();

public:
	Chest(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
	virtual ~Chest();

	//Functions
	void updateAnimation(const float& dt);
	void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget & target, const bool show_hitbox);
};

#endif 