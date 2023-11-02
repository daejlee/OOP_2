#include <iostream>
using namespace std;

unsigned long power(unsigned long base, unsigned long exp){
    if (exp) {
        base *= power(base, exp - 1);
        return base;
    }
    return 1;
}

int main() {
    unsigned long   base = 0;
    unsigned long   exp = 0;
    unsigned long   result = 0;
    cout << "Enter a base and an exponent: ";
    cin >> base >> exp;
    result = power(base, exp);
    cout << base << " raised to the " << exp << " is " << result;
    return 0;
}