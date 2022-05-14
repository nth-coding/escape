#include "EditorState.h"

//Initalizer
void EditorState::initVariables()
{

}

void EditorState::initBackground()
{
    
}

void EditorState::initFonts()
{
    if (!this->font.loadFromFile("fonts/Pixeboy-z8XGD.ttf"))
    {
        throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT!");
    }
}

void EditorState::initKeybinds()
{
    std::ifstream fin("Config/editorstate_keybinds.ini");

    if (fin.is_open())
    {
        std::string key = "";
        std::string key2 = "";
        
        while(fin >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    fin.close();
}

void EditorState::initButtons()
{
    
}

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
}

EditorState::~EditorState()
{
    for (auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
    {
        delete it->second;
    }
}

void EditorState::updateInput(const float& delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
        this->endState();
}

void EditorState::updateButtons()
{
    // Updates all the buttons in the state and handles their functionality. 
    for (auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

}

void EditorState::update(const float& delta)
{
    this->updateMousePosition();
    this->updateInput(delta);

    this->updateButtons();
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
    for (auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void EditorState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    } 

    this->renderButtons(*target);

    /*
    // DELETE LATER! This used to see the button position over to mouse
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 20);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(12);
    
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());

    target->draw(mouseText);
    */
}