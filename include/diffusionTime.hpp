#ifndef TIMEINTERVAL_HPP
#define TIMEINTERVAL_HPP
#include <string>

class DiffusionTime
{
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

public:
    DiffusionTime() = delete;
    DiffusionTime(const unsigned int& year, const unsigned int& month, 
                  const unsigned int& day, const unsigned int& hour, 
                  const unsigned int& minute, const unsigned int& second);

    bool operator<(const DiffusionTime& other) const;
    bool operator==(const DiffusionTime& other) const;
    bool operator<=(const DiffusionTime& other) const;
};

#endif