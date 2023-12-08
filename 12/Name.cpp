#include <string>
#include <sstream>
#include <stdexcept>
#include "Name.h"

using namespace std;

Name::Name(string firstName, string lastName) {
	setFirstName(firstName);
	setLastName(lastName);
}

void Name::setFirstName(string fn) {
	if (fn.length() < 2) {
		throw invalid_argument("length of the firstName must be longer than 1");
	}
	firstName = fn;
}

void Name::setLastName(string ln) {
	if (ln.length() < 2) {
		throw invalid_argument("length of the lastName must be longer than 1");
	}
	lastName = ln;
}

string Name::getFirstName() const { return firstName; }
string Name::getLastName() const { return lastName; }

string Name::getFullName() const {
	ostringstream fullname;
	fullname << firstName << " " << lastName;
	return fullname.str();
}