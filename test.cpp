#include <iostream>

using namespace std;

class rectangleType {
public:
    void setDimension(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;
    rectangleType();
    rectangleType(double l, double w);
private:
    double length;
    double width;
};

class boxType : public rectangleType {
public:
    void setDimension(double l, double w, double h);
    double getHeight() const;
    double area() const;
    double volume() const;
    void print() const;
    boxType();
    boxType(double l, double w, double h);
private:
    double height;
};

int main() {
    boxType myBox;
    return 0;
}

boxType::boxType() {
    cout << "~> constructor for boxType class.";
    height = 0;
}

boxType::boxType(double l, double w, double h) : rectangleType(l, w) {
    cout << "~> constructor2 for boxType class.";
    height = 0;
}

void boxType::print() const {
    rectangleType::print();
    cout << "~> print() boxType: " << height << endl;
};

void boxType::setDimension(double l, double w, double h) {
    rectangleType::setDimension(l, w);
    height = h;
}

double boxType::getHeight() const {
    return height;
}

double boxType::area() const {
    // cannot directly access the private member variables of the base     class. Must use the public member functions of the base class.
    return 2 * (getLength() * getWidth() + getLength() * height + getWidth() * height);
}

double boxType::volume() const {
    // boxType class overrides the area member function of the base class. so to access the base class member func needs to called the base class with scope resolution.
    return rectangleType::area() * height;
}

void rectangleType::print() const {
    cout << "-> print() rectangleType: " << length << " " << width << endl;
}

rectangleType::rectangleType() {
    cout << "-> Constructor of rectangleType class." << endl;
    length = 0;
    width = 0;
}

rectangleType::rectangleType(double l, double w) {
    cout << "-> Constructor#2 of rectangleType class." << endl;
    length = l;
    width = w;
}

void rectangleType::setDimension(double l, double w) {
    cout << "-> setDimension method of rectangleType class." << endl;
    length = l;
    width = w;
}

double rectangleType::getLength() const {
    cout << "-> getLength method of rectangleType class." << endl;
    return length;
}

double rectangleType::getWidth() const {
    cout << "-> getWidth method of rectangleType class." << endl;
    return width;
}

double rectangleType::area() const {
    cout << "-> area method of rectangleType class." << endl;
    return length * width;
}

double rectangleType::perimeter() const {
    cout << "-> perimeter method of rectangleType class." << endl;
    return 2 * (length + width);
}

