#ifndef TILEMAP_H
#define TILEMAP_H

#include "../tile/Tile.h"

class TileMap
{
private:
    float gridSizeF;
    unsigned layers;
    unsigned gridSizeU;
    sf::Vector2u maxSize;
    std::vector< std::vector< std::vector<Tile> > > map;

public:
    TileMap(/* args */);
    virtual ~TileMap();

    // Functions

    void update();
    void render(sf::RenderTarget& target);
};

#endif