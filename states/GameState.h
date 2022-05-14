#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "../GUI/PauseMenu.h"
#include "../map/TileMap.h"

class GameState : 
    public State
{
private:
    sf::Font font;
    PauseMenu* pmenu;

    Player* player;
    sf::Texture texture;

    TileMap map;
    
    // Functions
    void initKeybinds();
    void initFonts();
    void initTextures();
    void initPauseMenu();
    void initPlayers();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    void updateInput(const float& delta);
    void updatePlayerInput(const float& delta);
    void updatePauseMenuButtons();
    void update(const float& delta);
    void render(sf::RenderTarget* target = nullptr);
};

#endif