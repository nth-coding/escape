#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../HeaderFiles/Header.h"
#include "State.h"
#include "../GUI/PauseMenu.h"
#include "../GUI/DeadMenu.h"
#include "../GUI/WinMenu.h"
#include "../Map/TileMap.h"
#include "../GUI/PlayerGUI.h"
#include "../Items/Sword.h"
#include "../Systems/TextTagSystem.h"

class GameState :
	public State
{
private:
	sf::View view;
	sf::Vector2i viewGridPosition;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;

	sf::Font font;
	PauseMenu* pmenu;
	DeadMenu* deadmenu;
	WinMenu* winmenu;

	sf::Clock keyTimer;
	float keyTimeMax;

	sf::Text debugText;

	Player* player;
	PlayerGUI* playerGUI;
	sf::Texture texture;
	
	std::vector<Enemy*> activeEnemies;
	EnemySystem* enemySystem;

	TileMap* tileMap;

	//Systems
	TextTagSystem* tts;

	//Functions
	void initDeferredRender();
	void initView();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initDeadMenu();
	void initWinMenu();
	void initPauseMenu();
	void initKeyTime();
	void initDebugText();

	void initPlayers();
	void initPlayerGUI();
	void initEnemySystem();
	void initTileMap();
	void initSystems();

public:
	GameState(StateData* state_data);
	virtual ~GameState();

	//Accessors
	const bool getKeyTime();

	//Functions
	void updateView(const float& dt);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePlayerGUI(const float& dt);
	void updatePauseMenuButtons();
	void updateDeadMenuButtons();
	void updateWinMenuButtons();
	void updateTileMap(const float& dt);
	void updatePlayer(const float& dt);
	void updateCombatAndEnemies(const float& dt);
	void updateCombat(Enemy* enemy, const int index, const float& dt);
	void updateDebugText(const float& dt);
	void update(const float& dt);

	void render(sf::RenderTarget* target = NULL);
};

#endif