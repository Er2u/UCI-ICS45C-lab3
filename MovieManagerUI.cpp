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

string MovieManagerUI::getMovieName() {
	string mn;
	cout << "Please enter Movie Name: ";
	cin >> mn;
	return mn;
}

string MovieManagerUI::getMovieCode() {
	string code;
	cout << "Please enter Movie Code: ";
	cin >> code;
	return code;
}

int MovieManagerUI::getRenterID() {
	int id;
	cout << "Please enter Renter ID: ";
	cin >> id;
	return id;
}

string MovieManagerUI::getRenterFirstName() {
	string fn;
	cout << "Please enter Renter's First Name: ";
	cin >> fn;
	return fn;
}

string MovieManagerUI::getRenterLastName() {
	string ln;
	cout << "Please enter Renter's Last Name: ";
	cin >> ln;
	return ln;
}

string MovieManagerUI::toUpper(string cmd) {
	if (cmd == "q" || cmd == "Q") {
		return "Q";
	}
	else if (cmd == "p" || cmd == "P") {
		return "P";
	}
	else if (cmd == "am" || cmd == "Am" || cmd == "aM") {
		return "AM";
	}
	else if (cmd == "dm" || cmd == "Dm" || cmd == "dM") {
		return "DM";
	}
	else if (cmd == "rm" || cmd == "Rm" || cmd == "rM") {
		return "RM";
	}
	else if (cmd == "rr" || cmd == "Rr" || cmd == "rR") {
		return "RR";
	}
	else {
		return "Error";
	}
}