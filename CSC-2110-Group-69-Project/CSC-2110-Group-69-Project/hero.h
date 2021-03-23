#pragma once

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
};
