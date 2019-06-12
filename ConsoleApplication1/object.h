#pragma once
#include "object.h"
#include <string>
using namespace std;
class Object{

	//Wyglad
	char look;
	//Czy blokuje gracza
	bool walkable;
	//czy przedmiot do zebrania
//	bool isTreasure;

public:
	bool isTreasure;

	Object(char look = ' ');
	virtual ~Object();

	int static number;

	//pobierz wyglad obiektu
	 char getLook();
	//ustaw wyglad obiektu
	 void setLook(char look);
	//ustaw czy na obiekt mozna wejsc
	 void setWalkable(bool ifWalkable);

	//Sprawdz czy gracz moze wejsc na miejsce obiektu
	 bool canWalk();

//	 virtual string getName(char look);
};


