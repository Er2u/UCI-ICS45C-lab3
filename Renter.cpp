#include "Renter.h"

Renter::Renter() {
	this->id = 0;
	this->first = "";
	this->last = "";
}

Renter::Renter(int id, string fn, string ln) {
	this->id = id;
	this->first = fn;
	this->last = ln;
}
void Renter::setRenterID(int id) {
	this->id = id;
}

void Renter::setRenterFirstName(string fn) {
	this->first = fn;
}

void Renter::setRenterLastName(string ln) {
	this->last = ln;
}

int Renter::getRenterID() {
	return this->id;
}

string Renter::getRenterFirstName() {
	return this->first;
}

string Renter::getRenterLastName() {
	return this->last;
}