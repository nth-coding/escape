#include "Entity.h"

void Entity::initVariable()
{
    this->componentMovement = NULL;
    this->componentAnimation = NULL;
}

Entity::Entity()
{
    this->initVariable();
}

Entity::~Entity()
{
    delete this->componentHitbox;
    delete this->componentMovement;
    delete this->componentAnimation;
}

void Entity::setTexture(sf::Texture& texture)
{
    this->sprite.setTexture(texture);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
{
    this->componentHitbox = new ComponentHitBoxx(sprite, offset_x, offset_y, width, height);    
}

void Entity::createComponentMovement(const float maxVelocity, const float acceleration, const float deceleration)
{
    this->componentMovement = new ComponentMovement(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createComponentAnimation(sf::Texture& texture_sheet)
{
    this->componentAnimation = new ComponentAnimation(this->sprite, texture_sheet);
}

void Entity::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float &delta)
{
    if (this->componentMovement)
    {
        this->componentMovement->move(dir_x, dir_y, delta); // Set velocity
    }
}

void Entity::update(const float &delta)
{
    if (this->componentMovement)
        this->componentMovement->update(delta);
}

void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);

    if (this->componentHitbox)
    {
        this->componentHitbox->render(target);
    }
}