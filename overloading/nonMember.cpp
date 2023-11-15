#include <iostream>


using namespace std;

class rectangleType {
    friend ostream& operator<<(ostream&, const rectangleType&);
    friend istream& operator>>(istream&, rectangleType&);
public:
    void setDimensions(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;
    rectangleType();
    rectangleType(double l, double w);

    // overloading the binary operator as non-member functions:
    friend rectangleType operator+(const rectangleType&, const rectangleType&);

private:
    double width;
    double length;

};

void rectangleType::setDimensions(double l, double w) {
    if (l >= 0) length = l;
    else
        length = 0;
    if (w >= 0) width = w;
    else
        width = 0;
}

double rectangleType::getLength() const {
    return length;
}

double rectangleType::getWidth() const {
    return width;
}

double rectangleType::area() const {
    return length * width;
}

double rectangleType::perimeter() const {
    return 2 * (length + width);
}

void rectangleType::print() const {
    cout << "-> [print]\n";
    cout << "--> length: " << length << endl;
    cout << "--> width: " << width << endl;
}

rectangleType::rectangleType(double l, double w) {
    setDimensions(l, w);
}

rectangleType::rectangleType() {
    length = 0;
    width = 0;
}

// Definition of the function operator+:
// -> myRectangle + yourRectangle; --> "operator+(myRectangle + yourRectangle)".
// -> formal params are reference pointer to the yourRectangle & myRectangle, its const
// -> so its not going to be subject to any change from under your foot.
rectangleType operator+(const rectangleType& firstRect, const rectangleType& secondRect) {
    rectangleType tempRect;
    tempRect.length = firstRect.length + secondRect.length;
    tempRect.width = firstRect.width + secondRect.width;
    return tempRect;
}


ostream& operator<< (ostream& osObject, const rectangleType& rectangle) {
    osObject << "Length: " << rectangle.length << endl;
    osObject << "Width: " << rectangle.width << endl;
    return osObject;
}

istream& operator>> (istream& isObject, rectangleType& rectangle) {
    isObject >> rectangle.length >> rectangle.width;
    return isObject;
}

int main() {
    rectangleType rect1(10, 20), rect2(10, 20), rect3;
    rect1.print();

    cout << "-------------------------------\n";
    rect3 = rect1 + rect2;
    rect3.print();

    cout << "-------------------------------\n";
    cout << rect3;

    return 0;
}