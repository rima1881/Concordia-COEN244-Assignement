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
    

public:
    Driver(std::string fileName);

    std::vector<TA> readFile();
    //the bool is used for error tracking
    bool updateFile(std::vector<TA> data);

    ~Driver();
};

#endif