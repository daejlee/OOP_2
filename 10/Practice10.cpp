#include <iostream>
#include <stdexcept>
#include "DoubleSubscriptedArray.h"
using namespace std;

int main() {
   DoubleSubscriptedArray integers1{2, 4}; // seven-element array
   DoubleSubscriptedArray integers2; // 3-by-3 array by default

   // print integers1 size and contents
   cout << "Size of DoubleSubscriptedArray integers1 is "
       << integers1.getRowSize() << " X " << integers1.getColumnSize() << endl;

   // print integers2 size and contents
   cout << "\nSize of DoubleSubscriptedArray integers2 is "
       << integers2.getRowSize() << " X " << integers2.getColumnSize() << endl;

   // input and print integers1 and integers2
   cout << "\nEnter 17 integers:" << endl;
   cin >> integers1 >> integers2;

   cout << "\nAfter input, the DoubleSubscriptedArrays contain:\n"
      << "integers1(0,0):\n" << integers1(0,0)
      << "\nintegers2(0,0):\n" << integers2(0,0) << endl;

   // evaluting overloaded equality (==) operator
   cout << "Evaluating: integers1 == integers2" << endl;

   if (!(integers1 == integers2)) {
      cout << "integers1 and integers2 are not equal" << endl;
   }

   // use overloaded subscript operator to create rvalue
   cout << "\nintegers1(1, 2) is " << integers1(1, 2);

}