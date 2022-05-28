#ifndef AIFOLLOW_H
#define AIFOLLOW_H

#include "../header_files/Header.h"
#include "AIOption.h"

class AIFollow :
    public AIOption
{
private:

public:
    AIFollow(Entity& self, Entity& entity);
    ~AIFollow();

    void update(const float& dt);
};

#endif