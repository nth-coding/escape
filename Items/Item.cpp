#include "Item.h"

void Item::initVariables()
{
}

Item::Item(unsigned level, unsigned value)
{
	this->initVariables();

	this->level = level;
	this->value = value;
	this->type = ItemTypes::IT_DEFAULT;
}

Item::~Item()
{
}

const short unsigned& Item::getType() const
{
	return this->type;
}

const unsigned& Item::getLevel() const
{
	return this->level;
}

const unsigned& Item::getValue() const
{
	return this->value;
}