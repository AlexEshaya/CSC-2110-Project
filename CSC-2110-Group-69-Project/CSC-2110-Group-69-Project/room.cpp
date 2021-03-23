
#include "Header.h"

Room::Room(string room_name, Room* A, Room* B, Room* C, Room* D, bool final_room)
{
	name = room_name;
	north = A;
	south = B;
	east = C;
	west = D;
	exit = final_room;
}

//make rest of constructors

void Room::setName(string room_name) 
{
	name = room_name;
}

string Room::getName()const 
{
	return name;
}


void Room::setWestRoom(Room* B)
{
	B->east = this->west;
	west = B;
	cout << "have now set west.";
}

void Room::setEastRoom(Room* A)
{
	A->west = this->east;
	east = A;
	cout << "room is set to east.";
}

void Room::setNorthRoom(Room* C)
{
	C->south = this->north;
	north = C;
	cout << "have now set north.";
}

void Room::setSouthRoom(Room* D)
{
	D->north = this->south;
	south = D;
	cout << "have now set south.";
}



Room* Room::getEastRoom()const 
{
	cout << name << " is in the east room." << endl;
	return east;
}

Room* Room::getWestRoom()const
{
	cout << name << " is in the west room." << endl;
	return west;
}

Room* Room::getSouthRoom()const
{
	cout << name << " is in the east room." << endl;
	return south;
}

Room* Room::getNorthRoom()const
{
	cout << name << " is in the north room." << endl;
	return north;
}

bool Room::isExit() 
{
	if (exit == true)
	{
		cout << "You have won! This is the final room. GAME OVER";
		return true;
	}
	else 
	{
		cout << "You have been defeated! GAME OVER";
		return false;
	}

}



