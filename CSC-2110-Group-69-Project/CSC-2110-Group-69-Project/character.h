#pragma once
#using namespace std;

class character{
  protected:
	int hp;
	int attackPower;
  public:
	void setHP(int);
	const int getHP();
	void setAttackPower(int);
	const int getAttackPower();
};
