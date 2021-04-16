#include "monster.h"

// Constructor!
    Monster::Monster(int hP, int aP)
    {
        health = hP;

        if (aP >= 1)
        {
            attackPower = aP;
        }
        else {
            attackPower = 0;
        }
    }

//Monster Functions
///////////////////////////////
// monster AttackPower mutator!
    void Monster::decreaseAttackPower()
    {
        attackPower = attackPower - 5;
    }

// monster Health mutator and accessor!
    void Monster::setHP(int h) 
    {
        health = h;
    }

    int Monster::getHP() const 
    {
        return health;
    }

// monster AttackPower mutator and accessor!
    void Monster::setAttackPower(int ap) 
    {
        attackPower = ap;
    }

    int Monster::getAttackPower() const 
    {
        return attackPower;
    }
