#ifndef TACpp
#define TACpp
#include <String>


enum Status{
    UGrad,
    Alum,
    Grad,
    currupted
};

class TA
{
private:

    int id;
    std::string studentId;
    std::string firstName;
    std::string lastName;
    int hiredYear;
    int workingHours;
        //Used enum in order to avoid invalid data
    Status status;


    //statics
        //just for keeping the track of TAs
    int static LAST_ID;

public:

    //constructors
    TA();
    TA(std::string stdId,std::string fname,std::string lname,int hireYear,int workingHours,std::string status);

    //public methods
    bool checkStatus();


    //getters
    int getId();
    std::string getStudentId();
    std::string getFirstName();
    std::string getLastName();
    int getHiredYear();
    int getWorkingHours();
        //the return type is string in order to avoid to string problems
    std::string getStatus();


    //setters
    void setStudentId(std::string studentId);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setHiredYear(int hireYear);
    void setWorkingHours(int workingHours);
        //it is reading from txt => the initial data is going to be string
    bool setStatus(std::string status);    

};

#endif