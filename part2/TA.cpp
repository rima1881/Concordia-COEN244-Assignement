#include "./TA.hpp"
#include "./Error.hpp"
#include <iostream>

//statics
int TA::LAST_ID = 0;
std::vector<TA> TA::TAs;

void TA::save(){

    if(this -> age > 150 || this -> age < 0)
        throw new BadAge();
    
    if(this -> studentId.length() != 8)
        throw new BadStudentId();

    if(this -> hiredYear < 1950 || this -> hiredYear > 2023)
        throw new BadHearedYear();

    if(this -> workingHours > 40 || this -> workingHours < 0)
        throw new BadWorkingHours();

    if(this -> status != Status::Grad && this -> status != Status::UGrad)
        throw new BadStatus();

    TAs.push_back(*this);
}


//Constructors
TA::TA(){
    this -> id = LAST_ID++;
}

TA::TA(std::string stdId,int age,int hy,int workingHours,std::string status){


    this -> id = LAST_ID++;
    this -> studentId = stdId;
    this -> age = age;
    this -> hiredYear = hy;
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