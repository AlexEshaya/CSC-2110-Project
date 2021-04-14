#include "hero.h"

// constructor with parameters!
//Hero::Hero() {} 

Hero::Hero(int hP, int aP, int dP, int rC)
{
    setHP(hP);
    setAttackPower(aP);
    setDefensePower(dP);
    retreatCount = rC;
    bag[0] = NULL;
    bag[1] = NULL;
    bag[2] = NULL;
}
// Functions!

// Overload the multiplication operator when multiplying Hero * Monster!
int Hero::operator*(Monster& m)
{ 
    m.setHP(m.getHP() - getAttackPower() < 0 ? 0 : m.getHP() - getAttackPower());
    setHP(getHP() - (m.getAttackPower() / getDefensePower()));

    m.decreaseAttackPower();
    decreaseDefensePower();

    if (getHP() == 0) // Hero died!
    {
        cout << endl << "The hero has perished!" << endl;
        return -1;
    }
    else if (m.getHP() == 0)  // Monster died!
    {
        cout << endl << "The monster has been defeated!" << endl;
        return 1;
    }
    else   // No character died!
    {
        cout << endl << "Blows exhanged.";
        return 0;
    }
}

// Get the value for defensePower!
int Hero::getDefensePower() const
{
    return defensePower;
}

// Decreases defensePower by 1!
void Hero::decreaseDefensePower()
{
    defensePower--;
}

// Set the value for defensePower!
void Hero::setDefensePower(int dP)
{
    // defensePower cannot be less than 1!
    if (dP >= 1)
    {
        defensePower = dP;
    }
}

// Get the value for retreatCount!
int Hero::getRetreatCount() const
{
    return retreatCount;
}

// Decreases retreatCount by 1!
void Hero::decreaseRetreatCount()
{
    retreatCount = retreatCount - 1;
}

bool Hero::anyItems() const 
{
    for (int i = 0; i < 3; i++)
    {
        // Returns false when ALL pointers in bag are NULL!
        if (bag[i] != NULL)
        {
            return true;
        }
    }
    return false;
}

bool Hero::isAlive() const
{
    if (health >= 1)
    {
        //cout << endl << "alive" << endl;
        return true;
    }
    else
    {
        //cout << endl << "dead" << endl;
        return false;
    }
}

//health point mutator
void Hero::setHP(int h)
{
    health = h;
}

//health points accessor
int Hero::getHP() const
{
    return health;
}

//AttackPower mutator
void Hero::setAttackPower(int ap)
{
    attackPower = ap;
}

//Attack Power mutator
int Hero::getAttackPower() const
{
    return attackPower;
}

//Checks which item is selected and adds the value
void Hero::useItem(int bagIndex) {
    if (bag[bagIndex]->isHP() == true) {
		setHP(getHP() + bag[bagIndex]->getValue());
        cout << "HP increased by " << bag[bagIndex]->getValue() << "!" << endl;
        bag[bagIndex] = NULL;
        displayStats();
	}
	else if (bag[bagIndex]->isDefense() == true) {
		setDefensePower(getDefensePower() + bag[bagIndex]->getValue());
        cout << "Defense increased by " << bag[bagIndex]->getValue() << "!" << endl;
        bag[bagIndex] = NULL;
        displayStats();
	}
	else if (bag[bagIndex]->isAttack() == true) {
		setAttackPower(getAttackPower() + bag[bagIndex]->getValue());
        cout << "Attack increased by" << bag[bagIndex]->getValue() << "!" << endl;
        bag[bagIndex] = NULL;
        displayStats();
	} 
    else {
		cout << "Empty slot. No Item used" << endl;
	}
}

//displays user information
void Hero::displayStats() {
    cout << endl << "// Hero Info //";
    cout << endl << "HP: " << getHP();
    cout << endl << "Atk Power: " << getAttackPower();
    cout << endl << "Defense Power: " << getDefensePower() << endl << endl;
}
