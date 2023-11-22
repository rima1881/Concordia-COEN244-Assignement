#include "./TA.hpp"
#include <iostream>

//statics
int TA::LAST_ID = 0;
std::vector<TA> TA::TAs;

void TA::addTA(){

    std::cout << "please enter the TA info in the below order";

}


//Constructors
TA::TA(){

    this -> id = LAST_ID++;

}

TA::TA(std::string stdId,int age,int hireYear,int workingHours,std::string status){

    this -> id = LAST_ID++;
    this -> studentId = stdId;
    this -> age = age;
    this -> hiredYear = hiredYear;
    this -> workingHours = workingHours;
    

    if(status == "UGrad")
        this -> status = Status::UGrad;

    else if (status == "Grad")
        this -> status = Status::Grad;

    else if (status == "Alum")
        this -> status = Status::Alum;

    else
        this -> status = Status::currupted;
    
}


//methods
bool TA::checkStatus(){

    return this -> status == Status::UGrad || this -> status ==  Status::Grad;

}


//getters
int TA::getId(){
    return this -> id;
}

std::string TA::getStudentId(){
    return this -> studentId;
}
int TA::getAge(){
    return age;
}

int TA::getHiredYear(){
    return this -> hiredYear;
}

int TA::getWorkingHours(){
    return this -> workingHours;
}

std::string TA::getStatus(){

    if(status == Status::UGrad)
        return  "UGrad";

    else if (status == Status::Grad)
        return "Grad";
    
    else if (status == Status::Alum)
        return "Alum";
    

    return "currupted";

}

//setters
void TA::setStudentId(std::string studentId) {
    this -> studentId = studentId;
}
void TA::setAge(int age){
    this -> age = age;
}
void TA::setHiredYear(int hireYear) {
    this -> hiredYear = hiredYear;
}
void TA::setWorkingHours(int workingHours) {
    this -> workingHours = workingHours;
}
bool TA::setStatus(std::string status) {


    if(status == "UGrad"){
        this -> status = Status::UGrad;
        return true;
    } 
    else if (status == "Grad")
    {
        this -> status = Status::Grad;
        return true;
    }
    else if (status == "Alum")
    {
        this -> status = Status::Alum;
        return true;
    }



    return false;


}