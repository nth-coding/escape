#ifndef GAME_H
#define GAME_H

#include "../states/MainMenuState.h"

class Game
{
private:
    // Variables
    GraphicSetting gfxSettings;
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock deltaClock;
    float delta;
    
    std::stack<State*> states;

    std::map<std::string, int> supportedKeys;

    // Initialization
    void initVariables();
    void initGraphicSetting();
    void initWindow();
    void initStates();
    void initKeys();

public:
    Game();
    virtual ~Game();

    void endApplication();

    //Update
    void updatedelta();
    void updateEvents();
    void update();
    
    //Render
    void render();
    
    //Core
    void run();
};

#endif


