#include "room.h"

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

Room::Room(string room_name, Room* n, Room* s, Room* e, Room* w, Monster* obj)
{
	name = room_name;
	north = n;
	south = s;
	east = e;
	west = w;

	roomMonster = obj;
}

Room::Room(string room_name, Room* n, Room* s, Room* e, Room* w, Item* obj)
{
	name = room_name;
	north = n;
	south = s;
	east = e;
	west = w;

	roomItem = obj;
}

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


//make sure these work and check if we need to set them to nullptr 

void Room::setName(string room_name)
{
	name = room_name;
}

string Room::getName()const
{
	return name;
}


void Room::setWestRoom(Room* W)
{
	W->east = this->west;
	west = W;
	//cout << "have now set west.";
}

void Room::setEastRoom(Room* E)
{
	E->west = this->east;
	east = E;
	//cout << "room is set to east.";
}

void Room::setNorthRoom(Room* N)
{
	N->south = this->north;
	north = N;
	//cout << "have now set north.";
}

void Room::setSouthRoom(Room* S)
{
	S->north = this->south;
	south = S;
	//cout << "have now set south.";
}

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

Room* Room::getEastRoom()const //need to change to &'s ???
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
