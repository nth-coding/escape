#ifndef STATE_H
#define STATE_H

#include "../entities/Player.h"
#include "../resource_file/GraphicSetting.h"

class State
{
private:

protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;
    bool pause;
    float keytime;
    float keytimeMax;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Resources
    std::map<std::string, sf::Texture> textures;

    // Functions
    virtual void initKeybinds() = 0;

public:
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~State();

    // Accessors
    const bool& getQuit() const;
    const bool getKeytime();

    // Functions
    void endState();
    void pauseState();
    void unpauseState();
    
    virtual void updateMousePosition();
    virtual void updateKeytime(const float& delta);
    virtual void updateInput(const float& delta) = 0;
    virtual void update(const float& delta) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif