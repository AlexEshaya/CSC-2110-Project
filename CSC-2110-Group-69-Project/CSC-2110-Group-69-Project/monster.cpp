#include "monster.h"

Monster::Monster(int hP, int aP)
{
  hp = hP;
  
  if (aP => 1)
  {
    attackPower = aP;
  }
}

void Monster::decreaseAttackPower()
{
  attackPower = attackPower - 1;
}
