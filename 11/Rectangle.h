#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
	friend std::ostream& operator<<(std::ostream&, const Rectangle&);
public:
	explicit Rectangle(double = 1.0, double = 1.0); // default constructor
	void setWidth(double w); // set width
	void setLength(double l); // set length
	double getWidth() const; // get width
	double getLength() const; // get length  
	double perimeter() const; // perimeter
	double area() const; // area

	bool operator==(const Rectangle&) const;
	bool operator>(const Rectangle&) const;
	Rectangle operator-(const Rectangle&) const;
	void operator-=(const Rectangle&);

	bool operator!=(const Rectangle&) const;
	bool operator<(const Rectangle&) const;
	Rectangle operator+(const Rectangle&) const;
	void operator+=(const Rectangle&);

private:
	double length; // 1.0 < length < 20.0
	double width; // 1.0 < width < 20.0
};

#endif