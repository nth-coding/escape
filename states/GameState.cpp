#include "GameState.h"

void GameState::initKeybinds()
{
    std::ifstream fin("Config/gamestate_keybinds.ini");

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

void GameState::initFonts()
{
    if (!this->font.loadFromFile("fonts/Pixeboy-z8XGD.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT!");
    }
}

void GameState::initTextures()
{
    if (!this->textures["PLAYER_SHEET"].loadFromFile("textures/player.png"))
    {
        throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE_SHEET!";
    }
}

void GameState::initPauseMenu()
{
    this->pmenu = new PauseMenu(*this->window, this->font);

    this->pmenu->addButton("QUIT", 800.f, "Quit");
}

void GameState::initPlayers()
{
    this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    this->initKeybinds();
    this->initFonts();
    this->initTextures();
    this->initPauseMenu();
    this->initPlayers();
}

GameState::~GameState()
{
    delete this->pmenu;
    delete this->player;
}

void GameState::updateInput(const float& delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime())
    {
        if (!this->pause) this->pauseState();
         else this->unpauseState();
    }
}

void GameState::updatePlayerInput(const float& delta)
{
    // Update player input

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player->move(-1.f, 0.f, delta);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player->move(1.f, 0.f, delta);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player->move(0.f, -1.f, delta);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player->move(0.f, 1.f, delta);
}

void GameState::updatePauseMenuButtons()
{
    if (this->pmenu->isButtonPressed("QUIT") && this->getKeytime()) 
    {
        this->endState();
    }
}

void GameState::update(const float& delta)
{
    this->updateMousePosition();
    this->updateInput(delta);
    this->updateKeytime(delta); 

    if (!this->pause) // Unpause update
    {
        this->updatePlayerInput(delta);

        this->player->update(delta);
    }
    else // Pause update
    {        
        this->pmenu->update(this->mousePosView);
        this->updatePauseMenuButtons();
    }
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target)
    {
        target = this->window;
    }

    //this->map.render(*target);
    this->player->render(*target);

    if (this->pause) // Pause Menu Render
    {
        this->pmenu->render(*target);
    }
}