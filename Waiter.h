//
// Created by George on 09.06.2020.
//
#include "Employee.h"

#ifndef OOP_WAITER_H
#define OOP_WAITER_H

class Waiter: public Employee {

    unsigned int tips;
    unsigned int experience; // experience in years

public:

    Waiter(string name,unsigned int emplId, unsigned int experience, unsigned int tips = 0);
    ~Waiter(){}

    string getName();
    unsigned int getEmpId();
    char getEmpClass();
    float getSalary();
    unsigned int getTips();
    unsigned int getExperience();
    void setName(string);
    void setEmpId(unsigned int);
    void setEmpClass(char);
    void setSalary(float);
    void setTips(unsigned int);
    void setExperience(unsigned int);

    void display(ostream &out) const;
    void calcSalary(float);

};
Waiter::Waiter(string name,unsigned int emplId, unsigned int experience, unsigned int tips)
       : Employee(name, emplId)
{
    this->tips          = tips;
    this->emplClass     = 'W';
    this->salary        = 1000;

    if(experience > 0 && experience <= 70)
        this->experience = experience;
    else
        cerr<<"Please pass the experience between 0 and 70 !\n";
}
string Waiter::getName() { return this->name;}
float Waiter::getSalary() { return this->salary;}
char Waiter::getEmpClass() { return this->emplClass;}
unsigned int Waiter::getEmpId() { return this->emplId;}
unsigned int Waiter::getTips() {return this->tips;}
unsigned int Waiter::getExperience() {return this->experience;}

void Waiter::setName(string name) { this->name = name;}
void Waiter::setEmpId(unsigned int empId) { this->emplId = empId;}
void Waiter::setEmpClass(char emplClass) { this->emplClass = emplClass;}
void Waiter::setSalary(float salary) { this->salary = salary;}
void Waiter::setTips(unsigned int tips) { this->tips = tips;}
void Waiter::setExperience(unsigned int experience) { this->experience = experience;}

void Waiter::calcSalary(float bonus) {
    if(bonus >= 0)
        this->salary += bonus;
}

ostream & operator <<(ostream &out, const Waiter &waiter)  {
    waiter.display(out);

    return out;
}

void Waiter::display(ostream &out) const {

    out << "Class: Waiter\n"
        << "Waiter name: " << this->name << "\t"
        << "Waiter ID: " << this->emplId << "\n"
       <<"Raw Salary: "<<this->salary<<"\t"
       <<"Waiter Experience: "<<this->experience<<"\n"
       <<"Tips: "<<this->tips<<"\n";

    out<<"------------------------------------------------\n";

}

#endif //OOP_WAITER_H