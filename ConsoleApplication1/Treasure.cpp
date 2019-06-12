#include "Treasure.h"
#include <iostream>
using namespace std;
Treasure::Treasure(char look)
{
	this->setLook(look);
	this->setWalkable(true);
}

Treasure::~Treasure()
{
}

