#include <stdexcept>
#include <iostream>
#include "Rectangle.h" // include definition of class Rectangle
using namespace std;

Rectangle::Rectangle(double w, double l) {    
    if ((w <= 0 || w > 20.0) && (l <= 0 || l > 20.0)) {
        throw invalid_argument("width and length must be > 0 and < 20.0");        
    }

    setWidth(w); // invokes function setWidth
    setLength(l); // invokes function setLength
}

void Rectangle::setWidth(double w) {
    if (w <= 0 || w > 20.0) {
        throw invalid_argument("width must be > 0 and < 20.0");
    }

    width = w;
}

void Rectangle::setLength(double l)
{
    if (l <= 0 || l > 20.0) {
        throw invalid_argument("length must be > 0 and < 20.0");
    }

    length = l;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::perimeter() const {
    return 2 * (width + length); // returns perimeter	
}

double Rectangle::area() const {
    return width * length; // returns area
}

bool Rectangle::operator==(const Rectangle& rec) const {
    if ((this->width == rec.getWidth()) && (this->length == rec.getLength())) {
        return true;
    }
    else {
        return false;
    }
}

bool Rectangle::operator>(const Rectangle& rec) const {
    if (this->area() > rec.area()) {
        return true;
    }
    else {
        return false;
    }
}

Rectangle Rectangle::operator-(const Rectangle& rec) const {
    Rectangle temp;
    temp.setLength(this->length - rec.getLength());
    temp.setWidth(this->width - rec.getWidth());
    return temp;
}

void Rectangle::operator-=(const Rectangle& rec){
    this->setLength(this->length - rec.getLength());
    this->setWidth(this->width - rec.getWidth());
}

bool Rectangle::operator!=(const Rectangle& rec) const {
    if ((this->width != rec.getWidth()) || (this->length != rec.getLength())) {
        return true;
    }
    else {
        return false;
    }
}

bool Rectangle::operator<(const Rectangle& rec) const {
    if (this->area() < rec.area()) {
        return true;
    }
    else {
        return false;
    }
}

Rectangle Rectangle::operator+(const Rectangle& rec) const {
    Rectangle temp;
    temp.setLength(this->length + rec.getLength());
    temp.setWidth(this->width + rec.getWidth());
    return temp;
}

void Rectangle::operator+=(const Rectangle& rec) {
    this->setLength(this->length + rec.getLength());
    this->setWidth(this->width + rec.getWidth());
}

ostream& operator<<(ostream& output, const Rectangle& rec) {
    output << "Length: " << rec.getLength() << ", Width: " << rec.getWidth() << endl;
    return output;
}