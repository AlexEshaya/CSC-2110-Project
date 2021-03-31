#pragma once
#include "character.h"

class Monster : public Character
{
  public:
  void decreaseAttackPower();
  Monster(int hp, int attackPower);
};
