#ifndef DriverCpp
#define DriverCpp
#include <string>
#include <vector>
#include <fstream>
#include "./TA.hpp"

class Driver
{
private:
    /* data */

    std::string fileAddress;
        //The file is not gonna open on initialization
    std::ifstream * reader;
    std::ostream * writer;
    std::vector<TA> data;
    

public:
    Driver(std::string fileName);

    std::vector<TA> getData();

    void readFile();
    //the bool is used for error tracking
    bool updateFile();

    ~Driver();
};

#endif