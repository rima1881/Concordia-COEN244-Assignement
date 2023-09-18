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
    std::ifstream * reader;
    std::ostream * writer;
    

public:
    Driver(std::string fileName);

    std::vector<TA> readFile();
    bool updateFile(std::vector<TA> data);

    ~Driver();
};

#endif