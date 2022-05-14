#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "../resource_file/Gui.h"

class EditorState : public State
{
private:
    // Variables
    sf::Font font;

    std::map<std::string, gui::Button*> buttons;

    // Functions
    void initVariables();
    void initBackground();
    void initFonts();
    void initKeybinds();
    void initButtons();

public:
    EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~EditorState();

    void updateInput(const float& delta);
    void updateButtons();
    void update(const float& delta);
    void renderButtons(sf::RenderTarget& target);
    void render(sf::RenderTarget* target = NULL);
};

#endif