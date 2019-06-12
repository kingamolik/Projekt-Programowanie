#pragma once
#include <string>
#include "Team.h"
using namespace std;
class Thanos:public Team
{
public:
	string name;
	Thanos(string name);
	~Thanos();
	void Victory();
	void Introduction();
};

