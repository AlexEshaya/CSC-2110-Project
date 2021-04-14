#pragma once
#include <iostream>
#include "hero.h"
#include "room.h"
using namespace std;

class game 
{
  private: 
	//private variables
		Room* previousRoom;
		Room* currentRoom;
		Room *rooms[8];
		Monster* mPtr;
		Hero* heroName = new Hero(75, 25, 10, 3);
		char input;
	//private functions
		void createMap();
  public:
	//public functions
		void run();
		void swap(Room*, Room*);
	//constructors
		game();
};
