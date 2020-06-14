//
// Created by George on 09.06.2020.
//
#include "Employee.h"

#ifndef OOP_CHEF_H
#define OOP_CHEF_H

class Chef: public Employee{

    char chefSpeciality;

public:

    Chef(string name, unsigned int emplId, char chefSpeciality);
    ~Chef(){}

    string getName();
    unsigned int getEmpId();
    char getEmpClass();
    float getSalary();
    char getChefSpeciality();
    void setName(string);
    void setEmpId(unsigned int);
    void setEmpClass(char);
    void setSalary(float);
    void setChefSpeciality(char);

    void display(ostream &) const;
    void calcSalary(float);

};
Chef::Chef(string name, unsigned int emplId, char chefSpeciality)
     :Employee(name, emplId) {
    this->chefSpeciality = chefSpeciality;
    this->emplClass      = 'C';
    this->salary         = 3000;
}
string Chef::getName() { return this->name;}
float Chef::getSalary() { return this->salary;}
char Chef::getEmpClass() { return this->emplClass;}
unsigned int Chef::getEmpId() { return this->emplId;}
char Chef::getChefSpeciality() { return this->chefSpeciality;}

void Chef::setName(string name) { this->name = name;}
void Chef::setEmpId(unsigned int empId) { this->emplId = empId;}
void Chef::setEmpClass(char emplClass) { this->emplClass = emplClass;}
void Chef::setSalary(float salary) { this->salary = salary;}
void Chef::setChefSpeciality(char chefSpeciality) { this->chefSpeciality = chefSpeciality;}

void Chef::calcSalary(float bonus) {
    if(bonus >= 0)
    {
        bonus = (bonus/100) * 20;
        this->salary += bonus;
    }
}

ostream & operator <<(ostream &out, const Chef &chef)  {
    chef.display(out);

    return out;
}
void Chef::display(ostream &out) const {

    out << "Class: Chef\n"
        << "Chef name: " << this->name << "\t"
        << "Chef ID: " << this->emplId << "\n"
       <<"Raw Salary: "<<this->salary<<"\t";

    if(this->chefSpeciality == 'Q')
        out<<"Chef speciality: Georgian Cuisine\n";
    else if(this->chefSpeciality == 'B')
        out<<"Chef speciality: British Cuisine\n";
    else if(this->chefSpeciality == 'S')
        out<<"Chef speciality: Spanish Cuisine\n";
    else if(this->chefSpeciality == 'T')
        out<<"Chef speciality: Thai Cuisine\n";
    else if(this->chefSpeciality == 'C')
        out<<"Chef speciality: Chinese Cuisine\n";
    else if(this->chefSpeciality == 'J')
        out<<"Chef speciality: Japanese Cuisine\n";
    else if(this->chefSpeciality == 'I')
        out<<"Chef speciality: Italian Cuisine\n";
    else if(this->chefSpeciality == 'K')
        out<<"Chef speciality: Korean Cuisine\n";
    else if(this->chefSpeciality == 'G')
        out<<"Chef speciality: Greek Cuisine\n";
    else if(this->chefSpeciality == 'E')
        out<<"Chef speciality: Egypt Cuisine\n";
    else
        out<<"Chef speciality: Not yet defined in program !\n";


    out<<"------------------------------------------------\n";

}

#endif //OOP_CHEF_H
