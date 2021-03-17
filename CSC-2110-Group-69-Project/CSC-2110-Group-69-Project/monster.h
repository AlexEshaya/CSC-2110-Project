#pragma once
#include <string>
#include <iostream>

#include "character.h"

class monster:
{
  public:
  void decreaseAttackPower(); // The decreaseAttackPower function decreases attackPower by 1
  
  Monster(int,int); // The arguments of the Monster’s constructor are hp, and attack power
};
