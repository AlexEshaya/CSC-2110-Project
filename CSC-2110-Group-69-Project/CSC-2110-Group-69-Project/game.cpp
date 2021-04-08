#include "game.h"

game::game() { //Intialize hero
	
	createMap();
}

void game::swap(Room* xp, Room* yp)
{
	Room temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void game::createMap() {
	Item* hpUP = new Item(0, 100);
	Item* dfUP = new Item(1, 50);
	Item* atkUP = new Item(2, 30);

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
	Room* fourA = new Room("Room 4", NULL, NULL, NULL, NULL, m2, dfUP);
	//4b
	Room* fourB = new Room("Room 4", NULL, NULL, NULL, NULL, m3);
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

void game::run() {
	Hero heroName(100, 20, 10, 10); // fix inheritence later!
	previousRoom = NULL;
	
	//While (hero.alive and !currentRoom.isExit){
		//Show room information (name, monster’s info, item’s info).
		//If Retreat? { // ask user if wants to retreat, assuming retreat count >0
			//Move to previousRoom
			//Decrease retreat count
		//}

		//If hero.gotItems? {
			//Want to use it? {
				//Execute “use an item” process
			//}
		//}

		//if currentRoom.gotMonster? {
			//battle! // repeat battle until monster or hero wins
		//}

		//if hero.alive? {
			//if currentRoom.gotItem? {
				//Want to pick it up? {
					//execute “pick up item” process
				//}
			//}

			//execute “move” process (and update previousRoom pointer)
		//}	
	//}

	//run while player is alive and not in exit room
	while (heroName.isAlive() == true && currentRoom->isExit() == false) {


		//current room information display//
			cout << "//Room: " << currentRoom->getName() << endl;
			
			//if monster and item display info
			if (currentRoom->getRoomMonster()!=NULL) {
				cout << "!This room has a monster!" << endl;
				cout << "Monster HP: " << currentRoom->getRoomMonster()->getHP() << endl; //?
				cout << "Monster AP: " << currentRoom->getRoomMonster()->getAttackPower() << endl; //?
			}
			//item information
			if (currentRoom->getRoomItem() != NULL) {
				cout << "!This room has an item!";
				cout << "Item: " << currentRoom->getRoomItem(); //?
				cout << "Item Value: " << currentRoom->getRoomItem()->getValue(); //?
			}
			//if no monster and no item
			else {
				cout << endl << "This room is empty.";
			}
		

		//prompt for retreat if possible
			if (heroName.getRetreatCount() != 0 && previousRoom!=NULL) {

				cout << "Your hero has " << heroName.getRetreatCount() << " retreat(s) available." << endl;
				cout << "Would you like to retreat? (y/n): ";
				cin >> input;
				if (input == 'y') {
					heroName.decreaseRetreatCount();
					currentRoom = previousRoom;
				}
			}

		//USE ITEM PROCESS
		if (heroName.anyItems() == true) {
			
			//Prints bag contents
			for (int i = 0; i < 3; i++) {
				if (heroName.bag[i]->isHP() == true) {
					cout << "Slot " << i + 1 << ": HP Item" << endl;
				}
				else if (heroName.bag[i]->isDefense() == true) {
					cout << "Slot " << i + 1 << ": Defense Up Item" << endl;
				} 
				else if (heroName.bag[i]->isAttack() == true) {
					cout << "Slot " << i + 1 << ": Attack Up Item" << endl;
				} else {
					cout << "Slot " << i + 1 << ": Empty Slot" << endl;
				}
			}

			//Process to actually use an item
			char useItemInput;
			int slotNumberInput;
			
			cout << "Use Item (y/n)?";
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
					heroName.useItem(0);
					break;
				case 1:
					heroName.useItem(1);
					break;
				case 2:
					heroName.useItem(2);
					break;
				}
			}
			else if (useItemInput == 'n')
			{
				cout << "You have chosen to not use an item." << endl;
			}
		}
		//fight
		if (currentRoom->getRoomMonster() != NULL) {
			while (heroName.getHP() > 0 && currentRoom->getRoomMonster()->getHP() > 0) {
				switch (heroName * *currentRoom->getRoomMonster()) {
				case -1: //hero death case
					cout << "You died";
					break;
				case 0: //monster death case
					cout << "The monster died";
					break;
				case 1: //no death
					break;
				}
			}
		}
		//pickup item
		int slotInput;
		if (currentRoom->getRoomItem() != NULL){ 
			//Prints bag contents
			cout << "Bag Contents: " << endl;
			for (int i = 0; i < 3; i++) {
				if (heroName.bag[i]->isHP() == true) {
					cout << "Slot " << i + 1 << ": HP Item" << endl;
				}
				else if (heroName.bag[i]->isDefense() == true) {
					cout << "Slot " << i + 1 << ": Defense Up Item" << endl;
				} 
				else if (heroName.bag[i]->isAttack() == true) {
					cout << "Slot " << i + 1 << ": Attack Up Item" << endl;
				} else {
					cout << "Slot " << i + 1 << ": Empty Slot" << endl;
				}
			}
			//Prompts user for input
			cout << "Want to pick up Item (y/n)? ";
			cin >> input;

			if (input == 'y'||input=='Y') {
				cout << "Select slot to store item in (1 - 3): ";
				cin >> slotInput;

				//Deletes old item obj if present and new item obj to bag.
				if (heroName.bag[slotInput] != NULL){
					delete heroName.bag[slotInput];
					heroName.bag[slotInput] = currentRoom->getRoomItem(); 
				} else{
					heroName.bag[slotInput] = currentRoom->getRoomItem(); 
				}
				//Removes reference to item obj from room
				delete currentRoom->getRoomItem();
			}
		}
		//move rooms
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

		cout << endl << "Enter letter of direction to move in: ";
		cin >> input;

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
		cout << endl;

			
	}
	
	//game end messages
	if (currentRoom->isExit()) {
		cout << "Congratulations!";
	 }
	else {
		cout << "Game over";
	}

}
