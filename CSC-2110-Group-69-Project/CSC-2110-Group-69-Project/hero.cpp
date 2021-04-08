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

// Functions!

// Overload the multiplication operator when multiplying Hero * Monster!
int Hero::operator*(Monster& m)
{ 
    m.setHP(m.getHP() - getAttackPower() < 0 ? 0 : m.getHP() - getAttackPower());
    setHP(getHP() - m.getAttackPower() / getDefensePower());

    m.decreaseAttackPower();
    decreaseDefensePower();

    if (getHP() == 0) // Hero died!
    {
        return -1;
    }
    else if (m.getHP() == 0)  // Monster died!
    {
        return 1;
    }
    else   // No character died!
    {
        return 0;
    }
}

// Get the value for defensePower!
int Hero::getDefensePower() const
{
    return defensePower;
}

// DefensePower mutator!
void Hero::decreaseDefensePower()
{
    defensePower = defensePower - 1;
}

// DefensePower mutator!
void Hero::setDefensePower(int dP)
{
    // defensePower cannot be less than 1!
    if (dP >= 1)
    {
        defensePower = dP;
    }
}

// RetreatCount accessor!
int Hero::getRetreatCount() const
{
    return retreatCount;
}

// RetreatCount mutator!
void Hero::decreaseRetreatCount()
{
    retreatCount = retreatCount - 1;
}

// items in bag validator!
bool Hero::anyItems() const 
{
    for (int i = 0; i < 3; i++)
    {
        // Returns false when ALL pointers in bag are NULL!
        if (bag[i] == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

// Alive validator!
bool Hero::isAlive() const
{
    if (health >= 1)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// HEALTH mutator and accessor!
void Hero::setHP(int h)
{
    health = h;
}

int Hero::getHP() const
{
    return health;
}

// AttackPower mutator and accessor!
void Hero::setAttackPower(int ap)
{
    attackPower = ap;
}

int Hero::getAttackPower() const
{
    return attackPower;
}

// Checks which item is selected and adds the value
void Hero::useItem(int bagIndex) {
    if (bag[bagIndex]->isHP() == true) {
		setHP(getHP() + bag[bagIndex]->getValue());
	}
	else if (bag[bagIndex]->isDefense() == true) {
		setDefensePower(getDefensePower() + bag[bagIndex]->getValue());
	}
	else if (bag[bagIndex]->isAttack() == true) {
		setAttackPower(getAttackPower() + bag[bagIndex]->getValue());
	} else {
		cout << "Empty slot. No Item used" << endl;
	}
}
