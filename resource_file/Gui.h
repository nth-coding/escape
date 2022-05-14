#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\System.hpp"

enum button_state{BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};

namespace gui
{
    class Button
    {
    private:
        short unsigned buttonState;

        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

        sf::Color textIdleColor;
        sf::Color textHoverColor;
        sf::Color textActiveColor;
        
        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

    public:
        Button(float x, float y, float width, float height, 
        sf::Font* font, std::string text, unsigned character_size,
        sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

        ~Button();
        // Accessors (accessor là 1 pp mà lấy về dữ liệu cá nhân được lưu trữ trong một đối tượng)
        const bool isPressed() const;
        
        // Functions
        void update(const sf::Vector2f mousePos);
        void render(sf::RenderTarget& target);
    };

    // class DropDownBox
    // {
    // private:
    //     sf::Font& font;
    //     sf::RectangleShape active;
    //     std::vector<gui::Button*> list;

    // public:
    //     void update(const sf::Vector2f& mousePos);
    //     void render(sf::RenderTarget& target);
    // };
}
#endif