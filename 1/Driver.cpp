#include "./Driver.hpp"
#include <iostream>

Driver::Driver(std::string fileName){


    this -> fileAddress = fileName;

}

std::vector<TA> Driver::readFile(){

    reader = new std::ifstream(fileAddress);


    std::string line;
    int numline;

    std::getline(*(this -> reader),line);
    numline = stoi(line);

    std::vector<TA> data;

    std::string studentId;
    std::string fname;
    std::string lastName;
    int hiredYear;
    int workingHours;
    std::string status;

    try{

        for(int i=0;i<numline;i++){
            *reader >> workingHours >> studentId >> hiredYear >> status >> fname;

            //there was no last name in the given sample so I just entered empty string for it
            TA ta(studentId,fname,"",hiredYear,workingHours,status);
            data.push_back(ta);
        }
    }
    catch(...){
        std::cout << "\n\n\nthere was an error while extracting data!!!";
    }

    reader -> close();

    return data;

}

bool Driver::updateFile(std::vector<TA> data){



    try
    {

        writer = new std::ofstream(fileAddress);

        int numLine = data.size();

        *writer << numLine << "\n";

        for(int i=0;i < numLine; i++)
            *writer << data[i].getWorkingHours() << " "
            << data[i].getStudentId() << " "
            << data[i].getHiredYear() << " "
            << data[i].getStatus() << " "
            << data[i].getFirstName() << " "
            << data[i].getLastName() << "\n";



    }
    catch(const std::exception& e)
    {
        return false;
    }
    

    return true;
}



Driver::~Driver(){
    delete this -> reader;
    delete this -> writer;
}