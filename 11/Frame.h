//
// Created by 이대진 on 11/16/23.
//

#ifndef OOP_2_FRAME_H
#define OOP_2_FRAME_H
# include "Rectangle.h"
class Frame : public Rectangle{
public:
    explicit Frame(double = 1.0, double = 1.0, double = 0.9, double = 0.9);
    void    setInnerWidth(double w);
    void    setInnerLength(double l);
    double  getInnerWidth() const;
    double  getInnerLength() const;

    double  area() const;
private:
    double _innerWidth;
    double _innerLength;
};

#endif //OOP_2_FRAME_H
