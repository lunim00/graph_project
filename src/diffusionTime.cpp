#include <exception>
#include "diffusionTime.hpp"


DiffusionTime::DiffusionTime(const unsigned int& year, const unsigned int& month, 
                             const unsigned int& day, const unsigned int& hour, 
                             const unsigned int& minute, const unsigned int& second):
year(year), month(month), day(day), hour(hour), minute(minute), second(second)
{

}

bool DiffusionTime::operator<(const DiffusionTime& other) const
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
    if (other.second <= this->second && returningBool)
        returningBool = false;

    return returningBool;
}

bool DiffusionTime::operator==(const DiffusionTime& other) const
{
    bool returningBool = true;
    if (this->year != other.year)
        returningBool = false;
    if (this->month != other.month)
        returningBool = false;
    if (this->day != other.day)
        returningBool = false;
    if (this->hour != other.hour)
        returningBool = false;
    if (this->minute != other.minute)
        returningBool = false;
    if (this->second != other.second)
        returningBool = false;

    return returningBool;
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