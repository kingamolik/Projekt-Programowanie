#include "Teleport.h"


Teleport::Teleport(char look)
{
	//Ustaw atrybut look rodzica na look
	this->setLook(look);
	this->setWalkable(true);
}


Teleport::~Teleport()
{
}
