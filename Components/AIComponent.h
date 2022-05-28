#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include "../header_files/Header.h"
#include "../entities/Entity.h"
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

