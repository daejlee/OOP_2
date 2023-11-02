#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() : len_(1.0), wid_(1.0) {}

Rectangle::Rectangle(double wid, double len) : len_(1.0), wid_(1.0) {
    if (len < 0 || len > 20)
        throw invalid_argument("Length is invalid. Value limited 0.0 to 20.0");
    else if (wid < 0 || wid > 20)
        throw invalid_argument("Width is invalid. Value limited 0.0 to 20.0");
    len_ = len;
    wid_ = wid;
} //default arg = 1.0, exception need to see which val is exceeding

double  Rectangle::perimeter() const { return (len_ + wid_) * 2; }

double  Rectangle::area() const { return len_ * wid_; }

double  Rectangle::getLength() const { return len_; }

double  Rectangle::getWidth() const { return wid_; }

void    Rectangle::setLength(double len) {
    if (len < 0.0 || len > 20.0)
        throw invalid_argument("Length is invalid. Value limited 0.0 to 20.0");
    len_ = len;
}

void    Rectangle::setWidth(double wid) {
    if (wid < 0.0 || wid > 20.0)
        throw invalid_argument("Width is invalid. Value limited 0.0 to 20.0");
    wid_ = wid;
}