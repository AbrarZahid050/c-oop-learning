#include <iostream>


using namespace std;

class rectangleType {
public:
    void setDimensions(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;
    rectangleType();
    rectangleType(double l, double w);

    // Overload the operator +
    rectangleType operator+(const rectangleType&) const;
    // Overload the operator *
    rectangleType operator*(const rectangleType&) const;
    // Overload the operator ==
    bool operator==(const rectangleType&) const;
    bool operator!=(const rectangleType&) const;



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
// -> myRectangle + yourRectangle; --> "myRectangle.operator+(yourRectangle)".
// -> formal param rectangle is reference pointer to the yourRectangle, its const
// -> so its not going to be subject to any change from under your foot.
rectangleType rectangleType::operator+(const rectangleType& rectangle) const {
    rectangleType tempRect;
    tempRect.length = length + rectangle.length;
    tempRect.width = width + rectangle.width;
    return tempRect;
}

// Definition of the function operator*:
rectangleType rectangleType::operator*(const rectangleType& rectangle) const {
    rectangleType tempRect;
    tempRect.length = length * rectangle.length;
    tempRect.width = width * rectangle.width;
    return tempRect;
}

// Definition of the function operator== :
bool rectangleType::operator==(const rectangleType& rectangle) const {
    cout << "-> [operator ==] length: " << length << endl;
    cout << "-> [operator ==] rectangle.length: " << rectangle.length << endl;
    return (length == rectangle.length || width == rectangle.width);
}

// Definition of the function operator!= :
bool rectangleType::operator!=(const rectangleType& rectangle) const {
    // the instance object, which in this case is rect3 is passed to
    // "operator==".
    // when you use an operator in the form of a member function 
    // (like operator== or operator!=) for a class, the left-hand side 
    // object is implicitly passed as the `this` pointer, and the 
    // right-hand side object is passed as the argument.
    return !(operator==(rectangle));
}

int main() {
    rectangleType rect1(10, 20), rect2(10, 20), rect3, rect4;
    rect1.print();

    cout << "-------------------------------\n";
    rect3 = rect1 + rect2;
    rect3.print();

    cout << "-------------------------------\n";
    rect4 = rect1 * rect2;
    rect4.print();

    if (rect3 != rect4) {
        cout << "-> [main] DIFFERENT\n";
    }
    else {
        cout << "-> [main] SAME\n";
    }

    // when you call rect3 != rect4, the rect3 object is 
    // implicitly passed as the left-hand side (*this), 
    // and rect4 is passed as the argument to operator!=.

    return 0;
}