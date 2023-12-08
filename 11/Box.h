//
// Created by 이대진 on 11/16/23.
//

#ifndef OOP_2_BOX_H
#define OOP_2_BOX_H
# include "Rectangle.h"

class Box : public Rectangle{
public:
    explicit Box(double = 1.0, double = 1.0, double = 1.0);
    void    setWidth(double w);
    void    setLength(double l);
    void    setHeight(double h);
    double  getWidth() const;
    double  getLength() const;
    double  getHeight() const;

    double  area() const;
    double  perimeter() const;
    double  volume() const;
private:
    double _width;
    double _length;
    double _height;
};

#endif //OOP_2_BOX_H

/*
*  Rectangle 클래스의 derived class
▪ double 형의 height라는 데이터 멤버를 추가로 보유
▪ 추가된 데이터 멤버에 대한 set/get 함수 구현
▪ 유효한 height의 범위는 0 초과 20 이하로 함.
▪ height의 default argument는 1.0.
▪ perimeter 멤버 함수를 오버라이딩 하여 3차원 박스에 대해 알맞은 둘레가 반환되도록 구현
▪ area 멤버 함수를 오버라이딩 하여 3차원 박스에 대해 알맞은 총 면적이 반환되도록 구현
▪ volume 멤버 함수를 추가하여 3차원 박스의 부피를 반환하도록 구현

 */