//
// Created by 이대진 on 11/23/23.
//

#ifndef OOP_2_ALUMNI_H
#define OOP_2_ALUMNI_H
#include "Student.h"
#include <iostream>

class Alumni : public Student {
public:
    explicit Alumni(Name, std::string, std::string, std::string);
    void    setDegreeNumber(std::string);
    std::string getDegreeNumber() const;
    virtual std::string toString() const override;
private:
    std::string _degreeNumber;
};

#endif //OOP_2_ALUMNI_H
