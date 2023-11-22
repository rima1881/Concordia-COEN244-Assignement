#include "Error.hpp"

int Error::getCode(){
    return this -> code;
}

std::string Error::getMSG(){
    return this -> msg;
}


BadAge::BadAge(){
    this -> msg = "Age should be between 0 - 120";
    code = 1;
}

BadHearedYear::BadHearedYear(){
    this -> msg = "Year Hired should be between 1950 - 2023";
    code = 2;
}

BadStatus::BadStatus(){
    this -> msg = "Status is undefined";
    code = 3;
}

BadStudentId::BadStudentId(){
    this -> msg = "Student Id should be 8 in lenght";
    code = 4;
}

BadWorkingHours::BadWorkingHours(){
    this -> msg = "working hours should be between 0 - 40";
    code = 5;   
}