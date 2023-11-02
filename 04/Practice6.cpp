#include <array>
#include "GradeBook.h"
using namespace std;

int main() {    
    array<array<int, GradeBook::tests>, GradeBook::students> grades{
        {{87, 96, 70},
        {68, 87, 90},
        {94, 100, 90},
        {100, 81, 82},
        {83, 65, 85}}
        };
    string courseName{ "CS101 Introduction to C++ Programming" };
    cout << "Please enter the course name: ";
    cin >> courseName;
    for (size_t i = 0; i < 5; i++) {
        cout << "Please enter grades of the student " << i + 1 << ": ";
        cin >> grades[i][0] >> grades[i][1] >> grades[i][2];
    }
    GradeBook myGradeBook(courseName, grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
}