#include "object.h"
#include <iostream>

Object::Object(char look)
{
	this->look = look;
	this->walkable = false;
	this->isTreasure = false;
	number++;
}

Object::~Object()
{
	number--;
}

//Wyrenderuj obiekt na ekranie
char Object::getLook(){
	return this->look;
}
void Object::setLook(char look)
{
	this->look = look;
}
void Object::setWalkable(bool ifWalkable)
{
	this->walkable = ifWalkable;
}
//Sprawdz czy da sie przejsc 
bool Object::canWalk() {
	if (this->walkable == true) {
		return true;
	}
	else {
		return false;
	}
}

//string Object::getName(char look){}

int Object::number = 0;

