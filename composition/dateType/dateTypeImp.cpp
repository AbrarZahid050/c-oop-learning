#include <iostream>
#include "dataType.h"

using namespace std;

// Constructor:
dateType::dateType(int month, int day, int year) {
    dMonth = month;
    dDay = day;
    dYear = year;
    cout << "-> [dateType] setDate()" << endl;
}

void dateType::printDate() const {
    cout << "-> [dateType] printDate() " << dMonth << "/" << dDay << "/" << dYear << endl;
}

int dateType::getDay() const {
    cout << "-> [dateType] getDay() " << dDay << endl;
}

void dateType::setDate(int month, int day, int year) {
    dMonth = month;
    dDay = day;
    dYear = year;
    cout << "-> [dateType] setDate()" << endl;
}