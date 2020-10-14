#include <exception>
#include "diffusionTime.hpp"

DiffusionTime::DiffusionTime():
year(0), month(0), day(0), hour(0), minute(0), second(0)
{
}

DiffusionTime::DiffusionTime(const unsigned int& year, const unsigned int& month, 
                             const unsigned int& day, const unsigned int& hour, 
                             const unsigned int& minute, const unsigned int& second):
year(year), month(month), day(day), hour(hour), minute(minute), second(second)
{

}

bool DiffusionTime::operator<(const DiffusionTime& other) const
{
    if (this->year < other.year)
        return true;
    else if (other.year < this->year)
        return false;
    if (this->month < other.month)
        return true;
    else if (other.month < this->month)
        return false;
    if (this->day < other.day)
        return true;
    else if (other.day < this->day)
        return false;
    if (this->hour < other.hour)
        return true;
    else if (other.hour < this->hour)
        return false;
    if (this->minute < other.minute)
        return true;
    else if (other.minute < this->minute)
        return false;
    if (this->second < other.second)
        return true;
    else if (other.second < this->second)
        return false;
    return false;
}

bool DiffusionTime::operator==(const DiffusionTime& other) const
{
    if (this->year != other.year)
        return false;
    if (this->month != other.month)
        return false;
    if (this->day != other.day)
        return false;
    if (this->hour != other.hour)
        return false;
    if (this->minute != other.minute)
        return false;
    if (this->second != other.second)
        return false;

    return true;
}

bool DiffusionTime::operator<=(const DiffusionTime& other) const
{
    bool returningBool = true;
    if (other.year < this->year)
        returningBool = false;
    if (other.month < this->month && returningBool)
        returningBool = false;
    if (other.day < this->day && returningBool)
        returningBool = false;
    if (other.hour < this->hour && returningBool)
        returningBool = false;
    if (other.minute < this->minute && returningBool)
        returningBool = false;
    if (other.second < this->second && returningBool)
        returningBool = false;

    return returningBool;
}

std::string DiffusionTime::toString() const
{
    std::string returningStr = std::to_string(this->year) + "-" + std::to_string(this->month) + 
                               "-" + std::to_string(this->day) + " " + std::to_string(this->hour) + 
                               ":" + std::to_string(this->minute) + ":" + std::to_string(this->second);
    return returningStr;
}