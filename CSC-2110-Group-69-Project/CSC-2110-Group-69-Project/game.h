#pragma once
#include <iostream>
#include "hero.h"
#include "room.h"
using namespace std;

class game{
  private:
	//private variables
		Room* previousRoom;
		Room* currentRoom;
		Room *rooms[8];
		Item* items[3];
		Monster* monsters[3];
		Room* rPtr;
		//Hero heroName;

		char input;
	//private functions
		void createMap();
  public:
	//public functions
		void run();
	//constructors
		game();
};
