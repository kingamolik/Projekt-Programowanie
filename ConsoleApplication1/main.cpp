#include <iostream>
#include "map.h"
#include <Windows.h>
#include "Game.h"
#include <cstdlib>
#include <conio.h>
#include "tree.h"
#include "Mountain.h"
#include "Ground.h"
#include "Teleport.h"
#include "Water.h"
#include "Team.h"
#include "Thanos.h"
#include "Avengers.h"
using namespace std;
void start();
void team()
{
	char choice;
	while (1)
	{
		if (_kbhit())
		{
			choice = _getch();
			if (choice == 'a')
			{
				Avengers team1("Avengers");
				team1.Introduction();
				cout << endl<<"Kliknij 's' by zaczac gre!" << endl;
				cout << "Kliknij 'q' by zakonczyc gre." << endl;

				start();

				team1.Victory();
				Sleep(3000);
				break;

			}
			else if (choice == 'b')
			{
				Thanos team2("Thanos");
				team2.Introduction();
				cout << endl << "Kliknij 's' by zaczac gre!" << endl;
				cout << "Kliknij 'q' by zakonczyc gre." << endl;

				start();

				team2.Victory();
				Sleep(3000);
				break;

			}
			else if(choice=='q')
			{
				break;
			}
			else { cout << "Zly klawisz." << endl; }
		}
	}
}

void start()
{
	char choice;
	while (1)
	{
		if (_kbhit())
		{
			choice = _getch();
			if (choice == 's')
			{
				system("CLS");
				Game gra;
				break;
			}
			else if (choice == 'q')
			{
				system("CLS");
				system("pause");
			}
			else { cout << "Zly klawisz." << endl; }
		}
	}
}
int main()
{
	cout << endl;
	cout << "					Witaj w grze!" << endl << endl;
	cout << "Krotka instrukcja gry: " << endl<<endl;
	Tree drzewo('o');
	cout << drzewo.number<<". ";
	cout << " '"<<drzewo.getLook()<<"','O' - drzewa" << endl;
	Mountain gora('/');
	cout << gora.number << ". ";
	cout << " '"<<gora.getLook()<<"','\\' - gory" << endl;
	Water rzeka('{');
	cout << rzeka.number << ". ";
	cout << " '~','"<<rzeka.getLook()<<"','}' - rzeka" << endl;
	Teleport teleport('*');
	cout << teleport.number << ". ";
	cout << " '"<<teleport.getLook()<<"' - teleport" << endl;
	Ground ziemia(' ');
	cout << ziemia.number << ". ";
	cout << " '"<<ziemia.getLook()<<"', '.', '-' - ziemia" << endl<<endl;
	cout << "Mozesz poruszac sie jedynie po ziemii."<<endl;
	cout << "W Twoim wyposazeniu znajduja sie juz niektore kamienie nieskonczonosci." << endl;
	cout << "Twoim zadaniem bedzie przejsc przez wszystkie mapy i odnalezc pozostale." << endl << endl;
	cout << "Powodzenia! :)" << endl << endl;
	
	cout << "Wybierz swoja druzyne: " << endl;
	cout << "a) Avengers" << endl;
	cout << "b) Thanos" << endl;

	team();

	return(0);
}