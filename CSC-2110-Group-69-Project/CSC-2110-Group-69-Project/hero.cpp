#include "hero.h"

// constructor with parameters!
Hero::Hero(int hp, int attackPower, int defensePower, int retreatCount)
{
  hp = hp;
  attackPower = attackPower;
  defensePower = defensePower;
  retreatCount = retreatCount;
  Item*[3] bag;
}

// functions!
int operator*(Monster& m)
{
  Monster.hp = Monster.hp - hero.attackPower < 0 ? 0 : Monster.hp-hero.attackPower;
  hero.hp = hero.hp - Monster.attackPower/hero.defensePower;
  
  Monster.decreaseAttackPower;
  hero.decreaseDefensePower;
  
  if (hero.hp == 0) // hero died
  {
    return -1;
  }
  
  else if (Monster.hp == 0)  // monster died
  {
    return 1;
  }
  
  else   // no character died
  {
    return 0;
  }
}

const int Hero::getDefensePower()
{
  return defensePower;
}

void Hero::decreaseDefensePower()
{
  defensePower = defensePower - 1;
}

void Hero::setDefensePower(int defensePower)
{
  if (defensePower => 1)
  {
    defensePower = defensePower;
  }
}

const int Hero::getRetreatCount()
{
  return retreatCount;
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
