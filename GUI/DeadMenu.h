#ifndef DEADMENU_H
#define DEADMENU_H

#include "../HeaderFiles/Header.h"
#include "Gui.h"

class Gui;

class DeadMenu
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
	DeadMenu(sf::VideoMode& vm, sf::Font& font);
	virtual ~DeadMenu();

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