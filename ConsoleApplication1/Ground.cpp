#include "Ground.h"


Ground::Ground(char look)
{
	this->setLook(look);
	this->setWalkable(true);
}

Ground::~Ground()
{
}
