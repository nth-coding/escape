#ifndef SETTINGSTATE_H
#define SETTINGSTATE_H

#include "State.h"
#include "../resource_file/Gui.h"

class SettingState : public State
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
    SettingState(sf::RenderWindow* window, GraphicSetting& gfxSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~SettingState();

    // Accessors

    // Functions
    void updateInput(const float& delta);
    void updateButtons();
    void update(const float& delta);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = nullptr);
};

#endif