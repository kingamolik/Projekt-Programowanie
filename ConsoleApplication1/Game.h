#pragma once
#include "map.h"
#include "Player.h"

class Game
{

	Map current_map;
	Player player;
	Object prevObject;
	Object nextObject;
	int map;

public:
	Game();
	~Game();
	void drawMap();
	void setPlayer(int x, int y);

	friend class Map;
};

