#include "game.h"

//Game Constructor
	game::game() { 
		createMap();
	}

//Game Functions
////////////////
//Create Map Function
	void game::createMap() {
		//Map items declaration
		Item* hpUP = new Item(0, 100);
		Item* dfUP = new Item(1, 50);
		Item* atkUP = new Item(2, 30);
		
		//Map monsters declaration
		Monster* m1 = new Monster(50, 45);
		Monster* m2 = new Monster(50, 45);
		Monster* m3 = new Monster(50, 45);
		Monster* m4 = new Monster(50, 45);


		//initialize starting room
		Room* start= new Room("Start", NULL ,NULL ,NULL ,NULL ,false);//may need to change to nullptr??
		//room 2
		Room* two = new Room("Room 2", NULL, NULL, NULL, NULL, m1);
		//room 3
		Room* three = new Room("Room 3", NULL, NULL, NULL, NULL, hpUP);
		//4a
		Room* fourA = new Room("Room 4A", NULL, NULL, NULL, NULL, m2, dfUP);
		//4b
		Room* fourB = new Room("Room 4B", NULL, NULL, NULL, NULL, m3);
		//room 5
		Room* five = new Room("Room 5", NULL, NULL, NULL, NULL, atkUP);
		//room 6
		Room* six = new Room("Room 6", NULL, NULL, NULL, NULL, m4);
		//initialize end room
		Room* end = new Room("Exit Room", NULL, NULL, NULL, NULL, true);

		//map build
		start->setEastRoom(two);

		two->setSouthRoom(three);

		three->setEastRoom(fourA);

		three->setSouthRoom(fourB);

		fourB->setSouthRoom(five);

		five->setEastRoom(six);

		six->setSouthRoom(end);

		currentRoom = start;
	}

