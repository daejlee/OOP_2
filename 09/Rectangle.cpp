#include "Rectangle.h"

bool    Rectangle::operator==(const Rectangle &rec) const {
    if (_width == rec.getWidth() && _length == rec.getLength()) return true;
    else return false;
}

bool    Rectangle::operator>(const Rectangle &rec) const {
    if (area() > rec.area()) return true;
    else return false;
}

Rectangle   Rectangle::operator-(const Rectangle &rec) const {
    Rectangle   temp;
    temp.setLength(_length - rec.getLength());
    temp.setWidth(_width - rec.getWidth());
    return temp;
}

void    Rectangle::operator-=(const Rectangle &rec) {
    setLength(_length - rec.getLength());
    setWidth(_width - rec.getWidth());
}

Rectangle::Rectangle(double a, double b) : _length(1.0), _width(1.0){
    _length = b;
    _width = a;
}

void        Rectangle::setWidth(double w){ _width = w; }

void        Rectangle::setLength(double l) { _length = l; }

double      Rectangle::getWidth() const { return _width; }

double      Rectangle::getLength() const { return _length; }

double      Rectangle::perimeter() const { return (_width * 2 + _length * 2); }

double      Rectangle::area() const { return _width * _length; }

bool        Rectangle::operator!=(const Rectangle& rec) const{
    if (_width != rec.getWidth() || _length != rec.getLength()) return true;
    else return false;
}

bool        Rectangle::operator<(const Rectangle& rec) const{
    if (area() < rec.area()) return true;
    else return false;
}
Rectangle   Rectangle::operator+(const Rectangle& rec) const{
    Rectangle   temp;
    temp.setLength(_length + rec.getLength());
    temp.setWidth(_width + rec.getWidth());
    return temp;
}

void        Rectangle::operator+=(const Rectangle& rec){
    setLength(_length + rec.getLength());
    setWidth(_width + rec.getWidth());
}

std::ostream& operator<<(std::ostream& lhs, const Rectangle& rec){
    std::cout << "Length: " << rec.getLength() << ", Width: " << rec.getWidth() << "\n";
    return lhs;
}