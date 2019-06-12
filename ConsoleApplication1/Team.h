#pragma once
#include <string>
using namespace std;
class Team
{
public:
    string nazwa;
	virtual void Victory() = 0;
	virtual void Introduction() = 0;
};

