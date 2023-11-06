#include <iostream>
#include "personType.h"

using namespace std;

// Constructor:
personType::personType(string first, string last) {
    firstName = first;
    lastName = last;
}

void personType::setName(string first, string last) {
    firstName = first;
    lastName = last;
    cout << "-> [personType] setName() done!" << endl;
}

void personType::print() const {
    cout << "-> [personType] print(): " << firstName << " " << lastName << endl;
}

string personType::getFirstName() const {
    cout << "-> [personType] getFirstName(): " << firstName << endl;
}

string personType::getLastName() const {
    cout << "-> [personType] getFirstName(): " << firstName << endl;
}

