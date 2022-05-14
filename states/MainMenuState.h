#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "EditorState.h"
#include "SettingState.h"
#include "../resource_file/Gui.h"
#include "../resource_file/GraphicSetting.h"

class MainMenuState : 
    public State
{
private:
    // Variables
    GraphicSetting& gfxSettings;
    sf::Texture backgroundTexture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, gui::Button*> buttons;

    // Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, GraphicSetting& gfxSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    void updateInput(const float& delta);
    void updateButtons();
    void update(const float& delta);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};

#endif
