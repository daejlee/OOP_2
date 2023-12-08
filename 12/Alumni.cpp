//
// Created by 이대진 on 11/23/23.
//
#include "Alumni.h"
using namespace std;

Alumni::Alumni(Name n, std::string regNum, std::string email, std::string degNum) : Student(n, regNum, email) { _degreeNumber = degNum; }

void    Alumni::setDegreeNumber(string dn) { _degreeNumber = dn; }

string Alumni::getDegreeNumber() const { return _degreeNumber; }

string Alumni::toString() const {
    string ret;
    ret = "Alumni Name: " + studentName.getFullName() + "\n" +
          "RegNum: " + registrationNumber + "\n" + "Email: " + email + "\n"
          + "Degree num: " + _degreeNumber + "\n";
    return ret;
}