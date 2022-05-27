#include "DeadMenu.h"

DeadMenu::DeadMenu(sf::VideoMode& vm, sf::Font& font)
	: font(font)
{
	//Init background
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width), 
			static_cast<float>(vm.height)
		)
	);
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	//Init container
	this->container.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width) / 4.f,
			static_cast<float>(vm.height) - gui::p2pY(9.3f, vm)
		)
	);
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(
		static_cast<float>(vm.width) / 2.f - this->container.getSize().x / 2.f,
		30.f
	);

	//Init text
	this->menuText.setFont(font);
	this->menuText.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText.setCharacterSize(gui::calcCharSize(vm));
	this->menuText.setString("GAME OVER!");
	this->menuText.setPosition(
		this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText.getGlobalBounds().width / 2.f,
		this->container.getPosition().y + gui::p2pY(4.f, vm)
	);

	this->menuText2.setFont(font);
	this->menuText2.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuText2.setCharacterSize(gui::calcCharSize(vm));
	this->menuText2.setString("New Game?");
	this->menuText2.setPosition(
		this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuText2.getGlobalBounds().width / 2.f,
		gui::p2pY(67.f, vm)
	);
}

DeadMenu::~DeadMenu()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

std::map<std::string, gui::Button*>& DeadMenu::getButtons()
{
	return this->buttons;
}

//Functions
const bool DeadMenu::isButtonPressed(const std::string key)
{
	return this->buttons[key]->isPressed();
}

void DeadMenu::addButton(
	const std::string key,
	float x,
	const float y,
	const float width,
	const float height,
	const unsigned char_size, 
	const std::string text)
{
	if (x == 0) x = this->container.getPosition().x + this->container.getSize().x / 2.f - width / 2.f;
	this->buttons[key] = new gui::Button(
		x, y, width, height,
		&this->font, text, char_size,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);
}

void DeadMenu::update(const sf::Vector2i& mousePosWindow)
{
	for (auto &i : this->buttons)
	{
		i.second->update(mousePosWindow);
	}
}

void DeadMenu::render(sf::RenderTarget & target)
{
	target.draw(this->background);
	target.draw(this->container);

	for (auto &i : this->buttons)
	{
		i.second->render(target);
	}

	target.draw(this->menuText);
	target.draw(this->menuText2);
}