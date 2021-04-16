#pragma once
using namespace std;

class Character
{
	public:
		//Public functions
			//HP mutator and accessor
			virtual void setHP(int) = 0;
			virtual int getHP() const = 0;
	
			//AttackPower mutator and accessor
			virtual void setAttackPower(int) = 0;
			virtual int getAttackPower() const = 0;

	protected:
		//Protected Variables
			int health;
			int attackPower;
};
