#include <string>
#include <vector>
#include <sstream>
#include "./TA.hpp"

class Driver
{
private:
    /* data */

    std::string fileAddress;
    std::ifstream * db;
    

public:
    Driver(std::string fileName);

    std::vector<TA> readFile();
    bool updateFile(std::vector<TA> data);
    bool closeFile();

    ~Driver();
};
