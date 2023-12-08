#include <iostream>
#include <stdexcept>
#include "Box.h"

using namespace std;

int main() {
	Box b1{ 3.0, 4.0, 5.0 };

	cout << "b1 length: " << b1.getLength() << ", b1 width: " << b1.getWidth() << ", b1 height: " << b1.getHeight()
		<< "\nb1 perimeter: " << b1.perimeter() << ", b1 area: " << b1.area() << ", b1 volume: " << b1.volume() << endl;
		
	b1.setHeight(7.0);

	cout << "\nb1 length: " << b1.getLength() << ", b1 width: " << b1.getWidth() << ", b1 height: " << b1.getHeight()
		<< "\nb1 perimeter: " << b1.perimeter() << ", b1 area: " << b1.area() << ", b1 volume: " << b1.volume() << endl;

	try {
		b1.setHeight(21.0);
	}
	catch (invalid_argument& e) {
		cout << "\nException: " << e.what() << endl;
	}
}