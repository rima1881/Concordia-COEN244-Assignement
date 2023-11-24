#include <iostream>
#include <algorithm>
#include <functional>
#include "./Driver.hpp"
#include "./Error.hpp"
#include  "./TA.hpp"

bool menu();
void add();
int orderBy();
void sort();
void list();

int main(){

    using namespace std;

    std::cout << "*************************************" << std::endl;
    std::cout << "Loadding... " << std::endl;
    std::cout << "*************************************" << std::endl << std::endl;

    std::cout << "please enter the Address TAs Data file: ";
    std::string Address;
    std::cin >> Address;


    cout << "\nOpenning The file\n";

    //openning the file
    Driver driver(Address);


    cout << "reading the data\n";

    try{
        driver.readFile();
        if(TA::TAs.size() == 0)
            throw new BadFile();
    }
    catch (Error *err){
        std::cout << err -> what();
        while (true);
    }
    catch (...){
        std::cout << "there was an unknown error please restart the program!!!";
        while(true);
    }

    


    cout << "updating the data\n";
    //checking ta's status
    for(int i=0;i < TA::TAs.size();i++)
        if(!TA::TAs[i].checkStatus())
            //removing extra data
            TA::TAs.erase(TA::TAs.begin() + i);


    
    if(menu()){

        cout << "updating the files\n";
        if(!driver.updateFile()){
            cout << "there was an error!!! with the file while updating (press ctrl+c to stop program)";
            while (true);
        }
    }

    std::cout << std::endl << "goodbye :)";


    return 0;
}


void add(){
    std::cout << "please enter the TA info in the following order:\n";
    std::cout << "Age\tStudentId\tStatus\tYear_Hired\tWorking_Hours\n";
    int age,working_hours,Year_Heared;
    std::string status,StudentId;

    std::cin >> age >> StudentId >> status >> Year_Heared >> working_hours;


    TA ta(StudentId,age,Year_Heared,working_hours,status);
    
    try{
        ta.save();
    }
    catch(Error *err){
        std::cout << err->what() << std::endl;
    }



}


int orderBy(){

    int option = -1;
    system("cls"); 

    while (true)
    {
        std::cout << "please choose by what attribute do you wanna see the TAs:"<<std::endl;
        std::cout << "1)Student Id" << std::endl;
        std::cout << "2)Age" << std::endl;
        std::cout << "3)Status" << std::endl;
        std::cout << "4)Hired Year" << std::endl;
        std::cout << "5)Working Hours" << std::endl;

        std::cin >> option;

        if(option > 0 && option < 6)
            return option;

        std::cout << "Incorrect Number!!!" << std::endl << std::endl;
    }



}

void sort(){

    std::function<bool(TA t1,TA t2)> sortMethod;
    int ass, option = orderBy();

    std::cout << "Do you want it ascending or descending(1-ascending: 2-descending)";
    std::cin >> ass;

    bool isAss = (ass == 1);


    if(option == 1)
        sortMethod = [&isAss] (TA t1,TA t2) {
            return ( (t1.getStudentId() > t2.getStudentId()) == isAss);
        };
    else if(option == 2)
        sortMethod = [&isAss] (TA t1,TA t2) {
            return ( (t1.getAge() > t2.getAge()) == isAss);
        };
    else if(option == 3)
        sortMethod = [&isAss] (TA t1,TA t2) {
            return (t1.getStatus() < t2.getStatus() == isAss);
        };
    else if(option == 4)
        sortMethod = [&isAss] (TA t1,TA t2) {
            return (t1.getHiredYear() > t2.getHiredYear() == isAss);
        };
    else
        sortMethod = [&isAss] (TA t1,TA t2) {
            return (t1.getWorkingHours() > t2.getWorkingHours() == isAss);
        };
    

    std::sort(TA::TAs.begin(),TA::TAs.end(),sortMethod);

}


void list(){

    system("cls"); 

    std::cout << "Age\tStudentId\tStatus\tYear Hired\tWorking Hours" << std::endl;

    for (TA t : TA::TAs)
    {
        std::cout << t.getAge() << "\t" << t.getStudentId() << "\t"
        << t.getStatus() << "\t"
        << t.getHiredYear() << "\t\t"
        << t.getWorkingHours() << std::endl;
    }
    
}

bool menu(){

    system("cls"); 

    while (true){
        

        int option = -1;

        std::cout << "1)Add new TA" << std::endl;
        std::cout << "2)Sort TAs based on thier props" << std::endl;
        std::cout << "3)List the TAs" << std::endl;
        std::cout << "4)exit without saving" << std::endl;
        std::cout << "5)exit and saving changes to the file" << std::endl;
        std::cout << "please enter the operation number:";
        std::cin >> option;

        if(option == 4)
            return false;
        else if(option == 5)
            return true;
        else if(option == 1)
            add();
        else if(option == 2)
            sort();
        else if(option == 3)
            list();
        else
            std::cout << "\nIncorrect number!!!" << std::endl;


    }

    return 0;
}