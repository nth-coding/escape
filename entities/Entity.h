#ifndef ENTITY_H
#define ENTITY_H

#include "../components/ComponentMovement.h"
#include "../components/ComponentAnimation.h"
#include "../components/ComponentHitBoxx.h"

class Entity
{
private:
    void initVariable();

protected: // Can be accessed in the child class

    // we used pointer to point to the texture which had been loaded so it won't duplicate and won't take time. 
    sf::Sprite sprite; 

    ComponentHitBoxx* componentHitbox;
    ComponentMovement* componentMovement;
    ComponentAnimation* componentAnimation;

public:
    Entity();
    virtual ~Entity();

    // Component functions
    void setTexture(sf::Texture& texture);
    void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
    void createComponentMovement(const float maxVelocity, const float acceleration, const float deceleration);
    void createComponentAnimation(sf::Texture& texture_sheet);

    // Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float &delta);
    virtual void update(const float& delta);
    virtual void render(sf::RenderTarget& target);
};

#endif