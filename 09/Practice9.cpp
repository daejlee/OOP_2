#include <iostream> 
#include <iomanip> 
#include <stdexcept>
#include "Rectangle.h" // include definition of class Rectangle
using namespace std;

int main() {
    Rectangle a{ 8.0, 6.0 };
    Rectangle b{ 3.7, 4.5 };

    cout << fixed;
    cout << setprecision(1);
    cout << boolalpha;

    // output Rectangle a
    cout << "a: length = " << a.getLength() << "; width = "
        << a.getWidth() << "; perimeter = " << a.perimeter()
        << "; area = " << a.area() << '\n';

    // output Rectangle b
    cout << "b: length = " << b.getLength() << "; width = "
        << b.getWidth() << "; perimeter = " << b.perimeter()
        << "; area = " << b.area() << '\n';

    // == operator
    cout << "a == b? : " << (a == b) << endl;

    // > operator
    cout << "a > b? : " << (a > b) << endl;
    cout << "b > a? : " << (b > a) << endl;

    // - operator
    Rectangle c;
    c = a - b;
    cout << "c = a - b" << endl;
    cout << "c: length = " << c.getLength() << "; width = "
        << c.getWidth() << endl;

    // -= operator
    a -= b;
    cout << "a -= b" << endl;
    cout << "a: length = " << a.getLength() << "; width = "
        << a.getWidth() << endl;
    
}