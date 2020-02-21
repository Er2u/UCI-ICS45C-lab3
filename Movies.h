#ifndef MOVIES_H_
#define MOVIES_H_

#include "Renter.h"
class Movies {
private:
	string code, name;
	int count;
	Renter renters[10];
public:
	Movies();
	Movies(string code, string name);
	string getMovieCode();
	string getMovieName();
	int getRentedCopies();
	Renter getRneter(int i);
	void rentMovie(Renter renter);
	void returnRental(int rid);
	friend ostream& operator << (ostream& out, Movies& m);

};
#endif
