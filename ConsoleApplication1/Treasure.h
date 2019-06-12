#pragma once
#include "object.h"
#include <set>
#include <string>
using namespace std;
class Treasure:public Object
{

public:
	
	Treasure(char look);

	~Treasure();

	friend class Game;
};

