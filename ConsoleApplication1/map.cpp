#include "map.h"
#include <fstream>
#include <string>
#include "tree.h"
#include "Mountain.h"
#include "Player.h"
#include "Ground.h"
#include "missing.h"
#include "Water.h"
#include "Frame.h"
#include "Teleport.h"
#include "Treasure.h"

using namespace std;

//Zaczytaj mape z pliku do macierzy
void Map::loadMap()
{
	fstream plik;
	string linia;
	plik.open(this->file, ios::in);
	int linijka = 0;
	if (plik.good() == true){
		while (!plik.eof()){
			//Zaczytaj linie
			getline(plik, linia);
			//cout << "Linia:" << linia << endl;
			//Zapisz pojedyncze znaki do macierzy
			for (int i = 0; i <80; i++) {
				//Stworz obiekty danej klasy
				if (linia[i] == 'o' || linia[i] == 'O') {
					//Drzewo
					Tree drzewo(linia[i]);
					this->matrix[linijka][i] = drzewo;
				}else if (linia[i] == '/' || linia[i] == '\\' ){
					//Góra
					Mountain gora(linia[i]);
					this->matrix[linijka][i] = gora;
				}else if (linia[i]==' ' || linia[i]=='-' || linia[i]=='.'){
					//Pole do chodzenia
					Ground ziemia(linia[i]);
					this->matrix[linijka][i] = ziemia;
					//matrix[linijka][i] = new Ground();
				}else if (linia[i] == '{' || linia[i] == '~' || linia[i]=='}') {
					//Woda
					Water water(linia[i]);
					this->matrix[linijka][i] = water;
				}
				else if (linia[i] == '|' || linia[i] == '=')
				{	//ramka
					Frame frame(linia[i]);
					this->matrix[linijka][i] = frame;
				}
				else if(linia[i]=='*')
				{
					Teleport teleport(linia[i]);
					this->matrix[linijka][i] = teleport;
				}
				else if (linia[i] == '#'|| linia[i] == '$'|| linia[i] == '%'|| linia[i] == '&')
				{
					Treasure thing(linia[i]);
					thing.isTreasure = true;
					this->matrix[linijka][i] = thing;
				}
				else{
					//Gdy brakuje obiektu
					Missing missing(linia[i]);
					this->matrix[linijka][i] = missing;
				}
			}
			linijka++;
		}
		plik.close();

	}
}
//Konstruktor
Map::Map(std::string file)
{
	this->file = file;
	
	this->loadMap();
}

//Render mapy
void Map::printMap()
{
	//Wyrenderuj macierz
	cout << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 80; j++) {
			cout << this->matrix[i][j].getLook();
		}
		cout << endl;
	}
}



