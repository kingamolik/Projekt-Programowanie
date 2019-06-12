#include "object.h"
#include <set>
#include <iostream>
using namespace std;
class Player : public Object{

	//Pozycja gracza
	int x;
	int y;


public:
//	set<char>backpack;
	Player();
	Player(char look);
	~Player();

	int getX();
	int getY();

	void setX(int newX);
	void setY(int newY);

};

