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
		Monster* monsters[3];
		Item* itemPtr;
		Monster* monstrPtr;
		Room* rPtr;
	

		Hero heroName(int,int,int,int);
		char input;
	//private functions
		void createMap();
  public:
	//public functions
		void run();
	//constructors
		game();
};
