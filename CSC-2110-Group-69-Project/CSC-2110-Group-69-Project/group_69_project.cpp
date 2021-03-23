//==========================================================
//
// Title:      Final Project
// Course:     CSC 2110
// Author:     Lucas Jackman, Neil Rastogi, Luke Javier,
// Date:       3/11/2021
// Description:
//	A C++ console based game.
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
	//header
	cout << "|//////////////|" << endl;
	cout << "|   Group 69   |" << endl;
	cout << "|//////////////|" << endl;
	
	//game run
	game newGame;
	newGame.run();
	
	//end of program
	cout << endl << endl << "end." << endl;
	return 0;
	
	// OWA OWA
}
