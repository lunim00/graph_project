#include <exception>
#include "diffusionTime.hpp"


DiffusionTime::DiffusionTime(const unsigned int& year, const unsigned int& month, 
                             const unsigned int& day, const unsigned int& hour, const unsigned int& minute):
year(year), month(month), day(day), hour(hour), minute(minute)
{

}

bool DiffusionTime::operator<(const DiffusionTime& other) const
{
    bool returningBool = true;
    if (other.year <= this->day)
        returningBool = false;
    if (other.)
}

bool DiffusionTime::operator==(const DiffusionTime& other) const
{

}

bool DiffusionTime::operator<=(const DiffusionTime& other) const
{

}