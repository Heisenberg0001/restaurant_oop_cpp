#include "Employee.h"
#include "Owner.h"
#include "Chef.h"
#include "Waiter.h"
#include "DinamicList.h"
#include <algorithm>
#include <fstream>
#include <vector>

int calcIncome(int, int, int, int);

int main() {

    List emplList; // Employee List

    float income; // Income field
    int countOwner = 0, countChef = 0, countWaiter = 0; // Counter fields for Owner , Chef and Waiters
    vector<Waiter> waiterList; //Waiter List


    Owner primaryOwner("Gio",1); // creating Owner
    Chef mainChef("Gordon",2,'Q'); // creating Chef 1
    Chef sousChef("Lee",3,'S');// creating Chef 1
    Waiter waiterOne("John",4,2);// creating Waiter 1
    Waiter waiterTwo("Bane",5,1);// creating Waiter 2
    Waiter waiterThree("Morgan",6,4);// creating Waiter 3
    Waiter waiterFour("Beqa",7,10);// creating Waiter 3

    income = 100000;

    emplList.insert(&primaryOwner, 0);
    emplList.insert(&mainChef, 1);
    emplList.insert(&sousChef, 2);
    emplList.insert(&waiterOne, 3);
    emplList.insert(&waiterTwo, 4);
    emplList.insert(&waiterThree, 5);
    emplList.insert(&waiterThree, 6);

    for(int i = 0; i < emplList.length(); i++){ //counting Owners, Chefs and Waiters in "emplList"
        if (emplList.getMember(i)->getEmpClass() == 'O')
            countOwner++;
        else if (emplList.getMember(i)->getEmpClass() == 'C')
            countChef++;
        else
            countWaiter++;
    }


    cout<<"Owner: "<<countOwner<<"\t Chef: "<<countChef<<"\t Waiter: "<<countWaiter<<endl;


    // calculating the pure income after the salary is given out
    income = calcIncome(income, countOwner, countChef, countWaiter);

    //calculating salary for all Employers for this month, except Waiters
    for(int i=0; i < emplList.length(); i++){
        if(emplList.getMember(i)->getEmpClass() != 'W')
            emplList.getMember(i)->calcSalary(income);
    }

    //displaying emplList
    cout<<emplList;

    // array for to store tips, the size is depending on how much Waiters are in the "emplList"
    float tipsArr[countWaiter];


    tipsArr[0] = 1000.0;
    tipsArr[1] = 500.0;
    tipsArr[2] = 1500.0;
    tipsArr[3] = 200.0;

    sort(tipsArr, tipsArr + countWaiter);

    cout<< "\nTips: ";
    for (int i = 0; i < countWaiter; i ++ )
        cout<<tipsArr[i]<<"\t";

    cout<<"\n\n";

    //pushing Waiters in waiterList vector
    waiterList.push_back(waiterOne);
    waiterList.push_back(waiterFour);
    waiterList.push_back(waiterThree);
    waiterList.push_back(waiterTwo);

    //sorting Waiters with the experience
    sort(waiterList.rbegin(), waiterList.rend(), [](Waiter &a, Waiter &b){return a.getExperience() > b.getExperience();});


    //
    cout<< "Waiters after tips were distributed by experience: \n";
    for(int i = 0; i <  waiterList.size(); i++){
        waiterList[i].setTips(tipsArr[i]);
        waiterList[i].calcSalary(tipsArr[i]);
        cout<<waiterList[i];
    }

    cout<<"\n****************Console input Part!*****************************\n";


    List listOne;
    countOwner = 0;
    countChef = 0;
    countWaiter = 0;

    cout << "Customer input:\n";
    cout << "How much is the total Income in this month?\n";
    cin >> income;

    string        name; // Employee Name
    unsigned int  emplId; // Employee ID
    char          chefSpecification; // Chef speciality
    unsigned int  waiterTips; // tips
    unsigned int  waiterExperience; // experience in years

    cout<< "Input Owners information\n";
    cout<<"Owner Name: \n";
    cin>>name;
    cout<<"Owner Id: \n";
    cin>>emplId;

    Owner cinOwner(name, emplId);

    cout<< "Input Chef information\n";

    cout<<"Chef Name: \n";
    cin>>name;
    cout<<"Chef Id: \n";
    cin>>emplId;
    cout<<"Chef Specialization : \n";
    cin>>chefSpecification;

    Chef chef(name, emplId, chefSpecification);

    cout<< "Input Sous-Chef information\n";

    cout<<"Sous-Chef Name: \n";
    cin>>name;
    cout<<"Sous-Chef Id: \n";
    cin>>emplId;
    cout<<"Sous-Chef Specialization : \n";
    cin>>chefSpecification;

    Chef sousChefSec(name, emplId, chefSpecification);

    cout<< "Input First Waiter information\n";

    cout<<"Waiter Name: \n";
    cin>>name;
    cout<<"Waiter Id: \n";
    cin>>emplId;
    cout<<"Waiter Experience: \n";
    cin>>waiterExperience;
    cout<<"Waiter Tips: \n";
    cin>>waiterTips;

    Waiter waiter_1(name, emplId, waiterExperience, waiterTips);
    waiter_1.calcSalary(waiterTips);


    cout<< "Input Second Waiter information\n";

    cout<<"Waiter Name: \n";
    cin>>name;
    cout<<"Waiter Id: \n";
    cin>>emplId;
    cout<<"Waiter Experience: \n";
    cin>>waiterExperience;
    cout<<"Waiter Tips: \n";
    cin>>waiterTips;

    Waiter waiter_2(name, emplId, waiterExperience, waiterTips);
    waiter_2.calcSalary(waiterTips);


    cout<< "Input Third Waiter information\n";

    cout<<"Waiter Name: \n";
    cin>>name;
    cout<<"Waiter Id: \n";
    cin>>emplId;
    cout<<"Waiter Experience: \n";
    cin>>waiterExperience;
    cout<<"Waiter Tips: \n";
    cin>>waiterTips;

    Waiter waiter_3(name, emplId, waiterExperience, waiterTips);
    waiter_3.calcSalary(waiterTips);

    listOne.insert(&cinOwner,0);
    listOne.insert(&chef,1);
    listOne.insert(&sousChefSec,2);
    listOne.insert(&waiter_1,0);
    listOne.insert(&waiter_2,4);
    listOne.insert(&waiter_3,5);


    for(int i = 0; i < listOne.length(); i++){ //counting Owners, Chefs and Waiters in "emplList"
        if (listOne.getMember(i)->getEmpClass() == 'O')
            countOwner++;
        else if (listOne.getMember(i)->getEmpClass() == 'C')
            countChef++;
        else
            countWaiter++;
    }

    income = calcIncome(income, countOwner, countChef, countWaiter);

    //calculating salary for all Employers for this month, except Waiters
    for(int i=0; i < listOne.length(); i++){
        if(listOne.getMember(i)->getEmpClass() != 'W')
            listOne.getMember(i)->calcSalary(income);
    }

    cout<<listOne;
    cout<<endl;


    cout<<"\nIMPORTING DATA FROM FILE !*****************\n";

    List listTwo;
    countOwner = 0;
    countChef = 0;
    countWaiter = 0;

    ifstream myfile ("C:\\Users\\George\\CLionProjects\\OOP\\EmployeeList");
    string line; // ifstream buffer
    vector<string> vecLine;
    vector<Employee*> vecEmpl;


    if (myfile.is_open())
    {
        myfile >> line;
        income =stoi(line); // casting incoming String to Int

        cout<<"Income: "<<income<<"\n";

        while(myfile >> line)
            vecLine.push_back(line);

        myfile.close();

    }else cout << "Unable to open file";

    cout<< "Creating Owner object ...\n";
    Owner ownerFile(vecLine[0],stoi(vecLine[1]));

    cout<< "Creating Chef object ...\n";
    Chef chefFile(vecLine[2],stoi(vecLine[3]),char(vecLine[4][0]));

    cout<< "Creating Sous-Chef object ...\n";
    Chef sousChefFile(vecLine[5],stoi(vecLine[6]),char( vecLine[7][0]));

    cout<< "Creating Waiter One object ...\n";
    Waiter waiter_One( vecLine[8],stoi( vecLine[9]),stoi( vecLine[10]), stoi( vecLine[11]));
    waiter_One.calcSalary(stoi( vecLine[11]));


    cout<< "Creating Waiter Two object ...\n";
    Waiter waiter_Two(vecLine[12],stoi( vecLine[13]),stoi( vecLine[14]), stoi( vecLine[15]));
    waiter_Two.calcSalary(stoi( vecLine[15]));

    cout<< "Creating Waiter Three object ...\n";
    Waiter waiter_Three(vecLine[16],stoi( vecLine[17]),stoi( vecLine[18]), stoi( vecLine[19]));
    waiter_Two.calcSalary(stoi( vecLine[19]));



    vecEmpl.push_back(&ownerFile);

    listTwo.insert(&ownerFile,0);
    listTwo.insert(&chefFile,1);
    listTwo.insert(&sousChefFile,2);
    listTwo.insert(&waiter_One,3);
    listTwo.insert(&waiter_Two,4);
    listTwo.insert(&waiter_Three,5);


    for(int i = 0; i < listTwo.length(); i++){ //counting Owners, Chefs and Waiters in "emplList"
        if (listTwo.getMember(i)->getEmpClass() == 'O')
            countOwner++;
        else if (listTwo.getMember(i)->getEmpClass() == 'C')
            countChef++;
        else
            countWaiter++;
    }

    income = calcIncome(income, countOwner, countChef, countWaiter);

    //calculating salary for all Employers for this month, except Waiters
    for(int i=0; i < listTwo.length(); i++){
        if(listTwo.getMember(i)->getEmpClass() != 'W')
            listTwo.getMember(i)->calcSalary(income);
    }


    cout<<"Owner: "<<countOwner<<"\t Chef: "<<countChef<<"\t Waiter: "<<countWaiter<<"\n";
    cout<<"Income: "<<income<<endl;

    cout<<listTwo;

    return 0;
}

int calcIncome(int income, int owner, int chef, int waiter)
{
    return income - (5000*owner + 3000*chef + 1000*waiter);
}