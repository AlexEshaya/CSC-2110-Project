#include "hero.h"

// constructor with parameters!
Hero::Hero(int hP, int aP, int dP, int rC)
{
  hp = hP;
  attackPower = aP;
  defensePower = dP;
  retreatCount = rC;
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

void Hero::setDefensePower(int dP)
{
  if (dP => 1)
  {
    defensePower = dP;
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

void Hero::setHP(int h)
{
    health = h;
}
int Hero::getHP() const
{
    return health;
}

//AttackPower mutator and accessor
void Hero::setAttackPower(int ap)
{
    attackPower = ap;
}

int Hero::getAttackPower() const
{
    return attackPower;
}
