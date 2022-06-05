#include "Chest.h"

// Initializer functions
void Chest::initVariables()
{

}

void Chest::initAnimations()
{
	this->animationComponent->addAnimation("IDLE", 0.f, 0, 0, 0, 0, 16, 16);
	this->animationComponent->addAnimation("OPEN", 11.f, 0, 1, 2, 1, 16, 16);
}

// Constructors / Destructors
Chest::Chest(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Enemy(enemy_spawner_tile)
{
	this->initVariables();

	this->createHitboxComponent(this->sprite, 0.f, 0.f, 16.f, 16.f);
	this->createMovementComponent(0.f, 0.f, 0.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1, 1, 1, 1, 1, 1);

	this->setPosition(x, y);
	this->initAnimations();
}


Chest::~Chest()
{
	
}

void Chest::updateAnimation(const float& dt)
{
	if (this->movementComponent->getState(IDLE))
    {
        this->animationComponent->play("IDLE", dt);
    }

	this->sprite.setColor(sf::Color::White);
}

void Chest::update(const float & dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	Enemy::update(dt, mouse_pos_view, view);

	this->movementComponent->update(dt);

	this->updateAnimation(dt);

	this->hitboxComponent->update();
}

void Chest::render(sf::RenderTarget & target, const bool show_hitbox)
{
	target.draw(this->sprite);

	if (show_hitbox)
		this->hitboxComponent->render(target);
}
