//==========================================================
//
// Title:      Final Project
// Course:     CSC 2110
// Author:     Lucas "Wolverine" Jackman, Neil the creator of Rastogi, Luke Javier without the J, Alexander of Eshaya, Soham hailing from Bhavsar
// Date:       3/11/2021
// Description:
//	A simple C++ game. In this game, the player moves a character 
//  (hero) through multiple rooms to get to the exit. 
//  In some of the rooms, the hero may find other characters (monsters) and items. 
//  The hero will battle the enemies and take the times.
//  The player wins when the hero reaches the exit.
//  The player loses when hero’s health points(HP) are zero(0).
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <ctype.h> // For alphanumeric check
#include "game.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{
	// App Header!
	cout << "|////////////////////////////|" << endl;
	cout << "|   Group 69 Final Project   |" << endl;
	cout << "|////////////////////////////|" << endl << endl;
	
	//game run
	game newGame;
	newGame.run();
	
	// App Close!
	return 0;
}
