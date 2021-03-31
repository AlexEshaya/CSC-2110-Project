#pragma once
#include "character.h"

class Monster : public Character{
public:
	//constructor
	Monster(int, int);

	void decreaseAttackPower();

	//health mutator and accessor
	void setHP(int);
	int getHP() const;

	//AttackPower mutator and accessor
	void setAttackPower(int);
	int getAttackPower() const;
};
