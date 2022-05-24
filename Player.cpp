#include "Header.h"

#include "Player.h"

//Initializer functions
void Player::initVariables()
{
	this->initAttack = false;
	this->attacking = false;
	this->weapon = new Sword(1, 2, 5, 100, 20, "textures/weapon_cleaver.png");
	this->weapon->generate(1, 3);

	this->damageTimerMax = 500;
}

void Player::initComponents()
{

}

void Player::initAnimations()
{
    this->animationComponent->addAnimation("IDLE", 20.f, 0, 0, 12, 0, 32, 32);
    this->animationComponent->addAnimation("WALK", 5.f, 0, 1, 7, 1, 32, 32);
    this->animationComponent->addAnimation("ATTACK_1", 7.f, 0, 2, 9, 2, 32, 32);
    this->animationComponent->addAnimation("ATTACK_2", 7.f, 0, 3, 9, 3, 32, 32);
    this->animationComponent->addAnimation("ATTACK_3", 7.f, 0, 4, 9, 4, 32, 32);
}

void Player::initInventory()
{
	this->inventory = new Inventory(100);
}

//Constructors / Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
	this->initVariables();

	this->createHitboxComponent(this->sprite, 8.f, 10.f, 16.f, 20.f);
    this->createMovementComponent(140.f, 1400.f, 1000.f); 
    this->createAnimationComponent(texture_sheet);
	this->createAttributeComponent(1);
	this->createSkillComponent();

	this->setPosition(x, y);
	this->initAnimations();

	this->initInventory();
}

Player::~Player()
{
	delete this->inventory;
	delete this->weapon;
}

//Accessors
AttributeComponent * Player::getAttributeComponent()
{
	return this->attributeComponent;
}

Weapon * Player::getWeapon() const
{
	return this->weapon;
}

const std::string Player::toStringCharacterTab() const
{
	std::stringstream ss;
	const AttributeComponent* ac = this->attributeComponent;
	const Weapon* w = this->weapon;

	ss << "Level: " << ac->level << "\n"
		<< "Exp: " << ac->exp << "\n"
		<< "Exp next: " << ac->expNext << "\n"
		
		<< "Weapon Level: " << w->getLevel() << "\n"
		<< "Weapon Type: " << w->getType() << "\n"
		<< "Weapon Value: " << w->getValue() << "\n"
		<< "Weapon Range: " << w->getRange() << "\n"
		<< "Weapon Damage Min: " << w->getDamageMin() + this->attributeComponent->damageMin << " (" << this->attributeComponent->damageMin << ")" << "\n"
		<< "Weapon Damage Max: " << w->getDamageMax() + this->attributeComponent->damageMax << " (" << this->attributeComponent->damageMax << ")" << "\n";

	return ss.str();
}

const bool& Player::getInitAttack() const
{
	return this->initAttack;
}

const bool Player::getDamageTimer()
{
	if(this->damageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax)
	{ 
		this->damageTimer.restart();
		return true;
	}

	return false;
}

const unsigned Player::getDamage() const
{
	return rand() % (
	(this->attributeComponent->damageMax + this->weapon->getDamageMax()) 
	- (this->attributeComponent->damageMin + this->weapon->getDamageMin()) + 1)
	+ (this->attributeComponent->damageMin + this->weapon->getDamageMin());
}

void Player::setInitAttack(const bool initAttack)
{
	this->initAttack = initAttack;
}

//Functions
void Player::loseHP(const int hp)
{
	this->attributeComponent->loseHP(hp);
}

void Player::gainHP(const int hp)
{
	this->attributeComponent->gainHP(hp);
}

void Player::loseEXP(const int exp)
{
	this->attributeComponent->loseEXP(exp);
}

void Player::gainEXP(const int exp)
{
	this->attributeComponent->gainExp(exp);
}

void Player::updateAnimation(const float & dt)
{
	if (this->attacking)
	{
		if (this->animationComponent->play("ATTACK_3", dt, true)) this->attacking = false;
	}

	if (this->movementComponent->getState(IDLE))
    {  
        this->sprite.setScale(1.f, 1.f);
        this->animationComponent->play("IDLE", dt);
    }
    
    else if (this->movementComponent->getState(MOVING_RIGHT))
    {
        this->sprite.setOrigin(0.f, 0.f);
        this->sprite.setScale(1.f, 1.f);
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }

    else if (this->movementComponent->getState(MOVING_LEFT))
    {
        this->sprite.setOrigin(32.f, 0.f);
        this->sprite.setScale(-1.f, 1.f);
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }

    else if (this->movementComponent->getState(MOVING_UP))
    {
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }

    else if (this->movementComponent->getState(MOVING_DOWN))
    {
        this->animationComponent->play("WALK", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
}

void Player::update(const float & dt, sf::Vector2f& mouse_pos_view, const sf::View& view)
{
	this->movementComponent->update(dt);

	this->updateAnimation(dt);
	
	this->hitboxComponent->update();

	this->weapon->update(mouse_pos_view, sf::Vector2f(this->getSpriteCenter().x, this->getSpriteCenter().y + 5.f));
}

void Player::render(sf::RenderTarget & target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox)
{
	if (shader)
	{
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		target.draw(this->sprite, shader);

		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		this->weapon->render(target, shader);
	}
	else 
	{
		target.draw(this->sprite);
		this->weapon->render(target);
	}
	
	if(show_hitbox)
		this->hitboxComponent->render(target);
}
