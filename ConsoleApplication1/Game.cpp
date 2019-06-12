#include "Game.h"
#include "test.cpp"
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include "Ground.h"
#include <set>
#include "Treasure.h"

using namespace std;

Game::Game()
{
	//RZECZY DO ZROBIENIA PRZED URUCHOMIENIEM GLOWNEJ PETLI

	//Stworz obiekty map
	Map mapa1("map.txt");
	Map mapa2("map2.txt");

	//Stworz obiekt gracza
	Player gracz('@');
	//Przypisz gracza do atrybutu gracz klasy Gra
	this->player = gracz;

	//Wybierz poczatkowa mape
	this->current_map = mapa1;
	this->map = 1;
	//ustaw poczatkowy prevObject
	this->prevObject = current_map.matrix[16][19];
	//Dodaj gracza na mape
	this->current_map.matrix[16][19] = this->player;

	set<string>backpack;
	set<string>::iterator it;
	backpack.insert("Soul Stone");
	backpack.insert("Time Stone");

	// GLOWNA PETLA GRY 
	while (2) {
		this->drawMap();

		//Legenda
		std::cout << std::endl << "Aby wyjsc wpisz 'q'." << std::endl;
		std::cout << "Aktualna  mapa: "<< this->map << std::endl;

		//zbieranie przedmiotow
		if(prevObject.isTreasure==true)
		{
			switch (prevObject.getLook())
			{
			case '$':
				backpack.insert("Space Stone");
				break;
			case '#':
				backpack.insert("Mind Stone");
				break;
			case '&':
				backpack.insert("Reality Stone");
				break;
			case '%':
				backpack.insert("Power Stone");
				break;
			}
		}

		cout << "Twoja pozycja: |"<<this->player.getY() << "|" << this->player.getX() <<"|"<< endl;
		cout << "Plecak:";

		for (it = backpack.begin(); it != backpack.end(); ++it)
		{
			cout <<" ["<< *it<<"] ";
		}

		cout << endl << backpack.size() << "\\6" << endl;

		if (backpack.size() == 6) 
		{
			break;
		}

		char direction;
		direction = _getch();

		if (direction == 'w')
		{
		
			//zmienia y-1
			/*
			if (this->player.getY() == 0)
			{
				if (this->map == 3) {
					this->current_map = mapa1;
					this->map = 1;
					this->prevObject = this->current_map.matrix[0][this->player.getX()];
					this->setPlayer(19, this->player.getX());
				}
			}
			else */if (this->current_map.matrix[this->player.getY() - 1][this->player.getX()].canWalk()) {

				this->setPlayer(this->player.getY() - 1, this->player.getX());
				
			}
			system("CLS");
		}

		else if (direction == 's')
		{
			//zmienia y+1
			/*if (this->player.getY() == 19)
			{
				if (this->map == 1) {
					this->current_map = mapa3;
					this->map = 3;
					this->prevObject = this->current_map.matrix[this->player.getY()][19];
					this->setPlayer(0,this->player.getX());
				}
			}
			else */if (this->current_map.matrix[this->player.getY() + 1][this->player.getX()].canWalk()) {
				this->setPlayer(this->player.getY() + 1, this->player.getX());
			}
			system("CLS");
		}

		else if (direction == 'a')
		{
			//zmienia y-1
			if (this->player.getX() == 0)
			{
				if (this->map == 2) {
					this->current_map = mapa1;
					this->map = 1;
					this->prevObject = this->current_map.matrix[this->player.getY()][0];
					this->setPlayer(this->player.getY(),79);
				}
			}
			else if (this->current_map.matrix[this->player.getY()][this->player.getX() - 1].canWalk()) {
				this->setPlayer(this->player.getY(), this->player.getX() - 1);
			}
			system("CLS");
		}


		else if (direction == 'd')
		{
			
			//zmienia x+1
			if (this->player.getX() == 79)
			{
				if (this->map == 1) {
					this->current_map = mapa2;
					this->map = 2;
					this->prevObject = this->current_map.matrix[this->player.getY()][79];
					this->setPlayer(this->player.getY(),0);
				}
			}
			else if (this->current_map.matrix[this->player.getY()][this->player.getX() + 1].canWalk()) {
				this->setPlayer(this->player.getY(), this->player.getX() + 1);
			}
			system("CLS");
		}

		else if (direction == 'q') {
			break;
		}
		else system("CLS");


	}

}


Game::~Game(){}

void Game::drawMap() {
	current_map.printMap();
}

//wykonuje sie, gdy object.canWalk()=true
void Game::setPlayer(int new_y, int new_x)
{
	//Zaczytaj obiekt w miejscu gdzie chce sie ruszczyc gracz
	this->nextObject= this->current_map.matrix[new_y][new_x];
	//Przesun gracza na nowe miejsce
	this->current_map.matrix[new_y][new_x] = this->player;
	//Zaczytaj obiekt ktory znajdowal sie na poprzednim miejscu gracza
	this->current_map.matrix[this->player.getY()][this->player.getX()] = this->prevObject;
	//Uaktualnij pozycje gracza w jego atrybutach
	this->player.setX(new_x);
	this->player.setY(new_y);

	this->prevObject = this->nextObject;
}
