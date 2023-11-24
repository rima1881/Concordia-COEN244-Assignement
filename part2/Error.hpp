#include <string>

class Error
{
protected:
    std::string msg;
    int code;
public:
    std::string what();
    int getCode();
};



class BadStudentId : public Error
{
public:
    BadStudentId(/* args */);
};


class BadWorkingHours : public Error
{
public:
    BadWorkingHours();
};


class BadHearedYear : public Error
{
public:
    BadHearedYear(/* args */);
};

class BadStatus : public Error
{
public:
    BadStatus(/* args */);
};


class BadAge : public Error
{
public:
    BadAge(/* args */);
};