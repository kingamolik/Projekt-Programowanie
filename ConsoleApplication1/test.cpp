/*
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;
class map2
{
public:
	static int x, y;
	const char* matrix[20][20];

	map2() {
		x = 1;
		y = 1;
	}

	void loadMap(){
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				matrix[i][j] = "X";
			}
		}
	}


	void printMap(){
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	friend class move;
};

class move
{
	void movement(const char* player, const char* klawisz, map2& m)
	{
		if (klawisz = "w")
		{
			m.matrix[m.x - 1][m.y] = player;
		}
		else if (klawisz = "s")
		{
			m.matrix[m.x + 1][m.y] = player;
		}
		else if (klawisz = "a")
		{
			m.matrix[m.x][m.y - 1] = player;
		}
		else if (klawisz = "d")
		{
			m.matrix[m.x][m.y + 1] = player;
		}
		else
		{
			"Blad. Uzywaj klawiszy: w,s,a lub d.";
		}
	}
};
*/