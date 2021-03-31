#include "hero.h"

//constructor
Hero::Hero(int hp, int attackPower, int defensePower, int retreatCount)
{
  Item*[3] bag;
}

//functions
const int Hero::getDefensePower()
{
  
}

void Hero::decreaseDefensePower()
{
  defensePower = defensePower - 1;
}

void Hero::setDefensePower(int)
{
  
}

const int Hero::getRetreatCount()
{
  
}

void Hero::decreaseRetreatCount()
{
  retreatCount = retreatCount - 1;
}

const bool Hero::anyItems()
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

const bool Hero::isAlive()
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
