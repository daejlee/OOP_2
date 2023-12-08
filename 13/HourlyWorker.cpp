#include <iostream>
#include <sstream>
#include <stdexcept>
#include "HourlyWorker.h"
using namespace std;

HourlyWorker::HourlyWorker(const string& first, const string& last, const string& ssn, double wage, double hours)
   : Employee(first, last, ssn) {
   setWage(wage);
   setHours(hours);
}

void HourlyWorker::setWage(double wage) {
   if (wage < 0.0)
      throw invalid_argument("Wage must be >= 0.0");
   wage_ = wage;
}

double HourlyWorker::getWage() const { return wage_; }

void HourlyWorker::setHours(double hours) {
   if (hours < 0.0 || hours > 168.0)
      throw invalid_argument("hours must be >= 0 and <= 168");
   hours_ = hours;
}

double HourlyWorker::getHours() const { return hours_; }

double HourlyWorker::earnings() const {
    const double hours = getHours();
    if (hours > 40)
        return getWage() * ((getHours() - 40) * 1.5 + 40);
    return getWage() * getHours();
}

string HourlyWorker::toString() const {
   ostringstream output;
   output << "hourly employee: " << Employee::toString() << "\n"
      << "Wage: " << getWage() << "; hours: " << getHours();
   return output.str();
}