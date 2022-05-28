#ifndef GAME_H
#define GAME_H

#include "../header_files/Header.h"
#include "../states/MainMenuState.h"

class Game
{
private:
	//Variables
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	//Initialization
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();

public:
	Game();
	virtual ~Game();

	//Functions
	void endApplication();

	void updateDt();
	void updateSFMLEvents();
	void update();

	void render();
	void run();
};

#endif