#include "Thanos.h"
#include <iostream>
using namespace std;
Thanos::Thanos(string nazwa)
{
	name = nazwa;
}

Thanos::~Thanos()
{
}

void Thanos::Victory()
{
	cout << "Gratulacje! Dzieki Tobie zniknela polowa istot na swiecie! ";
}

void Thanos::Introduction()
{
	cout << "Wybrales druzyne " <<this->name<<". Twoim zadaniem jest przywrocenie rownawagi na swiecie poprzez jedno pstrykniece!" << endl;
	cout << "Powodzenia! :)" << endl;
}
