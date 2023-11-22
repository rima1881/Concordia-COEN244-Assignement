#include "./TA.hpp"

//statics

int TA::LAST_ID = 0;


//Constructors
TA::TA(){

    this -> id = LAST_ID++;

}

TA::TA(std::string stdId,std::string fname,std::string lname,int hireYear,int workingHours,std::string status){

    this -> id = LAST_ID++;
    this -> studentId = stdId;
    this -> firstName = fname;
    this -> lastName = lname;
    this -> hiredYear = hiredYear;
    this -> workingHours = workingHours;
    

    if(status == "UGrad")
        this -> status = UGrad;

    else if (status == "Grad")
        this -> status = Grad;

    else if (status == "Alum")
        this -> status = Alum;

    else
        this -> status = currupted;
    
}


//methods
bool TA::checkStatus(){

    return this -> status == UGrad || this -> status == Grad;

}


//getters
int TA::getId(){
    return this -> id;
}

std::string TA::getStudentId(){
    return this -> studentId;
}

std::string TA::getFirstName(){
    return this -> firstName;
}

std::string TA::getLastName(){
    return this -> lastName;
}

int TA::getHiredYear(){
    return this -> hiredYear;
}

int TA::getWorkingHours(){
    return this -> workingHours;
}

std::string TA::getStatus(){

    if(status == UGrad)
        return  "UGrad";

    else if (status == Grad)
        return "Grad";
    
    else if (status == Alum)
        return "Alum";
    

    return "currupted";

}

//setters
void TA::setStudentId(std::string studentId) {
    this -> studentId = studentId;
}
void TA::setFirstName(std::string firstName) {
    this -> firstName = firstName;
}
void TA::setLastName(std::string lastName) {
    this -> lastName = lastName;
}
void TA::setHiredYear(int hireYear) {
    this -> hiredYear = hiredYear;
}
void TA::setWorkingHours(int workingHours) {
    this -> workingHours = workingHours;
}
bool TA::setStatus(std::string status) {


    if(status == "UGrad"){
        this -> status = UGrad;
        return true;
    } 
    else if (status == "Grad")
    {
        this -> status = Grad;
        return true;
    }
    else if (status == "Alum")
    {
        this -> status = Alum;
        return true;
    }



    return false;


}