//
// Created by 이대진 on 11/16/23.
//
#include <stdexcept>
#include "Box.h"

using namespace std;

Box::Box(double w, double l, double h) : Rectangle(w, l) {
    setWidth(w);
    setLength(l);
    setHeight(h);
}

void    Box::setWidth(double w) {
    if (w < 0)
        throw invalid_argument("invalid width value!");
    _width = w;
}

void    Box::setLength(double l) {
    if (l < 0)
        throw invalid_argument("invalid Length value!");
    _length = l;
}

void    Box::setHeight(double h) {
    if (h <= 0 || h > 20)
        throw invalid_argument("height must be > 0 and < 20.0");
    _height = h;
}

double Box::getWidth() const { return _width; }
double Box::getLength() const { return _length; }
double Box::getHeight() const { return _height; }
double Box::volume() const { return (_length * _height * _width); }
double Box::area() const { return 2 * (_length * _height + _height * _width + _length * _width); }
double Box::perimeter() const { return 4 * (_length + _width + _height); }