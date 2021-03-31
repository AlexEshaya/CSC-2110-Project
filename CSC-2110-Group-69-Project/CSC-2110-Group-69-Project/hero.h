#pragma once
#include "character.h"
#include "monster.h"
#include "item.h"
using namespace std;

class Hero : public Character{
  private:
    //private variables
    int defensePower;
    int retreatCount;
  public:
    //public variables
      Item* bag[3];
    //public functions
      int getDefensePower() const;
      void decreaseDefensePower();
      void setDefensePower(int);
      int getRetreatCount() const;
      void decreaseRetreatCount();
      bool anyItems() const;
      bool isAlive() const;
      int operator*(Monster& m);
      //health mutator and accessor
      void setHP(int);
      int getHP() const;

      //AttackPower mutator and accessor
      void setAttackPower(int);
      int getAttackPower() const;
    //constructors
      Hero();
      Hero(int, int, int, int);

      
};