//Game Run Function
	void game::run() {
		previousRoom = NULL;	

		//run while player is alive and not in exit room
		while (heroName->isAlive() == true && currentRoom->isExit() == false) {

			//current room information display//
			cout << "\n///////////////////////////////////////////////////////////////" << endl;
				cout << "Room: " << currentRoom->getName() << endl;

				//if monster and item display info
				if (currentRoom->getRoomMonster()!=NULL) {
					cout << "! This room has a monster !" << endl;
					cout << "Monster HP: " << currentRoom->getRoomMonster()->getHP() << endl; //?
					cout << "Monster AP: " << currentRoom->getRoomMonster()->getAttackPower() << endl; //?
				}
				//item information
				if (currentRoom->getRoomItem() != NULL) {
					cout << "! This room has an item !" << endl;
					if (currentRoom->getRoomItem()->isHP() == true) {
						cout << "Item: HP up" << endl; //?
					}
					else if (currentRoom->getRoomItem()->isDefense() == true) {
						cout << "Item: Defense up" << endl; //?
					}
					else if (currentRoom->getRoomItem()->isAttack() == true) {
						cout << "Item: Attack up" << endl; //?;
					}
					cout << "Item Value: " << currentRoom->getRoomItem()->getValue() << endl; //?
				}
				//if no monster and no item
				if(currentRoom->getRoomItem() == NULL && currentRoom->getRoomMonster() == NULL) {
					cout << endl << "This room is empty.";
				}


			//prompt for retreat if possible
				if (currentRoom->getName() == "Room 4A" && heroName->getRetreatCount() <= 0) {
					cout << endl << "You have lost your way and cannot retreat.";
					break;
				}
				if (currentRoom->getRoomItem() != NULL || currentRoom->getRoomMonster() != NULL) {
					if (heroName->getRetreatCount() >= 1 && previousRoom != NULL) {
						heroName->displayStats();
						cout << "Your hero has " << heroName->getRetreatCount() << " retreat(s) available." << endl;
						cout << "Would you like to retreat? (y/n): ";
						cin >> input;
						if (input == 'y' || input == 'Y') {
							heroName->decreaseRetreatCount();
							currentRoom = previousRoom;
							continue;
						}
					}
				}


			//USE ITEM PROCESS
				if (heroName->anyItems() == true) {

				//Prints bag contents
					if (heroName->anyItems() == true) {
						cout << "Bag Contents: " << endl;
						for (int i = 0; i < 3; i++) {
							if (heroName->bag[i] != NULL) {
								if (heroName->bag[i]->isHP() == true) {
									cout << "Slot " << i + 1 << ": HP Item" << endl;
								}
								else if (heroName->bag[i]->isDefense() == true) {
									cout << "Slot " << i + 1 << ": Defense Up Item" << endl;
								}
								else if (heroName->bag[i]->isAttack() == true) {
									cout << "Slot " << i + 1 << ": Attack Up Item" << endl;
								}
							}
							else {
								cout << "Slot " << i + 1 << ": Empty Slot" << endl;
							}
						}
					}

				//Process to actually use an item
					char useItemInput;
					int slotNumberInput;

				//prompt user for item use
					cout << "Use Item (y/n)? ";
					cin >> useItemInput;

				// While loop validates user input, if it is an incorrect an error message is produced. It then requests a new input.
					while (useItemInput != 'y' && useItemInput != 'n')
					{
						cout << "You have entered an incorrect option. Choose 'y' to use an item, or 'n' to not use an item: ";
						cin >> useItemInput;
					}

					if(useItemInput == 'y')
					{
					// If user chose to use an item, the item slot number is requested.
						cout << "Enter slot number (1 - 3)? ";
						cin >> slotNumberInput;

					// While loop validates user input, if it is an incorrect an error message is produced. It then requests a new input.
						while (slotNumberInput != 1 && slotNumberInput != 2 && slotNumberInput != 3)
						{
							cout << "You have entered an incorrect slot number. For slot 1, enter '1', for slot 2 enter '2', for slot 3 enter '3': ";
							cin >> slotNumberInput;
						}
						cout << endl;

					//Runs the useItem function based off which slot is chosen
						switch (slotNumberInput-1) {
						case 0:
							heroName->useItem(0);
							break;
						case 1:
							heroName->useItem(1);
							break;
						case 2:
							heroName->useItem(2);
							break;
						}
					}
					else if (useItemInput == 'n')
					{
						cout << "You have not used an item." << endl;
					}
				}

			//FIGHT PROCESS
				if (currentRoom->getRoomMonster() != NULL) {
					int fightCase;
					while (heroName->getHP() > 0 && currentRoom->getRoomMonster()->getHP() > 0) {
						fightCase = *heroName * *currentRoom->getRoomMonster();
					}
					//fight result handling
					switch (fightCase) {
					case -1:
						cout << endl << "The hero has perished!" << endl;
						break;
					case 1:
						cout << endl << "The monster has been defeated!" << endl;
						currentRoom->setRoomMonster(NULL);
					}
				}

			//PICK UP ITEM PROCESS
				int slotInput;
				if (currentRoom->getRoomItem() != NULL){

				//Prints bag contents
					cout << "Bag Contents: " << endl;
					for (int i = 0; i < 3; i++) {
						if (heroName->bag[i] != NULL) {
							if (heroName->bag[i]->isHP() == true) {
								cout << "Slot " << i + 1 << ": HP Item" << endl;
							}
							else if (heroName->bag[i]->isDefense() == true) {
								cout << "Slot " << i + 1 << ": Defense Up Item" << endl;
							}
							else if (heroName->bag[i]->isAttack() == true) {
								cout << "Slot " << i + 1 << ": Attack Up Item" << endl;
							}
						}
						else {
							cout << "Slot " << i + 1 << ": Empty Slot" << endl;
						}
					}
				//Prompts user for input
					cout << "Want to pick up Item (y/n)? ";
					cin >> input;

				//Run use item if user initializes
					if (input == 'y'||input=='Y') {
						cout << "Select slot to store item in (1 - 3): ";
						cin >> slotInput;

						//Deletes old item obj if present and new item obj to bag.
						slotInput--;
						if (heroName->bag[slotInput] != NULL){
							delete heroName->bag[slotInput];
							heroName->bag[slotInput] = NULL;
							heroName->bag[slotInput] = currentRoom->getRoomItem(); 
						} else{
							heroName->bag[slotInput] = currentRoom->getRoomItem(); 
						}
						//Removes reference to item obj from room
						currentRoom->setRoomItem(NULL);
					}
				}

			//MOVE ROOM PROCESS
				//Display room move options
					cout << endl << "Current Room: " << currentRoom->getName();
					if(currentRoom->getNorthRoom() != NULL) {
						cout << endl << "N) " << currentRoom->getNorthRoom()->getName();
					}
					if (currentRoom->getEastRoom() != NULL) {
						cout << endl << "E) " << currentRoom->getEastRoom()->getName();
					}
					if (currentRoom->getSouthRoom() != NULL) {
						cout <<endl << "S) " << currentRoom->getSouthRoom()->getName();
					}
					if (currentRoom->getWestRoom() != NULL) {
						cout << endl << "W) " << currentRoom->getWestRoom()->getName();
					}
				//Handles dead end case
					if (currentRoom->getWestRoom() == NULL && currentRoom->getSouthRoom() == NULL && currentRoom->getEastRoom() == NULL && currentRoom->getNorthRoom() == NULL) {
						cout << endl << "! This room is a dead end, you are forced to retreat !" << endl;
						heroName->decreaseRetreatCount();
						currentRoom = previousRoom;
						continue;
					}
				//if not dead end, prompt user input for direction to move
					else {
						cout << endl << "Enter letter of direction to move in: ";
						cin >> input;

					//execute room move
						previousRoom = currentRoom;
						currentRoom = NULL;

						while (currentRoom == NULL) {
							if (input == 'n' && previousRoom->getNorthRoom() != NULL) {
								currentRoom = previousRoom->getNorthRoom();
							}
							else if (input == 'e' && previousRoom->getEastRoom() != NULL) {
								currentRoom = previousRoom->getEastRoom();
							}
							else if (input == 's' && previousRoom->getSouthRoom() != NULL) {
								currentRoom = previousRoom->getSouthRoom();
							}
							else if (input == 'w' && previousRoom->getWestRoom() != NULL) {
								currentRoom = previousRoom->getWestRoom();

							}
							else {
								cout << endl << "invalid input!";
								cout << endl << "Enter letter of direction to move in: ";
								cin >> input;
							}
						}
					}	
	}
	
	//game end messages
	if (currentRoom->isExit()) {
		cout << endl << "Congratulations!";
		cout << endl << "You Win!";
	 }
	else {
		cout << endl << "Game over";
		cout << endl << "You Lose!";
	}

}
