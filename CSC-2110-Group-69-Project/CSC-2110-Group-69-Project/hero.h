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
  void decreaseDefensePower();
  void setDefensePower(int);
  int getRetreatCount() const;
  void decreaseRetreatCount();
  bool anyItems();
  bool isAlive() const;
  int operator*(Monster& m);
  
  Hero(int,int,int,int);
};
