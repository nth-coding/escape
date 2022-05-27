#ifndef PLAYER_H
#define PLAYER_H

#include "../HeaderFiles/Header.h"
#include "Entity.h"
#include "../Items/Items.h"
#include "../Items/Inventory.h"

class Entity;

class Player : public Entity
{
private:
	//Variables
	Inventory* inventory;

	bool initAttack;
	bool attacking;
	Weapon* weapon;

	sf::Clock damageTimer;
	sf::Int32 damageTimerMax;

	//Initializer functions
	void initVariables();
	void initComponents();
	void initAnimations();
	void initInventory();

public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();
	
	//Accessors
	AttributeComponent* getAttributeComponent();
	Weapon* getWeapon() const;

	const std::string toStringCharacterTab() const;
	const bool& getInitAttack() const;
	
	const bool getDamageTimer();
	const unsigned getDamage() const;
	
	const bool isDead() const;
	
	//Modifier
	void setInitAttack(const bool initAttack);

	//Functions
	void loseHP(const int hp);
	void gainHP(const int hp);
	void loseEXP(const int exp);
	void gainEXP(const int exp);

	void updateAttack();
	void updateAnimation(const float& dt);
	void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target, const bool show_hitbox = false);
};

#endif