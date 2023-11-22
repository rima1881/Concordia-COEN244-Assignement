#include "./Driver.hpp"
#include <iostream>

Driver::Driver(std::string fileName){


    this -> fileAddress = fileName;

}

void Driver::readFile(){

    reader = new std::ifstream(fileAddress);


    std::string line;
    int numline;

    //getting the first line(number of data)
    std::getline(*reader,line);
    numline = stoi(line);

    std::string studentId;
    int age;
    int hiredYear;
    int workingHours;
    std::string status;

    try{

        //geting the data
        for(int i=0;i<numline;i++){
            *reader >> age >> studentId >> status >> hiredYear >> workingHours;

            //there was no last name in the given sample so I just entered empty string for it
            TA ta(studentId,age,hiredYear,workingHours,status);
            TA::TAs.push_back(ta);
        }
    }
    catch(...){
        std::cout << "\n\n\nthere was an error while extracting data!!!";
    }

    reader -> close();


}

bool Driver::updateFile(){

    try
    {

        writer = new std::ofstream(fileAddress);

        int numLine = TA::TAs.size();

        //writting the first line which is the size of data (TA)
        *writer << numLine << "\n";


        //inserting the data in txt
        for(int i=0;i < numLine; i++)
            *writer << TA::TAs[i].getAge() << " "
            << TA::TAs[i].getStudentId() << " "
            << TA::TAs[i].getStatus() << " "
            << TA::TAs[i].getHiredYear() << " "
            << TA::TAs[i].getWorkingHours() << "\n";

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