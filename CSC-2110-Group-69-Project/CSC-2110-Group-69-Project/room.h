#pragma once

class Room:
{
  private:
  string name;
  
  Room* east;
  Room* west;
  Room* north;
  Room* south;
  
  Monster* roomMonster;
  Item* roomItem;
  bool exit;
  
  public:
  void setName(string);
  string getName() const;
  void setEastRoom(Room*);
  void setWestRoom(Room*);
  void setNorthRoom(Room*);
  void setSouthRoom(Room*);
  Room* getEastRoom() const;
  Room* getWestRoom() const;
  Room* getNorthRoom() const;
  Room* getSouthRoom() const;
  void setRoomMonster(Monster*);
  Monster* getRoomMonster() const;
  void setRoomItem(Item*);
  Item* getRoomItem() const;
  bool isExit();
  
  // Construct with parameters!
  Room(string, Room*,Room*,Room*,Room*,Monster*,Item*);
  Room(string, Room*,Room*,Room*,Room*,Monster*);
  Room(string, Room*,Room*,Room*,Room*,Item*);
  Room(string, Room*,Room*,Room*,Room*,bool);
};
