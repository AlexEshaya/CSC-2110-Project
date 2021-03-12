#pragma once

class game{
  private:
	//private variables
		Room* currentRoom;
		Hero HeroName;
	//private functions
		void createMap();
  public:
	//public functions
		void run();
	//constructors
		Game();
};
