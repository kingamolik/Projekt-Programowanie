#pragma once
#include <iostream>
#include <fstream>
#include "object.h"

class Map
{
	//Atrybuty
	Object matrix[20][80];
	std::string file;

	//Prywatne funkcje
	void loadMap();

public:

	//Publiczne funkcje
	Map(std::string file = "");
	void printMap();
	friend class Game;
};


