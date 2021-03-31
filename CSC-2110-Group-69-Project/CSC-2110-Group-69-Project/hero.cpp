#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

#include "hero.h"

// Construct with parameters!
Hero(int hp, int attackPower, int defensePower, int retreatCount)
{
  // The arguments of the Hero’s constructor are hp, attack power, defense power, and retreat count
  // This constructor initializes the corresponding member variables and the bag with 3 null pointers
  Item*[3] bag;
}

// decreaseRetreatCount function decreases retreatCount by 1!
void decreaseRetreatCount()
{
  retreatCount = retreatCount - 1;
}

// decreaseDefensePower function decreases defensePower by 1!
void decreaseDefensePower()
{
  defensePower = defensePower - 1;
}

//  anyItems function returns false when all pointers in bag are NULL; otherwise, returns true!
bool anyItems()
{
  if (Item*[3] bag = NULL)
  {
    return false;
  }
  
  else
  {
    return true;
  }
}

// isAlive function returns true when hp is greater than 0; otherwise, returns false!
bool isAlive() const
{
  if (hp > 0)
  {
    return true;
  }
  
  else
  {
    return false;
  }
}
