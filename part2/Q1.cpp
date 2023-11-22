#include <iostream>
#include "./Driver.hpp"
#include "./Error.hpp"
#include  "./TA.hpp"

int menu();
void add();

int main(){

    using namespace std;

    cout << "\nOpenning The file\n";

    //openning the file
    Driver driver("./db.txt");


    cout << "reading the data\n";
    driver.readFile();
    //if data size is 0 there was a problem with txt or there was nothing in txt
    //eithere way running the rest of program is useless
    if(TA::TAs.size() == 0){
        cout << "\ncan not read data!!! (press ctrl+c to stop program)";
        while (true);
        
    }

    


    cout << "updating the data\n";
    //checking ta's status
    for(int i=0;i < TA::TAs.size();i++)
        if(!TA::TAs[i].checkStatus())
            //removing extra data
            TA::TAs.erase(TA::TAs.begin() + i);


    
    menu();

    cout << "updating the files\n";
    if(!driver.updateFile()){
        cout << "there was an error!!! with the file while updating (press ctrl+c to stop program)";
        while (true);
    }


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
    catch(Error err){
        std::cout << err.getMSG();
    }



}


int menu(){

    while (true){
    

        int option = -1;

        while (true)
        {
            std::cout << "1)Add new TA" << std::endl;
            std::cout << "2)Sort TAs based on thier props" << std::endl;
            std::cout << "3)exit" << std::endl;
            std::cout << "please enter the operation number:";

            std::cin >> option;

            if(option > 0 && option < 4)
                break;

            std::cout << "\nIncorrect number!!!";
        }


        switch (option){
        case 1:
        
        case 2:

        case 3:
        default:
            return 0;
        }
    
    }
}