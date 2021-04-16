#include "room.h"

// Start and exit room type constructor
	Room::Room(string room_name, Room* n, Room* s, Room* e, Room* w, bool room)
	{
		name = room_name;
		north = n;
		south = s;
		east = e;
		west = w;

		if (room == true)
		{
			exit = true;
		}
	}

// Monster type constructor
	Room::Room(string room_name, Room* n, Room* s, Room* e, Room* w, Monster* obj)
	{
		name = room_name;
		north = n;
		south = s;
		east = e;
		west = w;

		roomMonster = obj;
	}

//item room type constructor
	Room::Room(string room_name, Room* n, Room* s, Room* e, Room* w, Item* obj)
	{
		name = room_name;
		north = n;
		south = s;
		east = e;
		west = w;

		roomItem = obj;
	}

//Monster and Item room type constructor
	Room::Room(string room_name, Room* n, Room* s, Room* e, Room* w, Monster* obj1, Item* obj2)
	{
		name = room_name;
		north = n;
		south = s;
		east = e;
		west = w;
		roomMonster = obj1;
		roomItem = obj2;
	}

//name accessor and mutator
	void Room::setName(string room_name)
	{
		name = room_name;
	}

	string Room::getName()const
	{
		return name;
	}


//movement option mutators
	void Room::setWestRoom(Room* W)
	{
		west = W;
		W->east = this;
	}

	void Room::setEastRoom(Room* E)
	{
		east = E;
		E->west = this;
	}

	void Room::setNorthRoom(Room* N)
	{
		north = N;
		N->south = this;
	}

	void Room::setSouthRoom(Room* S)
	{
		south = S;
		S->north = this;
	}

//movement option accessors
	Room* Room::getEastRoom()const
	{
		//cout << name << " is in the east room." << endl;
		return east;
	}

	Room* Room::getWestRoom()const
	{
		//cout << name << " is in the west room." << endl;
		return west;
	}

	Room* Room::getSouthRoom()const
	{
		//cout << name << " is in the east room." << endl;
		return south;
	}

	Room* Room::getNorthRoom()const
	{
		//cout << name << " is in the north room." << endl;
		return north;
	}

//room entity accessors and mutators
	Monster* Room::getRoomMonster() const
	{
		return roomMonster;
	}

	Item* Room::getRoomItem() const
	{
		return roomItem;
	}

	void Room::setRoomMonster(Monster *m)
	{
		roomMonster = m;
	}

	void Room::setRoomItem(Item *t)
	{
		roomItem = t;
	}

//room is exit check
	bool Room::isExit()
	{
		if (exit == true)
		{
			//cout << endl << "exit" << endl;
			return true;
		}
		else {
			//cout << endl << "not exit" << endl;
			return false;
		}
	}
