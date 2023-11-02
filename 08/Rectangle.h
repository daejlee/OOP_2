
#ifndef OOP_2_RECTANGLE_H
#define OOP_2_RECTANGLE_H
#include <stdexcept>

class Rectangle{
private:
    double  len_; //from 0.0 to 20.0
    double  wid_; //from 0.0 to 20.0
public:
    Rectangle();
    Rectangle(double wid, double len); //default arg = 1.0, exception need to see which val is exceeding
    double  perimeter() const;
    double  area() const;
    double  getLength() const;
    double  getWidth() const;
    void    setLength(double len);
    void    setWidth(double wid); //all getter setter if invalid exception
};

#endif //OOP_2_RECTANGLE_H
