#include "game.h"

game::game() {
	
}

void game::createMap() {
	Item hpUP(0, 100);
	Item dfUP(1, 50);
	Item atkUP(2, 30);
	Monster m1(500, 45);
	Monster m2(500, 45);
	Monster m3(500, 45);
	Monster m4(500, 45);

	//initialize starting room
	Room start("Start", NULL ,NULL ,NULL ,NULL ,true);
	*monstrPtr = m1;
	//room 2
	Room two("Room 2", NULL, NULL, NULL, NULL, monstrPtr);
	*itemPtr = hpUP;
	//room 3
	Room three("Room 3", NULL, NULL, NULL, NULL, itemPtr);
	//4a
	*itemPtr = dfUP;
	*monstrPtr = m2;
	Room fourA("Room 4", NULL, NULL, NULL, NULL, monstrPtr, itemPtr);
	//4b
	*monstrPtr = m3;
	Room fourB("Room 4", NULL, NULL, NULL, NULL, monstrPtr);
	//room 5
	*itemPtr = atkUP;
	Room five("Room 5", NULL, NULL, NULL, NULL, itemPtr);
	//room 6
	*monstrPtr = m4;
	Room six("Room 6", NULL, NULL, NULL, NULL, monstrPtr);	
	//initialize end room
	Room end("Exit Room", NULL, NULL, NULL, NULL, false);

	//map build
	*rPtr = two;
	start.setEastRoom(rPtr);
	//*rPtr
}

void game::run() {
	//create map
	createMap();

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
	/*while (heroName.isAlive() && !(currentRoom->isExit()) == true) {


		//current room information display//
		cout << "//Room: " << currentRoom->getName() << endl;
			//monster information
		if (currentRoom->getRoomMonster()!=NULL) {
			cout << "!This room has a monster!" << endl;
			cout << "Monster HP: " << currentRoom->getRoomMonster()->getHP() << endl; //?
			cout << "Monster AP: " << currentRoom->getRoomMonster()->getAttackPower() << endl; //?
		}
			//item information
		else if (currentRoom->getRoomItem() != NULL) {
			cout << "!This room has an item!";
			cout << "Item: " << currentRoom->getRoomItem(); //?
			cout << "Item Value: " << currentRoom->getRoomItem()->getValue(); //?
		}
			//if no monster and no item
		else {
			cout << "//Monster Status//" << endl;
			cout << "Room " << currentRoom->getName() << "is empty." << endl;
		}

			//prompt for retreat if possible
		if (heroName.getRetreatCount() != 0 && previousRoom!=NULL) {

			cout << "Your hero has " << heroName.getRetreatCount() << " retreat(s) available." << endl;
			cout << "Would you like to retreat? (y/n): ";
			cin >> input;
			if (input = 'y') {
				heroName.decreaseRetreatCount();
				currentRoom = previousRoom;
			}
		}

		//item use prompt

		//fight

		//death check
		//pickup item
		//move rooms
			
	}
	
	//game end messages
	if (currentRoom->isExit()) {
		cout << "Congratulations!";
	 }
	else {
		cout << "Game over";
	}

}*/
