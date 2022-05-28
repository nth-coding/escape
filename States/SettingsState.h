#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "../header_files/Header.h"
#include "State.h"
#include "../GUI/Gui.h"

class SettingsState : public State
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, gui::Button*> buttons;
	std::vector<sf::VideoMode> modes;

	// Functions
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();

public:
	SettingsState(StateData* state_data);
	virtual ~SettingsState();

	// Accessors

	// Functions
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif