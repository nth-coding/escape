#ifndef WINMENU_H
#define WINMENU_H

#include "../header_files/Header.h"
#include "Gui.h"

class Gui;

class WinMenu
{
private:
	sf::Font& font;
	sf::Text menuText;
	sf::Text menuText2;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, gui::Button*> buttons;

	//Private Functions

public:
	WinMenu(sf::VideoMode& vm, sf::Font& font);
	virtual ~WinMenu();

	//Accessor
	std::map<std::string, gui::Button*>& getButtons();

	//Functions
	const bool isButtonPressed(const std::string key);
	void addButton(const std::string key, 
		const float y, 
		float x,
		const float width,
		const float height,
		const unsigned char_size, 
		const std::string text);
	void update(const sf::Vector2i& mousePosWindow);
	void render(sf::RenderTarget& target);
};

#endif