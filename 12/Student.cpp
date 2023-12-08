#include <iostream>
#include <stdexcept>
#include "Name.h"
#include "Student.h"

using namespace std;

unsigned int Student::count{ 0 };

Student::Student(Name& name, string regNum, string email) {
	setName(name).setRegistrationNumber(regNum).setEmail(email);
	count++;
}

Student::~Student() {
	count--;
}

Student& Student::setName(Name& name) {
	studentName = name;
	return *this;
}

Student& Student::setRegistrationNumber(string regNum) {
	if (regNum.length() != 8) {
		throw invalid_argument("Registration number shoud have length of 8!");
	}

	registrationNumber = regNum;
	return *this;
}

Student& Student::setEmail(string email) {
	this->email = email;
	return *this;
}

Name Student::getName() const {	return studentName; }
string Student::getRegistrationNumber() const { return registrationNumber; }
string Student::getEmail() const { return email; }

unsigned int Student::getCount() { return count; }

string Student::toString() const {
    string ret;
    ret = "Student Name: " + studentName.getFullName() + "\n" +
            "RegNum: " + registrationNumber + "\n" + "Email: " + email + "\n";
    return ret;
}