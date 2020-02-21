#ifndef RENTER_H_
#define RENTER_H_

#include "Exceptions.cpp"

class Renter {
private:
	int id;
	string first, last;
public:
	Renter();
	Renter(int id, string fn, string ln);
	void setRenterID(int id);
	void setRenterFirstName(string fn);
	void setRenterLastName(string ln);
	int getRenterID();
	string getRenterFirstName();
	string getRenterLastName();
};
#endif
