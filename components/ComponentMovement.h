#ifndef COMPONENTMOVEMENT_H
#define COMPONENTMOVEMENT_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "SFML\System.hpp"

enum movement_states {IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN};

class ComponentMovement
{
private:
    sf::Sprite& sprite;

    float maxVelocity;
    float acceleration;      // gia tốc
    float deceleration;      // giảm tốc, chậm lại
    
    sf::Vector2f velocity;   // vận tốc
    

// Initializer functions 

public:
    ComponentMovement(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
    virtual ~ComponentMovement();

// Accessors
    const float& getMaxVelocity() const;
    const sf::Vector2f& getVelocity() const;

// Functions
    const bool getState(const short unsigned state) const;
    const bool idle() const;
    const bool moving() const;
    const bool movingLeft() const;
    const bool movingRight() const;
    
    void move(const float x, const float y, const float& delta);
    void update(const float& delta);
};

#endif