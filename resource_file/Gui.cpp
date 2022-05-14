#include "Gui.h"

gui::Button::Button(float x, float y, float width, float height, 
    sf::Font* font, std::string text, unsigned character_size,
    sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = BUTTON_IDLE;

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(this->idleColor);
    
    this->font = font;

    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(textIdleColor);
    this->text.setCharacterSize(character_size);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f, 
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );

    this->textIdleColor = textIdleColor;
    this->textHoverColor = textHoverColor;
    this->textActiveColor = textActiveColor;

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;
}

gui::Button::~Button()
{
    
}

// Accessors
const bool gui::Button::isPressed() const
{
    if (this->buttonState == BUTTON_ACTIVE) return true;
    return false;
}

// Functions
void gui::Button::update(const sf::Vector2f mousePos)
{
    // Update the booleans for hover and pressed
    this->buttonState = BUTTON_IDLE;

    // Hover
    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BUTTON_HOVER;
        
        // Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BUTTON_ACTIVE;
        }
    }

    switch (this->buttonState)
    {
    case BUTTON_IDLE: 
        this->shape.setFillColor(this->idleColor);
        this->text.setFillColor(this->textIdleColor);
        break;
    
    case BUTTON_HOVER: 
        this->shape.setFillColor(this->hoverColor);
        this->text.setFillColor(this->textHoverColor);
        break;
    
    case BUTTON_ACTIVE: 
        this->shape.setFillColor(this->activeColor);
        this->shape.setFillColor(this->textActiveColor);
        break;
    
    default:
        this->shape.setFillColor(sf::Color::Blue);
        this->shape.setFillColor(sf::Color::Red);
        break;
    }
}

void gui::Button::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
    target.draw(this->text);
}

/* ------------------------  DROP DOWN LIST  ---------------------------*/

// void gui::DropDownBox::update(const sf::Vector2f& mousePos)
// {

// }

// void gui::DropDownBox::render(sf::RenderTarget& target)
// {

// }