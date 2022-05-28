#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../header_files/Header.h"
#include "GameState.h"
#include "EditorState.h"
#include "SettingsState.h"
#include "../GUI/Gui.h"

class MainMenuState :
	public State
{
private:
	//Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;
	sf::Music music;

	sf::RectangleShape btnBackground;
	std::map<std::string, gui::Button*> buttons;

	//Functions
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

public:
	MainMenuState(StateData* state_data);
	virtual ~MainMenuState();

	//Functions
	void updateMusic();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif
