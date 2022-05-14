#include "ComponentAnimation.h"

ComponentAnimation::ComponentAnimation(sf::Sprite& sprite, sf::Texture& texture_sheet) 
: sprite(sprite), textureSheet(texture_sheet), lastAnimation(NULL), priorityAnimation(NULL)
{
    
}

ComponentAnimation::~ComponentAnimation()
{
    for (auto &i : this->animations) delete i.second;
}

// Accessor
const bool& ComponentAnimation::isDone(const std::string key)
{
    return this->animations[key]->isDone();
}

// Function
void ComponentAnimation::addAnimation(std::string key, float animation_timer, 
    int start_frame_x, int start_frame_y, int frame_x, int frame_y, int width, int height)
{
    this->animations[key] = new Animation(
        this->sprite, this->textureSheet, animation_timer,
        start_frame_x, start_frame_y, frame_x, frame_y, 
        width, height);
}

const bool& ComponentAnimation::play(const std::string key, const float& delta, const bool priority)
{
    if (this->priorityAnimation) // If there is a priority animation
    {
        if (this->priorityAnimation == this->animations[key])
        {
            if (this->lastAnimation != this->animations[key])
            {
                if (this->lastAnimation == NULL)
                    this->lastAnimation = this->animations[key];
                else 
                {
                    this->lastAnimation->reset();
                    this->lastAnimation = this->animations[key];
                }
            }

            // If the priority animation is done, remove it
            if (this->animations[key]->play(delta))
            {
                this->priorityAnimation = NULL;
            }
        }
    }
    else
    {
        if (priority)
        {
            this->priorityAnimation = this->animations[key];
        }
        if (this->lastAnimation != this->animations[key])
        {
            if (this->lastAnimation == NULL)
                this->lastAnimation = this->animations[key];
            else 
            {
                this->lastAnimation->reset();
                this->lastAnimation = this->animations[key];
            }
        }
        this->animations[key]->play(delta);
    }
    return this->animations[key]->isDone();
}

const bool& ComponentAnimation::play(const std::string key, const float& delta, const float& modifier, const float& modifier_max, const bool priority)
{
    if (this->priorityAnimation) // If there is a priority animation
    {
        if (this->priorityAnimation == this->animations[key])
        {
            if (this->lastAnimation != this->animations[key])
            {
                if (this->lastAnimation == NULL)
                    this->lastAnimation = this->animations[key];
                else 
                {
                    this->lastAnimation->reset();
                    this->lastAnimation = this->animations[key];
                }
            }

            // If the priority animation is done, remove it.
            if (this->animations[key]->play(delta), abs(modifier / modifier_max))
            {
                this->priorityAnimation = NULL;
            }
            // this->animations[key]->play(delta, abs(modifier / modifier_max));
        }
    }
    else
    {
        // If this is a priority animation, set it.
        if (priority)
        {
            this->priorityAnimation = this->animations[key];
        }
        if (this->lastAnimation != this->animations[key])
        {
            if (this->lastAnimation == NULL)
                this->lastAnimation = this->animations[key];
            else 
            {
                this->lastAnimation->reset();
                this->lastAnimation = this->animations[key];
            }
        }
        this->animations[key]->play(delta, abs(modifier / modifier_max));
    }
    return this->animations[key]->isDone();
}