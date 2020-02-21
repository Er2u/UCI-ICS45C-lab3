#include "MovieManagerUI.h"

void MovieManagerUI::printMenu(){
	cout << "----------\nam: Add Movie\ndm : Discontinue Movie\nrm : Rent Movie\nrr : Return Rental\np : Print Movie Inventory\nq : Quit Program\n----------\n";
}

string MovieManagerUI::getCommand() {
	string cmd;
	cout << "Enter Command: ";
	cin >> cmd;
	return cmd;
}
