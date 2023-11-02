#include <iostream> 
#include <iomanip> 
#include <stdexcept>
#include "Rectangle.h" // include definition of class Rectangle
using namespace std;

int main() {
    Rectangle a;
    Rectangle b(4.0, 5.0);

    cout << fixed;
    cout << setprecision(1);

    // output Rectangle a
    cout << "a: length = " << a.getLength() << "; width = "
        << a.getWidth() << "; perimeter = " << a.perimeter()
        << "; area = " << a.area() << '\n';

    // output Rectangle b
    cout << "b: length = " << b.getLength() << "; width = "
        << b.getWidth() << "; perimeter = " << b.perimeter()
        << "; area = " << b.area() << '\n';

    a.setWidth(6.5);
    a.setLength(2.0);
    cout << "a after set: length = " << a.getLength() << "; width = "
        << a.getWidth() << "; perimeter = " << a.perimeter()
        << "; area = " << a.area() << '\n';

    // try to create a Rectanle with invalid arguments
    try {
        Rectangle c(67.0, 888.0 );
    }
    catch (invalid_argument& e) {
        cout << "\nException: " << e.what() << endl;
    }
    try {
        Rectangle c(67.0, 8.0 );
    }
    catch (invalid_argument& e) {
        cout << "\nException: " << e.what() << endl;
    }
    try {
        Rectangle c( 7.0, 88.0 );
    }
    catch (invalid_argument& e) {
        cout << "\nException: " << e.what() << endl;
    }
}