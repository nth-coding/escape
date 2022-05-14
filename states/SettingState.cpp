#include "SettingState.h"

void SettingState::initVariables()
{

}

void SettingState::initBackground()
{
    this->background.setSize(
        sf::Vector2f
        (
            static_cast<float> (this->window->getSize().x), 
            static_cast<float>(this->window->getSize().y))
        );

    if (!this->backgroundTexture.loadFromFile("textures/background_2.jpg"))
    {
        std::cout << "ERROR:MAIN_MENU_STATE: FAILED_TO_LOAD_BACKGROUND_TEXTURE!";
    }
    this->background.setTexture(&this->backgroundTexture);
}

void SettingState::initFonts()
{
    if (!this->font.loadFromFile("fonts/Pixeboy-z8XGD.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT!");
    }
}

void SettingState::initKeybinds()
{
    std::ifstream fin("Config/mainmenustate_keybinds.ini");

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

void SettingState::initButtons()
{
    this->buttons["EXIT_STATE"] = new gui::Button(100, 540, 150, 50, &this->font, "Quit", 50,
    sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
    sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

SettingState::SettingState(sf::RenderWindow* window, GraphicSetting& gfxSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) 
    : State(window, supportedKeys, states), gfxSettings(gfxSettings)
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
}

SettingState::~SettingState()
{
    for (auto &it : buttons)
    {
        delete it.second;
    }
}

void SettingState::updateInput(const float& delta)
{
    
}

void SettingState::updateButtons()
{
    // Updates all the buttons in the state and handles their functionality. 
    for (auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    // Quit the game
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        endState(); 
    }
}

void SettingState::update(const float& delta)
{
    this->updateMousePosition();
    this->updateInput(delta);

    this->updateButtons();
}

void SettingState::renderButtons(sf::RenderTarget& target)
{
    for (auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void SettingState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }
    target->draw(this->background);

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