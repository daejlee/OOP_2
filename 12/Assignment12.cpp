#include <iostream>
#include "Name.h"
#include "Student.h"
#include "Alumni.h"

using namespace std;

int main() {
	Name n1{ "Doguk", "Kim" };
	Name n2{ "No", "Name" };
		
	Student s1{ n1, "20210094", "dgkim@inha.ac.kr" };

	cout << "Control with variable name" << endl;
	cout << s1.toString() << "\n" << endl;

	Alumni a1{ n2, "20171234", "noname@inha.ac.kr", "2021234" };

	cout << a1.toString() << "\n" << endl;

	Student* tempPtr = &s1;

	cout << "Control with pointer" << endl;
	cout << tempPtr->toString() << "\n" << endl;

	tempPtr = &a1;
	cout << tempPtr->toString() << "\n" << endl;
}