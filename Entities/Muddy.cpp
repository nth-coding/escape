#include "Muddy.h"

// Initializer functions
void Muddy::initVariables()
{

}

void Muddy::initAnimations()
{
	this->animationComponent->addAnimation("IDLE", 25.f, 0, 0, 3, 0, 60, 64);
	this->animationComponent->addAnimation("WALK", 11.f, 3, 0, 7, 0, 60, 64);
	this->animationComponent->addAnimation("ATTACK", 5.f, 0, 0, 3, 0, 60, 64);
}

void Muddy::initAI()
{
	
}

void Muddy::initGUI()
{
	this->hpBar.setFillColor(sf::Color::Red);
	this->hpBar.setSize(sf::Vector2f(60.f, 10.f));
	this->hpBar.setPosition(this->sprite.getPosition());
}

// Constructors / Destructors
Muddy::Muddy(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player)
	: Enemy(enemy_spawner_tile)
{
	this->initVariables();
	this->initGUI();

	this->createHitboxComponent(this->sprite, 22.f, 24.f, 20.f, 20.f);
	this->createMovementComponent(50.f, 700.f, 400.f);
	this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1, 3, 1, 1, 1, 1);

	this->generateAttributes(this->attributeComponent->level);

	this->setPosition(x, y);
	this->initAnimations();

	this->follow = new AIFollow(*this, player);
}


Muddy::~Muddy()
{
	delete this->follow;
}

void Muddy::updateAnimation(const float & dt)
{
	if (this->movementComponent->getState(IDLE))
    {  
		this->sprite.setOrigin(0.f, 0.f);
        this->sprite.setScale(1.f, 1.f);
		this->animationComponent->play("IDLE", dt);
    }

    else if (this->movementComponent->getState(MOVING_RIGHT))
    {
		this->sprite.setOrigin(0.f, 0.f);
        this->sprite.setScale(1.f, 1.f);
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }

    else if (this->movementComponent->getState(MOVING_LEFT))
    {
        this->sprite.setOrigin(60.f, 0.f);
        this->sprite.setScale(-1.f, 1.f);
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }

    else if (this->movementComponent->getState(MOVING_UP))
    {
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }

    else if (this->movementComponent->getState(MOVING_DOWN))
    {
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }

	else if (this->movementComponent->getState(MOVING_DOWN) && this->movementComponent->getState(MOVING_LEFT))
	{
        this->sprite.setScale(-1.f, 1.f);
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}

	else if (this->movementComponent->getState(MOVING_UP) && this->movementComponent->getState(MOVING_LEFT))
	{
        this->sprite.setScale(-1.f, 1.f);
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}

	if (this->damageTimer.getElapsedTime().asMilliseconds() <= this->damageTimerMax)
	{
		this->sprite.setColor(sf::Color::Red);
	}
	else
		this->sprite.setColor(sf::Color::White);
}

void Muddy::update(const float & dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	Enemy::update(dt, mouse_pos_view, view);

	this->movementComponent->update(dt);

	this->hpBar.setSize(sf::Vector2f(60.f * (static_cast<float>(this->attributeComponent->hp) / this->attributeComponent->hpMax), 10.f));
	this->hpBar.setPosition(this->sprite.getPosition());

	this->updateAnimation(dt);

	this->hitboxComponent->update();

	this->follow->update(dt);
}

void Muddy::render(sf::RenderTarget & target, const bool show_hitbox)
{
	target.draw(this->sprite);
	target.draw(this->hpBar);

	if (show_hitbox)
		this->hitboxComponent->render(target);
}
