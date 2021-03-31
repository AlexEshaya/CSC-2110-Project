#include "hero.h"

// constructor with parameters!
Hero::Hero() {

}
Hero::Hero(int hP, int aP, int dP, int rC)
{
    health = hP;
    attackPower = aP;
    defensePower = dP;
    retreatCount = rC;
    Item* bag[3];
}

// functions!
int operator*(Monster& m)
{
   /*Monster.hp = Monster.hp - hero.attackPower < 0 ? 0 : Monster.hp - hero.attackPower;
    hero.hp = hero.hp - Monster.attackPower / hero.defensePower;

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
    }*/
}

int Hero::getDefensePower() const
{
    return defensePower;
}

void Hero::decreaseDefensePower()
{
    defensePower = defensePower - 1;
}

void Hero::setDefensePower(int dP)
{
    if (dP >= 1)
    {
        defensePower = dP;
    }
}

int Hero::getRetreatCount() const
{
    return retreatCount;
}

void Hero::decreaseRetreatCount()
{
    retreatCount = retreatCount - 1;
}

 bool Hero::anyItems() const
{
    if (Item* bag[3] = NULL)
    {
        return false;
    }

    else
    {
        return true;
    }
}

bool Hero::isAlive() const
{
    if (health > 0)
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

