//
// Created by George on 09.06.2020.
//
#include "Employee.h"

#ifndef OOP_OWNER_H
#define OOP_OWNER_H

class Owner: public Employee{

public:

    Owner(string name,unsigned int emplId);
    ~Owner(){}

    string getName();
    unsigned int getEmpId();
    char getEmpClass();
    float getSalary();

    void setName(string);
    void setEmpId(unsigned int);
    void setEmpClass(char);
    void setSalary(float);

    void display(ostream &out) const;
    void calcSalary(float );


};
Owner::Owner(string name,unsigned int emplId)
      :Employee(name, emplId){
    this->emplClass = 'O';
    this->salary    = 5000;
}
string Owner::getName() { return this->name;}
float Owner::getSalary() { return this->salary;}
char Owner::getEmpClass() { return this->emplClass;}
unsigned int Owner::getEmpId() { return this->emplId;}

void Owner::setName(string name) { this->name = name;}
void Owner::setEmpId(unsigned int empId) { this->emplId = empId;}
void Owner::setEmpClass(char emplClass) { this->emplClass = emplClass;}
void Owner::setSalary(float salary) { this->salary = salary;}

void Owner::calcSalary(float bonus) {

    if(bonus < 0)
    {
        this->salary += bonus;
    }
    else{
        bonus = (bonus/100)*60;
        this->salary += bonus;
    }
}

ostream & operator <<(ostream &out, const Owner &owner) {
    owner.display(out);

    return out;
}

void Owner::display(ostream &out) const {

    out << "Class: Owner\n"
        << "Owner name: " << this->name << "\t\t"
        << "Owner ID: " << this->emplId << "\n"
       <<"Raw Salary: "<<this->salary<<"\n";

    out<<"------------------------------------------------\n";
}



#endif //OOP_OWNER_H
