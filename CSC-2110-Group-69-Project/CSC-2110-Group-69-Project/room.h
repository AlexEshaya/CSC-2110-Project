#pragma once
#include <string>
#include <iostream>
using namespace std;

class Room {
  private:
	//private variables
		string name;
		bool exit;
		//movement option declaration
		Room* east;
		Room* west;
		Room* north;
		Room* south;
		//room entity declaration
		Monster* roomMonster;
		Item* roomItem;
  public:
	//public functions
		//name accessor and mutator
		void setName(string);
		string getName() const;
		//movement option accessors and mutators
		void setEastRoom(Room*);
		void setWestRoom(Room*);
		void setNorthRoom(Room*);
		void setSouthRoom(Room*);
		Room* getEastRoom() const;
		Room* getWestRoom() const;
		Room* getNorthRoom() const;
		Room* getSouthRoom() const;
		//room entity accessors and mutators
		void setRoomMonster(Monster*);
		Monster* getRoomMonster() const;
		void setRoomItem(Item*);
		Item* getRoomItem() const;
		//room is exit check
		bool isExit();
  
  //Constructors
		Room(string, Room*,Room*,Room*,Room*,Monster*,Item*);
		Room(string, Room*,Room*,Room*,Room*,Monster*);
		Room(string, Room*,Room*,Room*,Room*,Item*);
		Room(string, Room*,Room*,Room*,Room*,bool);
};
