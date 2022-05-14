#include "../header_file/Game.h"
#include "../states/MainMenuState.h"

void Game::initVariables()
{
    this->window = NULL;
    this->delta = 0.f;
}

void Game::initGraphicSetting()
{
    this->gfxSettings.loadFromFile("config/graphics.ini");

}

void Game::initWindow()
{
    if (this->gfxSettings.fullscreen)
    {
        this->window = new sf::RenderWindow(this->gfxSettings.resolution, this->gfxSettings.title, sf::Style::Fullscreen, this->gfxSettings.contextSetting);
    }
    else
        this->window = new sf::RenderWindow(this->gfxSettings.resolution, this->gfxSettings.title, sf::Style::Titlebar | sf::Style::Close, this->gfxSettings.contextSetting);

    this->window->setFramerateLimit(this->gfxSettings.frameRateLimit);
    this->window->setVerticalSyncEnabled(this->gfxSettings.verticalSync);
}

void Game::initKeys()
{
    std::ifstream fin("Config/supported_keys.ini");

    if (fin.is_open())
    {
        std::string key = "";
        int key_value = 0;
        
        while(fin >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }
    fin.close();
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, this->gfxSettings, &this->supportedKeys, &this->states));
    // this->states.push(new GameState(this->window, &this->supportedKeys));
}

Game::Game()
{
    this->initVariables();
    this->initGraphicSetting();
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();

    }
}

void Game::endApplication()
{
    std::cout << "Ending Applicaion!\n";
}

void Game::updatedelta()
{
    /* Update the delta variable with the time its take to update and render 1 frame. */
    this->delta = this->deltaClock.restart().asSeconds();

    //system("cls");
    //std::cout << this->delta << '\n';
}

void Game::updateEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::update()
{
    this->updateEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->delta);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }

    // Application end.
    else
    {
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    if (!this->states.empty())
        this->states.top()->render();

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updatedelta();
        this->update();
        this->render();
    }
}