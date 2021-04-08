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
