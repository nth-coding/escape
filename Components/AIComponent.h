#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include "../HeaderFiles/Header.h"
#include "../Entities/Entity.h"
#include "../AI/AIFollow.h"

class AIComponent
{
private:
	Entity& entity;
	Entity& self;

public:
	AIComponent(Entity& self, Entity& entity);
	~AIComponent();

	void update(const float& dt);
};

#endif

