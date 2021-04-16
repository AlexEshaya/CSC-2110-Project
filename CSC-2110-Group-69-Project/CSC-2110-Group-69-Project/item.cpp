#include "item.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

//Constructor
  Item::Item(int TypeInput, int ValueInput)
  {
    type = TypeInput; // Initialize type
    value = ValueInput; // Initialize value
  }

// Check if item is HP item
  bool Item::isHP() const
  {
    if (type == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

// Check if item is defense item
  bool Item::isDefense() const
  {
    if (type == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

// Check if item is attack item
  bool Item::isAttack() const
  {
    if (type == 2)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

// Use accessor function to get value of item
  int Item::getValue() const
  {
    return value;
  }
