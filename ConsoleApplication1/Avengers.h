#pragma once
#include <string>
#include "Team.h"
using namespace std;
class Avengers :public Team
{
public:
	string name;
	Avengers(string name);
	~Avengers();
	void Victory();
	void Introduction();
};

