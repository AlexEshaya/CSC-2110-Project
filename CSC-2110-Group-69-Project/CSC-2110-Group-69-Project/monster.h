#pragma once
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

#include "character.h"

class monster : public character:
{
  public:
  void decreaseAttackPower(); // The decreaseAttackPower function decreases attackPower by 1
  
  Monster(int,int); // The arguments of the Monster’s constructor are hp, and attack power
};
