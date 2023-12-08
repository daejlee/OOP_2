//
// Created by 이대진 on 11/16/23.
//
#include <stdexcept>
#include "Frame.h"

using namespace std;

Frame::Frame(double w, double l, double i_w, double i_l) : Rectangle(w, l) {
    setInnerWidth(i_w);
    setInnerLength(i_l);
}

void    Frame::setInnerWidth(double w) {
    if (w < 0 || w >= Rectangle::getWidth())
        throw invalid_argument("invalid width value!");
    _innerWidth = w;
}

void    Frame::setInnerLength(double l) {
    if (l < 0 || l >= Rectangle::getLength())
        throw invalid_argument("invalid width value!");
    _innerLength = l;
}

double Frame::getInnerWidth() const { return _innerWidth; }
double Frame::getInnerLength() const { return _innerLength; }

double Frame::area() const {
    return (Rectangle::getLength() * Rectangle::getWidth()) - _innerWidth * _innerLength;
}