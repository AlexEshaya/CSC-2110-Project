#pragma once
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

// Declare Item Class
class Item
{
private:
  int type; // 0 = hp, 1 = defense, 2 = attack. An ATTACK ITEM will be our unique feature for the game.
  int value; // Will dictate the value of the hp, defense, or attack item.
public:
  bool isHP() const; // Checks to see if item is an HP item
  bool isDefense() const; // Checks to see if item is a Defense item
  bool isAttack() const; // Checks to see if item is an attack item
  int getValue() const; // Outputs value of item. This is an accessor, the item class does not have a mutator for value.
  Item(int, int); // arguments are type and value
}
