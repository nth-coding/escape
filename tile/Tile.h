#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp" 
#include "SFML\System.hpp"

class Tile
{
private:
    /* data */
protected:
    sf::RectangleShape shape;

public:
    Tile();
    Tile(float x, float y, float gridSizeF);
    virtual ~Tile();

    void update();
    void render(sf::RenderTarget& target);
};

#endif