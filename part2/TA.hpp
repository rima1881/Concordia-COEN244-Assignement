#ifndef TACpp
#define TACpp
#include <String>
#include <vector>


enum class Status{
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
    int age;
    int hiredYear;
    int workingHours;
        //Used enum in order to avoid invalid data
    Status status;


    //statics
        //just for keeping the track of TAs
    int static LAST_ID;

public:

    static std::vector<TA> TAs;
    static void addTA(TA t);
    //constructors
    TA(std::string stdId,int age,int hireYear,int workingHours,std::string status);

    //public methods
    bool checkStatus();


    //getters
    int getId();
    int getAge();
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
    void setAge(int);
    void setWorkingHours(int workingHours);
        //it is reading from txt => the initial data is going to be string
    bool setStatus(std::string status);    

};

#endif