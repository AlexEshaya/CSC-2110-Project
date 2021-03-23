#pragma once

class game{
  private:
	//private variables
		Room* previousRoom;
		Room* currentRoom;
		Hero HeroName;
		char input;
	//private functions
		void createMap();
  public:
	//public functions
		void run();
	//constructors
		Game();
};
