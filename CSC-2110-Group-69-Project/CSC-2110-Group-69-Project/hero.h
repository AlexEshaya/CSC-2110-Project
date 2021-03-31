#include "character.h"
#include "item.h"
#include "monster.h"
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
      const int getDefensePower();
      void decreaseDefensePower();
      void setDefensePower(int);
      const int getRetreatCount();
      void decreaseRetreatCount();
      const bool anyItems();
      const bool isAlive();
      int operator*(Monster& m);
    //constructors
      Hero(int, int, int, int);
  
    //health mutator and accessor
      void setHP(int);
      int getHP() const;

    //AttackPower mutator and accessor
      void setAttackPower(int);
      int getAttackPower() const;
};
