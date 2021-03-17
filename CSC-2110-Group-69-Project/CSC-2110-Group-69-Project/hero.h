#pragma once
#include <string>
#include <iostream>

#include "character.h"

class Hero:
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
