#ifndef COMPONENTANIMATION_H
#define COMPONENTANIMATION_H

#include <iostream>
#include <string>
#include <map>

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "SFML\System.hpp"

class ComponentAnimation
{
private:
    class Animation
    {
    public:
        // Variables
        sf::Sprite& sprite; 
        sf::Texture& textureSheet;

        float animationTimer;
        float timer;
        bool done;
        int width;
        int height;

        sf::IntRect currentRect;
        sf::IntRect startRect;
        sf::IntRect endRect;

        Animation(sf::Sprite& sprite, sf::Texture& texture_sheet, 
        float animation_timer, int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height) 
        : sprite(sprite), textureSheet(texture_sheet), animationTimer(animation_timer),timer(0.f), done(false), width(width), height(height)
        {
            this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
            this->currentRect = this->startRect;
            this->endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);

            this->sprite.setTexture(this->textureSheet, true);
            this->sprite.setTextureRect(this->startRect);
        }

        // Accessor
        const bool& isDone() const
        {
            return this->done;
        }

        // Functions 
        const bool& play(const float& delta)
        {
            // Update timer
            this->done = false;
            this->timer += 100.f * delta;
            if (this->timer >= this->animationTimer)
            {
                // reset timer
                this->timer = 0.f;

                if (this->currentRect != this->endRect)
                {
                    this->currentRect.left += this->width;
                }
                else // reset
                {
                    this->currentRect.left = this->startRect.left;
                    this->done = true;
                }
                this->sprite.setTextureRect(this->currentRect);
            }
            return this->done;
        }

        const bool& play(const float& delta, float percentage)
        {
            // Update timer
            if (percentage < 0.5f)
            {
                percentage = 0.5f;
            }
            
            this->done = false;
            this->timer += percentage * 100.f * delta;
            if (this->timer >= this->animationTimer)
            {
                // reset timer
                this->timer = 0.f;

                if (this->currentRect != this->endRect)
                {
                    this->currentRect.left += this->width;
                }
                else // reset
                {
                    this->currentRect.left = this->startRect.left;
                    this->done = true;
                }

                this->sprite.setTextureRect(this->currentRect);
            }
            return this->done;
        }
        
        // void pause();
        void reset()
        {
            this->timer = this->animationTimer;
            this->currentRect = this->startRect;
        }
    };

    sf::Sprite& sprite;
    sf::Texture& textureSheet;
    std::map<std::string, Animation*> animations;
    Animation* lastAnimation;
    Animation* priorityAnimation;

public:
    ComponentAnimation(sf::Sprite& sprite, sf::Texture& texture_sheet);
    virtual ~ComponentAnimation();

    // Accessor
    const bool& isDone(const std::string key);

    // Functions
    void addAnimation(std::string key,float animation_timer, 
        int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height);
    const bool& play(const std::string key, const float& delta, const bool priority = false);    
    const bool& play(const std::string key, const float& delta, const float& modifier, const float& modifier_max, const bool priority = false);
};
#endif