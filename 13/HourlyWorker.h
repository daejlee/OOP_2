//
// Created by 이대진 on 11/30/23.
//

#ifndef OOP_2_HOURLYWORKER_H
#define OOP_2_HOURLYWORKER_H
#include "Employee.h"

class HourlyWorker : public Employee {
public:
    HourlyWorker(const std::string&, const std::string&, const std::string&, double = 0.0, double = 0);

    void setWage(double);
    double getWage() const;

    void setHours(double);
    double getHours() const;

    virtual double earnings() const override;
    virtual std::string toString() const override;
private:
    double wage_; // >= 0
    double hours_; // 0~168
};

#endif //OOP_2_HOURLYWORKER_H
