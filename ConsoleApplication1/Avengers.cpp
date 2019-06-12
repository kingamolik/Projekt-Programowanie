#include "Avengers.h"
#include <iostream>
using namespace std;
Avengers::Avengers(string name)
{
	this->name = name;
}

Avengers::~Avengers()
{
}

void Avengers::Victory()
{
	cout << "Gratulacje! Uratowales cala galaktyke! ";
}

void Avengers::Introduction()
{
	cout << "Wybrales druzyne "<< this->name << ". Twoim zadaniem jest poprowadzic druzne, by znalezc kamienie nieskonczosci przed Thanosem!" << endl;
	cout << "Powodzenia! :)" << endl;
}
