#include "Movies.h"
Movies::Movies() {
	this->code = "";
	this->name = "";
	this->count = 0;
	for (int i = 0; i < 10; i++) {
		this->renters[i] = Renter();
	}
}

Movies::Movies(string code, string name) {
	this->code = code;
	this->name = name;
	this->count = 0;
	for (int i = 0; i < 10; i++) {
		this->renters[i] = Renter();
	}
}

string Movies::getMovieCode() {
	return this->code;
}

string Movies::getMovieName() {
	return this->name;
}

int Movies::getRentedCopies() {
	return this->count;
}

Renter Movies::getRneter(int i) {
	return this->renters[i];
}

void Movies::rentMovie(Renter renter) {
	if (this->count >= 10) {
		throw RenterLimitException();
	}
	for (int i = 0; i < 10; i++) {
		Renter a = this->renters[i];
		if (renter.getRenterID() == a.getRenterID()) {
			throw DuplicateRenterException();
		}
	}
	if (renter.getRenterID() <= 0) {
			throw InvalidRenterIDException();
	}
	if ( renter.getRenterFirstName() == "" || renter.getRenterLastName() == "") {
			throw EmptyRenterNameException();
	}
	this->renters[count] = renter;
	this->count++;
}

void Movies::returnRental(int rid) {
	if (this->count == 0) {
		throw EmptyRenterListException();
	}
	if (rid <= 0) {
		throw InvalidRenterIDException();
	}
	int i;
	for (i = 0; i < this->count; i++) {
		if (this->renters[i].getRenterID() == rid) {
			break;
		}
	}
	if (i >= this->count - 1 && this->renters[i].getRenterID() != rid) {
		throw RenterNotFoundException();
	}
	else {
		int j;
		for (j = i; j+1 < this->count; j++) {
			this->renters[j] = this->renters[j + 1];
		}
		this->renters[j + 1] = Renter();
		this->count--;
	}
}

ostream& operator << (ostream& out, Movies& m) {
	string str;
	str = "Movie ID : " + m.getMovieCode() + "\nMovie Name: " + m.getMovieName() + "\nAlready Rented: " + to_string(m.getRentedCopies());
	if (m.getRentedCopies() > 0) {
		str += "\nRenters: " + m.getRneter(0).getRenterFirstName() + " " + m.getRneter(0).getRenterLastName() + " " + to_string(m.getRneter(0).getRenterID());
		for (int i = 1; i < m.getRentedCopies(); i++) {
			str += ", " + m.getRneter(i).getRenterFirstName() + " " + m.getRneter(i).getRenterLastName() + " " + to_string(m.getRneter(i).getRenterID());
		}
	}
	else {
		str += "\nRenters: None";
	}
	out << str;
	return out;
}