#include <charconv>
#include <stdexcept>
#include "utility.hpp"

void utility::stringViewToUnsignedInt(const char* start, const char* end, unsigned int& value)
{
        auto res = std::from_chars(start, end, value);
        if (res.ec == std::errc::invalid_argument)
            throw std::logic_error("Logic error | Coult not convert to unsigned int.");
}