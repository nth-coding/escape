#ifndef DEMON_H
#define DEMON_H

#include "../header_files/Header.h"
#include "Enemy.h"

class Demon : public Enemy
{
private:
	void initVariables();
	void initAnimations();
	void initAI();
	void initGUI();

	sf::RectangleShape hpBar;

	AIFollow* follow;

public:
	Demon(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
	virtual ~Demon();

	//Functions
	void updateAnimation(const float & dt);
	void update(const float & dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget & target, const bool show_hitbox);
};

#endif 