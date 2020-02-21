#ifndef MOVIEMANAGER_H_
#define MOVIEMANAGER_H_

#include "MovieManagerUI.h"
#include <iostream>
#include <string>
using namespace std;

class MovieManager{
public:
    MovieManager();
    void run();
    void addMovie(Movies m);
    void discontinueMovie(string movieCode);
    void rentMovie(string movieCode, Renter r);
    void returnRental(int renterID, string movieCode);
    void printInventory();

private:
    Movies movieList[20];
    int movieNum;   
};

































#endif
