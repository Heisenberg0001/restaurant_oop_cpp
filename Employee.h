//
// Created by George on 04.06.2020.
//
#include <string>
#include <iostream>

#ifndef OOP_EMPLOYEE_H
#define OOP_EMPLOYEE_H

using namespace std;

class Employee {
protected:
    string        name; // Employee Name
    unsigned int  emplId; // Employee ID
    char          emplClass; // Employee Class that can be 'O' - Owner, 'C' - Chef, 'W' - Waiter
    float         salary; // Employee salary

public:

   Employee( string name, unsigned int  emplID);
   virtual ~Employee(){}

    virtual string getName() = 0;
    virtual unsigned int getEmpId() = 0;
    virtual char getEmpClass() = 0;
    virtual float getSalary() = 0;

    virtual void setName(string) = 0;
    virtual void setEmpId(unsigned int) = 0;
    virtual void setEmpClass(char) = 0;
    virtual void setSalary(float) = 0;

   virtual void display(ostream &) const = 0;
   virtual void calcSalary(float) = 0;
};

Employee::Employee(string name, unsigned int emplID ) {
    this->name      = name;
    this->emplId    = emplID;
}

#endif //OOP_EMPLOYEE_H
