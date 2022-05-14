#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
private:

    // Variables
    int kindOfAttack;
    bool attacking;

    // Initializer functions
    void initVariables();
    void initComponents();

public:
    Player(float x, float y, sf::Texture& texture_sheet);
    virtual ~Player();

    // Function
    virtual void update(const float& delta);
    std::string kind_of_attack();
};

#endif