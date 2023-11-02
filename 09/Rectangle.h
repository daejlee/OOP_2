#ifndef OOP_2_RECTANGLE_H
#define OOP_2_RECTANGLE_H

#include <iostream>

class Rectangle {
public:
    explicit    Rectangle(double = 1.0, double = 1.0);
    void        setWidth(double w);
    void        setLength(double l);
    double      getWidth() const;
    double      getLength() const;
    double      perimeter() const;
    double      area() const;

    bool        operator==(const Rectangle&) const;
    bool        operator>(const Rectangle&) const;
    Rectangle   operator-(const Rectangle&) const;
    void        operator-=(const Rectangle&);
    bool        operator!=(const Rectangle&) const;
    bool        operator<(const Rectangle&) const;
    Rectangle   operator+(const Rectangle&) const;
    void        operator+=(const Rectangle&);

private:
    double _length;
    double _width;
};

std::ostream& operator<<(std::ostream& lhs, const Rectangle& rec);

#endif //OOP_2_RECTANGLE_H
