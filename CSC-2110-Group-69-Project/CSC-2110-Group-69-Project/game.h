#include "room.h"
#include "hero.h"
#include <string>
#include <iostream>
using namespace std;

class game
{
 private:
	//private variables
	Room* previousRoom;
	Room* currentRoom;
	//Hero HeroName = Hero(100, 100, 100, 100);
	char input;
	//private functions
	void createMap();
 public:
	//public functions
	void run();
	//constructors
	game();
};
