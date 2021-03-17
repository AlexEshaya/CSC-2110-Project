#pragma once
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

#include "character.h"

class Hero : public character
{
  private:
  int defencePower;
  int retreatCount;
  
  public:
  Item*[3] bag;
  int getDefensePower() const;
  int getRetreatCount() const;
  int operator*(Monster& m);
  void decreaseDefensePower(); // The decreaseDefensePower function decreases defensePower by 1
  void decreaseRetreatCount(); // The decreaseRetreatCount function decreases retreatCount by 1
  void setDefensePower(int);
  bool anyItems(); //  The anyItems function returns false when all pointers in bag are NULL; otherwise, returns true
  bool isAlive() const; // The isAlive function returns true when hp is greater than 0; otherwise, returns false
  
  // The arguments of the Hero’s constructor are hp, attack power, defense power, and retreat count
  // This constructor initializes the corresponding member variables and the bag with 3 null pointers
  Hero(int,int,int,int);
};
