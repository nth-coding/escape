#include "ComponentMovement.h"

ComponentMovement::ComponentMovement(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration) 
: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
    this->maxVelocity = maxVelocity;
}

ComponentMovement::~ComponentMovement()
{

}

const float& ComponentMovement::getMaxVelocity() const
{
    return this->maxVelocity;
}

const sf::Vector2f& ComponentMovement::getVelocity() const
{
    return this->velocity;
}

const bool ComponentMovement::getState(const short unsigned state) const
{
    switch (state)
    {
    case IDLE:
        if (this->velocity.x == 0.f && this->velocity.y == 0.f) return true;
        return false;
        break;
    
    case MOVING:
    if (this->velocity.x != 0 || this->velocity.y != 0) return true;
        return false;
    break;

    case MOVING_LEFT:
    if (this->velocity.x < 0.f) return true;
        return false; 
    break;

    case MOVING_RIGHT:
    if (this->velocity.x > 0.f) return true;
        return false;
    break;

    case MOVING_UP:
    if (this->velocity.y > 0.f) return true;
        return false;
    break;

    case MOVING_DOWN:
    if (this->velocity.y < 0.f) return true;
        return false;
    break;
    }
    return false;
}

void ComponentMovement::move(const float dir_x, const float dir_y , const float& delta)
{
    // Acceleration
    this->velocity.x += this->acceleration * dir_x;
    this->velocity.y += this->acceleration * dir_y;
}

void ComponentMovement::update(const float& delta)
{
    /* Decelerating the sprite and controling the maxVelocity */

    // Check x:
    if (this->velocity.x > 0.f) // positive
    {
        // Max velocity check 
        if (this->velocity.x > this->maxVelocity) this->velocity.x = this->maxVelocity;
        
        // Deleceration
        this->velocity.x -= deceleration;
        if (this->velocity.x < 0.f) this->velocity.x = 0.f; 
    }
    else if (this->velocity.x < 0.f) // negative
    {
        // Max velocity check
        if (this->velocity.x < -this->maxVelocity) this->velocity.x = -this->maxVelocity;
        
        // Deleceration
        this->velocity.x += deceleration;
        if (this->velocity.x > 0.f) this->velocity.x = 0.f; 
    }

    // Check y:
    if (this->velocity.y > 0.f) // positive
    {
        // Max velocity check 
        if (this->velocity.y > this->maxVelocity) this->velocity.y = this->maxVelocity;
        
        // Deleceration
        this->velocity.y -= deceleration;
        if (this->velocity.y < 0.f) this->velocity.y = 0.f; 
    }
    else if (this->velocity.y < 0.f) // negative
    {
        // Max velocity check
        if (this->velocity.y < -this->maxVelocity) this->velocity.y = -this->maxVelocity;
        
        // Deleceration
        this->velocity.y += deceleration;
        if (this->velocity.y > 0.f) this->velocity.y = 0.f; 
    }

    // Final move
    this->sprite.move(this->velocity * delta); // Use velocity
}