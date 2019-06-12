#include "Player.h"


int Player::getX()
{
	return this->x;
}

int Player::getY()
{
	return this->y;
}

void Player::setX(int newX)
{
	this->x = newX;
}

void Player::setY(int newY)
{
	this->y = newY;
}


Player::Player()
{
	this->x = 19;
	this->y = 16;
}

Player::Player(char look)
{
	this->x = 19;
	this->y = 16;
	this->setLook(look);

}


Player::~Player()
{
}