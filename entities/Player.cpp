#include "Player.h"

void Player::initVariables()
{
    this->attacking = false;
    this->kindOfAttack = 1;
}

Player::Player(float x, float y, sf::Texture& texture_sheet)
{
    this->initVariables();
    
    this->setPosition(x, y);

    this->createHitboxComponent(this->sprite, 8.f, 10.f, 16.f, 20.f);
    this->createComponentMovement(100.f, 10.f, 2.f);   
    this->createComponentAnimation(texture_sheet);

    this->componentAnimation->addAnimation("IDLE", 20.f, 0, 0, 12, 0, 32, 32);
    this->componentAnimation->addAnimation("WALK", 5.f, 0, 1, 7, 1, 32, 32);
    this->componentAnimation->addAnimation("ATTACK_1", 7.f, 0, 2, 9, 2, 32, 32);
    this->componentAnimation->addAnimation("ATTACK_2", 7.f, 0, 3, 9, 3, 32, 32);
    this->componentAnimation->addAnimation("ATTACK_3", 7.f, 0, 4, 9, 4, 32, 32);
    
}

Player::~Player()
{

}

std::string Player::kind_of_attack()
{
    std::string _key;
    if ((this->kindOfAttack % 3) + 1 == 1) _key = "ATTACK_1";
    else if ((this->kindOfAttack % 3) + 1== 2) _key = "ATTACK_2";
    else _key = "ATTACK_3";

    if (this->kindOfAttack >= 1 && this->kindOfAttack <= 3) 
    {
        this->kindOfAttack = this->kindOfAttack + 1;
    }

    if (this->kindOfAttack > 3) 
    {
        this->kindOfAttack = 1;
    }
    // kindOfAttack++;
    return _key;
}

void Player::update(const float& delta)
{
    Entity::update(delta);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        attacking = true;
    }

    if (this->attacking) 
    {
        if (this->componentAnimation->play("ATTACK_2", delta, true)) this->attacking = false;
    }

    if (this->componentMovement->getState(IDLE))
        this->componentAnimation->play("IDLE", delta);
    
    else if (this->componentMovement->getState(MOVING_RIGHT))
    {
        this->sprite.setOrigin(0.f, 0.f);
        this->sprite.setScale(1.f, 1.f);
        this->componentAnimation->play("WALK", delta, this->componentMovement->getVelocity().x, this->componentMovement->getMaxVelocity());
    }

    else if (this->componentMovement->getState(MOVING_LEFT))
    {
        this->sprite.setOrigin(32.f, 0.f);
        this->sprite.setScale(-1.f, 1.f);
        this->componentAnimation->play("WALK", delta, this->componentMovement->getVelocity().x, this->componentMovement->getMaxVelocity());
    }

    else if (this->componentMovement->getState(MOVING_UP))
    {
        this->componentAnimation->play("WALK", delta, this->componentMovement->getVelocity().y, this->componentMovement->getMaxVelocity());
    }

    else if (this->componentMovement->getState(MOVING_DOWN))
    {
        this->componentAnimation->play("WALK", delta, this->componentMovement->getVelocity().y, this->componentMovement->getMaxVelocity());
    }

    this->componentHitbox->update();
}