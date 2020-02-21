//Jiayu Zuo #
//Iris Yu  #12404925



#include "MovieManager.h"
#include <string>
using namespace std;

//Default constructor of MovieManager.
MovieManager::MovieManager(){
    this->movieNum = 0;
    for (int i=0; i<20; i++){
        this->movieList[i] = Movies();
    }
};

//Add new movie in the inventory list.
void MovieManager::addMovie(Movies m){
    this->movieNum ++;
    if (this->movieNum > 20){
        this->movieNum = 20;
        throw MovieLimitException();
    }
    else if (m.getMovieName()=="" || m.getMovieCode()==""){
        throw EmptyMovieInfoException();
    }
    else{
        bool found = false;
        int pos = 0;
        while (pos < 20 && !found){
            if (this->movieList[pos].getMovieCode() == m.getMovieCode()){
                found = true;
            }
            else{
                pos++;
            }
        }
        if (found == true){
            throw DuplicateMovieException();
        }
        else{
            this->movieList[this->movieNum - 1] = m;
        }
    }
}

//Delete movies from the inventory list.
void MovieManager::discontinueMovie(string movieCode){
    bool found = false;
    int pos = 0;
    while (pos < 20 && !found){
        if (this->movieList[pos].getMovieCode() == movieCode){
            found = true;
        }
        else{
            pos++;
        }
    }
    if (found == false){
        throw MovieNotFoundException();
    }//need to set default to ""
    else if (this->movieList[0].getMovieCode() == ""){
        throw EmptyMovieInfoException();
    }//Double check the returned value of getRentedCopies
    else if (this->movieList[pos].getRentedCopies()==0){
        throw RentedMovieException();
    }
        
    else{
        Movies temp = this->movieList[this->movieNum - 1];
        this->movieList[pos] = temp;
        this->movieList[this->movieNum - 1] = Movies();
        this->movieNum--;
    }
}

//Add new renter on specific movie's renter list.
void MovieManager::rentMovie(string movieCode, Renter r){
    bool found = false;
    int pos = 0;
    while (pos < 20 && !found){
        if (this->movieList[pos].getMovieCode() == movieCode){
            found = true;
        }else{
            pos++;
        }
    }
    if (found == false){
        throw MovieNotFoundException();
    }else{
        movieList[pos].rentMovie(r);
    }
}

//Delete renters from specific movie's renter list.
void MovieManager::returnRental(int renterID, string movieCode){
        bool found = false;
        int pos = 0;
        while (pos < 20 && !found){
            if (this->movieList[pos].getMovieCode() == movieCode){
                found = true;
            }else{
                pos++;
            }
        }
        if (found == false){
            throw MovieNotFoundException();
        }else{
            movieList[pos].returnRental(renterID);
        }
    }


//Print out all the information related to the movie and renter.
void MovieManager::printInventory(){
//awaiting
    
    
}


//Promote for users to use all the functions in this program.
void MovieManager::run(){
    cout << "Welcome to Movie Rental Kiosk!\n";
    MovieManagerUI sample = MovieManagerUI();
    string command = "BEGIN";
    command = sample.getCommand();
    command = sample.toUpper(command);
    sample.printMenu();
    while (command != "Q"){
        if (command == "Q"){
            break;
        }
        else if (command == "AM"){
            try{
                string theCode, theName;
                theCode = sample.getMovieCode();
                theName = sample.getMovieName();
                Movies obj1 = Movies(theCode, theName);
                addMovie(obj1);
            }
            catch(MovieLimitException& e1){
                cout << "MovieLimitException: The movie list already has the maximum number(20) of movies, you cannot add more movies." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(EmptyMovieInfoException& e2){
                cout << "EmptyMovieInfoException: The movie's code and name cannot be empty." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(DuplicateMovieException& e3){
                cout << "DuplicateMovieException: The movie that you enter has already existed in the list." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
        }
        
        
        else if (command == "DM"){
            try{
                string theCode = sample.getMovieCode();
                discontinueMovie(theCode);
            }
            catch(MovieNotFoundException& e1){
                cout << "MovieNotFoundException: Cannot find the movie that you enter." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(EmptyMovieInfoException& e2){
                cout << "EmptyMovieInfoException: The movie's code and name cannot be empty." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(RentedMovieException& e3){
                cout << "RentedMovieException: There are movie copies out of rental, you cannot delete this movie." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
        }
        
        
        else if (command == "RM"){
            try{
                int theID;
                string theFirst, theLast, theCode;
                theCode = sample.getMovieCode();
                theID = sample.getRenterID();
                theFirst = sample.getRenterFirstName();
                theLast = sample.getRenterLastName();
                Renter obj2 = Renter(theID, theFirst, theLast);
                rentMovie(theCode, obj2);
            }
            catch(MovieNotFoundException& e1){
                cout << "MovieNotFoundException: Cannot find the movie that you enter." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(EmptyRenterNameException& e2){
                cout << "EmptyRenterNameException: The renter's first name and last name cannot be empty." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(InvalidRenterIDException& e3){
                cout << "InvalidRenterIDException: Please enter a valid renter ID (must be a positive numebr)." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(DuplicateRenterException& e4){
                cout << "DuplicateRenterException: The renter ID that you enter has already existed in the list." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(RenterLimitException& e5){
                cout << "RenterLimitException: The renter list already has the maximum number(10) of renters, you cannot rent more movies." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
        }
        
        
        else if (command == "RR"){
            try{
                int theID;
                string theCode;
                theCode = sample.getMovieCode();
                theID = sample.getRenterID();
                returnRental(theID, theCode);
            }
            catch(MovieNotFoundException& e1){
                cout << "MovieNotFoundException: Cannot find the movie that you enter." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(RenterNotFoundException& e2){
                cout << "RenterNotFoundException: Cannot find the renter that you enter." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
            catch(EmptyRenterListException& e3){
                cout << "EmptyRenterListException: The list of renter is empty." << endl;
                sample.printMenu();
                command = sample.getCommand();
                command = sample.toUpper(command);
            }
        }
        
        
        else if (command == "P"){
            printInventory();
        }
    }
}












































