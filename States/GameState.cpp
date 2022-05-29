#include "GameState.h"

const bool showHitbox = false;

void GameState::initDeferredRender()
{
	this->renderTexture.create(
		this->stateData->gfxSettings->resolution.width,
		this->stateData->gfxSettings->resolution.height
	);

	this->renderSprite.setTexture(this->renderTexture.getTexture());
	this->renderSprite.setTextureRect(
		sf::IntRect(
			0, 0, 
			this->stateData->gfxSettings->resolution.width, 
			this->stateData->gfxSettings->resolution.height
		)
	);
}

// Initializer functions
void GameState::initView()
{
	this->view.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width / 2),
			static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)
		)
	);

	this->view.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
			static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
		)
	);
}

void GameState::initKeybinds()
{
	std::ifstream ifs("../build/Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void GameState::initFonts()
{
	if (!this->font.loadFromFile("../build/Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("../build/textures/player.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}

	if(!this->textures["DEMON_SHEET"].loadFromFile("../build/textures/Demon1.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_DEMON_TEXTURE";
	}

	if (!this->textures["CHARGER_SHEET"].loadFromFile("../build/textures/charger.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_CHARGER_TEXTURE";
	}

	if (!this->textures["MUDDY_SHEET"].loadFromFile("../build/textures/muddy_green.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_MUDDY_TEXTURE";
	}

	if (!this->textures["OGRE_SHEET"].loadFromFile("../build/textures/ogre.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_OGRE_TEXTURE";
	}
}

void GameState::initPauseMenu()
{
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

	this->pmenu->addButton("CONTINUE", gui::p2pY(28.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Continue");
	this->pmenu->addButton("QUIT", gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quit");
	this->pmenu->addButton("SOUND_ON/OFF", gui::p2pY(60.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Sound: ON/OFF");

}

void GameState::initDeadMenu()
{
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->deadmenu = new DeadMenu(this->stateData->gfxSettings->resolution, this->font);

	// this->deadmenu->addButton("QUIT", 0, gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quit");
	this->deadmenu->addButton("YES", gui::p2pX(38.f, vm), gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm) - 5, "YES");
	this->deadmenu->addButton("NO", gui::p2pX(49.f, vm), gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm) - 5, "NO");
}

void GameState::initWinMenu()
{
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;	
	this->winmenu = new WinMenu(this->stateData->gfxSettings->resolution, this->font);

	this->winmenu->addButton("YES", gui::p2pX(38.f, vm), gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm) - 5, "YES");
	this->winmenu->addButton("NO", gui::p2pX(49.f, vm), gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm) - 5, "NO");
}

void GameState::initKeyTime()
{
	this->keyTimeMax = 0.3f;
	this->keyTimer.restart();
}

void GameState::initDebugText()
{
	this->debugText.setFont(this->font);
	this->debugText.setFillColor(sf::Color::White);
	this->debugText.setCharacterSize(16);
	this->debugText.setPosition(15.f, this->window->getSize().y / 2.f);
}

void GameState::initPlayers()
{
	this->player = new Player(328, 383, this->textures["PLAYER_SHEET"]);
}

void GameState::initPlayerGUI()
{
	this->playerGUI = new PlayerGUI(this->player, this->stateData->gfxSettings->resolution);
}

void GameState::initEnemySystem()
{
	this->enemySystem = new EnemySystem(this->activeEnemies, this->textures, *this->player);
}

void GameState::initTileMap()
{
	this->tileMap = new TileMap("../build/text.slmp");
}

void GameState::initSystems()
{
	this->tts = new TextTagSystem("../build/Fonts/PixellettersFull.ttf");
}

//Constructors / Destructors
GameState::GameState(StateData* state_data)
	: State(state_data)
{
	this->initDeferredRender();
	this->initView();
	this->initKeybinds();
	// this->initBackgroundMusic();
	this->initFonts();
	this->initTextures();
	this->initPauseMenu();
	this->initDeadMenu();
	this->initWinMenu();
	this->initKeyTime();
	this->initDebugText();

	this->initPlayers();
	this->initPlayerGUI();
	this->initEnemySystem();
	this->initTileMap();
	this->initSystems();
}

GameState::~GameState()
{
	delete this->pmenu;
	delete this->deadmenu;
	delete this->winmenu;
	delete this->player;
	delete this->playerGUI;
	delete this->enemySystem;
	delete this->tileMap;
	delete this->tts;

	for (size_t i = 0; i < this->activeEnemies.size(); i++)
	{
		delete this->activeEnemies[i];
	}
}

const bool GameState::getKeyTime()
{
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax)
	{
		this->keyTimer.restart();
		return true;
	}

	return false;	
}

// Functions
void GameState::updateView(const float & dt)
{
	this->view.setCenter(
		std::floor(this->player->getPosition().x + (static_cast<float>(this->mousePosWindow.x) - static_cast<float>(this->stateData->gfxSettings->resolution.width / 2)) / 10.f),
		std::floor(this->player->getPosition().y + (static_cast<float>(this->mousePosWindow.y) - static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)) / 10.f)
	);
	
	if (this->tileMap->getMaxSizeF().x >= this->view.getSize().x)
	{
		if (this->view.getCenter().x - this->view.getSize().x / 2.f < 0.f)
		{
			this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
		else if (this->view.getCenter().x + this->view.getSize().x / 2.f > this->tileMap->getMaxSizeF().x)
		{
			this->view.setCenter(this->tileMap->getMaxSizeF().x - this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
	}

	if (this->tileMap->getMaxSizeF().y >= this->view.getSize().y)
	{
		if (this->view.getCenter().y - this->view.getSize().y / 2.f < 0.f)
		{
			this->view.setCenter(this->view.getCenter().x, 0.f + this->view.getSize().y / 2.f);
		}
		else if (this->view.getCenter().y + this->view.getSize().y / 2.f > this->tileMap->getMaxSizeF().y)
		{
			this->view.setCenter(this->view.getCenter().x, this->tileMap->getMaxSizeF().y - this->view.getSize().y / 2.f);
		}
	}

	this->viewGridPosition.x = static_cast<int>(this->view.getCenter().x) / static_cast<int>(this->stateData->gridSize);
	this->viewGridPosition.y = static_cast<int>(this->view.getCenter().y) / static_cast<int>(this->stateData->gridSize);
}

void GameState::updateInput(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime())
	{
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}

	if (this->player->isWin(player->getPosition())) this->winState();
	
	if (this->player->isDead()) this->deadState();
}

void GameState::updatePlayerInput(const float & dt)
{
	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);
}

void GameState::updatePlayerGUI(const float & dt)
{
	this->playerGUI->update(dt);
}

void GameState::updatePauseMenuButtons()
{
	if (this->pmenu->isButtonPressed("QUIT"))
	{
		this->endState();
	}

	if (this->pmenu->isButtonPressed("CONTINUE") && this->getKeytime())
	{
		this->unpauseState();
	}

	if (this->pmenu->isButtonPressed("SOUND_ON/OFF") && this->getKeytime())
	{
		sound_paused = sound_paused ^ 1;

		if (sound_paused)
		{
			this->music.pause();
		}
		else 
		{
			this->music.play();
		}
	}
}

void GameState::updateDeadMenuButtons()
{
	if (this->deadmenu->isButtonPressed("YES"))
	{
		this->endState();
		this->states->push(new GameState(this->stateData));
	}

	if (this->deadmenu->isButtonPressed("NO"))
	{
		this->endState();
	}
}

void GameState::updateWinMenuButtons()
{
	if (this->winmenu->isButtonPressed("YES"))
	{
		this->endState();
		this->states->push(new GameState(this->stateData));
	}

	if (this->winmenu->isButtonPressed("NO"))
	{
		this->endState();
	}
}

void GameState::updateTileMap(const float& dt)
{
	this->tileMap->updateWorldBoundsCollision(this->player, dt); 
	this->tileMap->updateTileCollision(this->player, dt);
	this->tileMap->updateTiles(this->player, dt, *this->enemySystem);
}

void GameState::updatePlayer(const float& dt)
{
	this->player->update(dt, this->mousePosView, this->view);
}

void GameState::updateCombatAndEnemies(const float& dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->getWeapon()->getAttackTimer())
		this->player->setInitAttack(true);

	unsigned index = 0;
	for (auto *enemy : this->activeEnemies)
	{
		enemy->update(dt, this->mousePosView, this->view);

		this->tileMap->updateWorldBoundsCollision(enemy, dt);
		this->tileMap->updateTileCollision(enemy, dt);

	  this->updateCombat(enemy, index, dt);

		if (enemy->isDead())
		{
			this->player->gainEXP(enemy->getGainExp());
			this->tts->addTextTag(EXPERIENCE_TAG, this->player->getPosition().x - 40.f, this->player->getPosition().y - 30.f, static_cast<int>(enemy->getGainExp()), "+", "EXP");

			this->enemySystem->removeEnemy(index);
			continue;
		}
		else if (enemy->getDespawnTimerDone())
		{
			this->enemySystem->removeEnemy(index);
			continue;
		}

		++index;
	}

	this->player->setInitAttack(false);
}

void GameState::updateCombat(Enemy* enemy, const int index, const float& dt)
{
	if (this->player->getInitAttack() && enemy->getGlobalBounds().contains(this->mousePosView)
		&& enemy->getSpriteDistance(*this->player) < this->player->getWeapon()->getRange() && enemy->getDamageTimerDone())
	{
		int dmg = static_cast<int>(this->player->getDamage());
		enemy->loseHP(dmg);
		enemy->resetDamageTimer();
		this->tts->addTextTag(DEFAULT_TAG, enemy->getPosition().x, enemy->getPosition().y, dmg, "", "");	
	}

	// Check enemy damage
	if (enemy->getGlobalBounds().intersects(this->player->getGlobalBounds()) && this->player->getDamageTimer())
	{
		int dmg = enemy->getAttributeComp()->damageMax;
		this->player->loseHP(dmg);
		this->tts->addTextTag(NEGATIVE_TAG, player->getPosition().x - 30.f, player->getPosition().y, dmg, "-", "HP");
	}
}

void GameState::updateDebugText(const float& dt)
{
	std::stringstream ss;

	ss << "Mouse Pos View: " << this->mousePosView.x << " " << this->mousePosView.y << "\n"
	<< "Active Enemies: " << this->activeEnemies.size() << "\n";

	this->debugText.setString(ss.str());
}

void GameState::update(const float& dt)
{
	// this->updateMusic();
	this->updateMousePositions(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);

	// this->updateDebugText(dt);
	
	if (this->dead)
	{
		this->deadmenu->update(this->mousePosWindow);
		this->updateDeadMenuButtons();

		this->updateView(dt);

		// Update the collision
		this->updateTileMap(dt);

		// Move the player
		this->updatePlayer(dt);

		this->updatePlayerGUI(dt);

		//Update systems
		this->tts->update(dt);

		return;
	}

	if (this->won)
	{
		this->winmenu->update(this->mousePosWindow);
		this->updateWinMenuButtons();

		this->updateView(dt);

		// Update the collision
		this->updateTileMap(dt);

		// Move the player
		this->updatePlayer(dt);

		this->updatePlayerGUI(dt);

		//Update systems
		this->tts->update(dt);

		return;
	}

	if (!this->paused) //Unpaused update
	{
		this->updateView(dt);

		this->updatePlayerInput(dt);

		// Update the collision
		this->updateTileMap(dt);

		// Move the player
		this->updatePlayer(dt);

		this->updatePlayerGUI(dt);

		//Update all enemies
		this->updateCombatAndEnemies(dt);

		//Update systems
		this->tts->update(dt);
	}
	else //Paused update
	{
		this->pmenu->update(this->mousePosWindow);
		this->updatePauseMenuButtons();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->renderTexture.clear();

	this->renderTexture.setView(this->view);
	this->tileMap->render(this->renderTexture, this->viewGridPosition, this->player->getCenter(), false);

	for (auto *enemy : this->activeEnemies)
	{
		enemy->render(this->renderTexture, showHitbox);
	}
	this->player->render(this->renderTexture, showHitbox);

	this->tileMap->renderDeferred(this->renderTexture, this->player->getCenter());
	this->tts->render(this->renderTexture);

	//Render GUI
	this->renderTexture.setView(this->renderTexture.getDefaultView());
	this->playerGUI->render(this->renderTexture);

	if (this->dead) this->deadmenu->render(this->renderTexture);

	if (this->won) this->winmenu->render(this->renderTexture);

	if (this->paused) //Pause menu render
	{
		this->pmenu->render(this->renderTexture);
	}

	//Debug Text
	this->renderTexture.draw(this->debugText);

	//FINAL RENDER
	this->renderTexture.display();
	target->draw(this->renderSprite);
}

